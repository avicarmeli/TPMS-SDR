

#if !defined(ESP32) && defined(USE_BLE)
   #error For now BLE is supported only with ESP32
#endif

#if defined(ESP32) && defined(USE_BLE)
  #include <BLEDevice.h>
  #include <BLEUtils.h>
  #include <BLEServer.h>

   // 128-bit Service UUID
  static BLEUUID serviceUUID("0000fbb0-0000-1000-8000-00805f9b34fb"); // Service UUID of Sysgration BLE sensors

  // Manufacturer Data
  // Base TPMS data for 4 sensors
  uint8_t tpmsData[4][18] = {
    {0x00, 0x01, 0x80, 0xEA, 0xCA, 0x10, 0x8A, 0x78, 0xE3, 0x6D, 0x00, 0x00, 0xE6, 0x0A, 0x00, 0x00, 0x5B, 0x00}, // Sensor 1
    {0x00, 0x01, 0x81, 0xEA, 0xCA, 0x20, 0x8A, 0x79, 0xD2, 0x4B, 0x00, 0x00, 0xE6, 0x0A, 0x00, 0x00, 0x4A, 0x00}, // Sensor 2
    {0x00, 0x01, 0x82, 0xEA, 0xCA, 0x30, 0x8A, 0x7A, 0xC1, 0x2A, 0x00, 0x00, 0xE6, 0x0A, 0x00, 0x00, 0x39, 0x00}, // Sensor 3
    {0x00, 0x01, 0x83, 0xEA, 0xCA, 0x40, 0x8A, 0x7B, 0xB0, 0x09, 0x00, 0x00, 0xE6, 0x0A, 0x00, 0x00, 0x28, 0x00}  // Sensor 4
  };

  // Function to convert PSI to kPa
  float psi_to_kpa(float psi) {
      return psi * 6.89476f; // 1 PSI = 6.89476 kPa
  }

  // Function to convert integer to 4-byte little-endian representation
  void int_to_little_endian(uint32_t value, uint8_t *output) {
      output[0] = (uint8_t)(value & 0xFF);
      output[1] = (uint8_t)((value >> 8) & 0xFF);
      output[2] = (uint8_t)((value >> 16) & 0xFF);
      output[3] = (uint8_t)((value >> 24) & 0xFF);
  }

  // Function to store TPMS sensor data into tpmsData array
  void update_tpmsData(int16_t index, float Temperature, double Pressure){
    if (index > TYRECOUNT)
    return;
    float kpa = psi_to_kpa(Pressure);
    uint32_t kpa_int = (uint32_t)kpa *1000; // Truncate to integer
    uint32_t temp_int = (uint32_t)Temperature*100; // Truncate to integer
    uint8_t press_little_endian_bytes[4];
    uint8_t temp_little_endian_bytes[4];
    int_to_little_endian(kpa_int, press_little_endian_bytes);
    int_to_little_endian(temp_int, temp_little_endian_bytes);
    for (int i = 0; i < 4; i++) {
       tpmsData[index][8+i]=press_little_endian_bytes[i];
       tpmsData[index][12+i]=temp_little_endian_bytes[i];
    }
  }




 

  // function to advertize TPMS sensor data over BLE
  void ble_advertise_tpms(int16_t index, float Temperature, double Pressure) {
    if (index > TYRECOUNT)
    return;
    
    update_tpmsData(index, Temperature, Pressure);
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising(); //check
    
    pAdvertising->stop();
    BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
    String manufacturerData((char*)tpmsData[index], sizeof(tpmsData[index]));
    oAdvertisementData.setManufacturerData(manufacturerData);
    pAdvertising->setAdvertisementData(oAdvertisementData);
    pAdvertising->setAdvertisementType(ADV_TYPE_SCAN_IND);
    oAdvertisementData.setFlags(ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT);
    oAdvertisementData.setName("ESP32_TPMS");

    BLEAdvertisementData scanResponseData;
    scanResponseData.setCompleteServices(serviceUUID);
    pAdvertising->setScanResponseData(scanResponseData);

    // Configure advertising
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    
    // Start advertising
    pAdvertising->start();
    Serial.println("Advertising started!");
    Serial.print("Advertising started! Sending Sensor no.");
    Serial.println(index);
    
  }

 // Function to initialize the BLE advertiser server
  void init_ble() {
    // Initialize the BLE device
    BLEDevice::init("ESP32");

    // Create BLE Server
    BLEServer *pServer = BLEDevice::createServer();

    // Create the BLE Service
    BLEService *pService = pServer->createService(serviceUUID);

    // Start the service
    pService->start();

    // Start advertising
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    
    //ble_advertise_tpms(0, 27.3f , 35.0f);
 
  }



#endif