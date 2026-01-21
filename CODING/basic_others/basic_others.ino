#include <ESP8266WiFi.h>

// Replace these variables with your Wi-Fi credentials
const char* ssid = "NIHAR";
const char* password = "12345678";

// Replace this variable with the IP address or domain of your server
const char* server = "youtube.com";

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print ESP8266 IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Send a message to the server
  sendToServer("Hello from ESP8266!");

  // Wait for 5 seconds before sending the next message
  delay(5000);
}

void sendToServer(String message) {
  // Use the WiFiClient class to create a TCP connection
  WiFiClient client;

  if (client.connect(server, 80)) {  // Replace 80 with the port number of your server
    Serial.println("Connected to server");

    // Make an HTTP request
    client.print("GET /send?message=" + message + " HTTP/1.1\r\n" +
                 "Host: " + server + "\r\n" +
                 "Connection: close\r\n\r\n");
    delay(10);

    // Read and print the response
    while (client.available()) {
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }

    Serial.println();
    Serial.println("Message sent to server");
    client.stop();
  } else {
    Serial.println("Failed to connect to server");
  }
}

// #include "bsec.h"

// // Helper functions declarations
// void checkIaqSensorStatus(void);
// void errLeds(void);

// // Create an object of the class Bsec
// Bsec iaqSensor;

// String output;

// // Entry point for the example
// void setup(void)
// {
//   Serial.begin(115200);
//   Wire.begin(0,2);

//   iaqSensor.begin(BME680_I2C_ADDR_PRIMARY, Wire);
//   output = "\nBSEC library version " + String(iaqSensor.version.major) + "." + String(iaqSensor.version.minor) + "." + String(iaqSensor.version.major_bugfix) + "." + String(iaqSensor.version.minor_bugfix);
//   Serial.println(output);
//   checkIaqSensorStatus();

//   bsec_virtual_sensor_t sensorList[10] = {
//     BSEC_OUTPUT_RAW_TEMPERATURE,
//     BSEC_OUTPUT_RAW_PRESSURE,
//     BSEC_OUTPUT_RAW_HUMIDITY,
//     BSEC_OUTPUT_RAW_GAS,
//     BSEC_OUTPUT_IAQ,
//     BSEC_OUTPUT_STATIC_IAQ,
//     BSEC_OUTPUT_CO2_EQUIVALENT,
//     BSEC_OUTPUT_BREATH_VOC_EQUIVALENT,
//     BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
//     BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
//   };

//   iaqSensor.updateSubscription(sensorList, 10, BSEC_SAMPLE_RATE_LP);
//   checkIaqSensorStatus();

//   // Print the header
//   output = "Timestamp [ms], raw temperature [°C], pressure [hPa], raw relative humidity [%], gas [Ohm], IAQ, IAQ accuracy, temperature [°C], relative humidity [%], Static IAQ, CO2 equivalent, breath VOC equivalent";
//   Serial.println(output);
// }

// // Function that is looped forever
// void loop(void)
// {
//   unsigned long time_trigger = millis();
//   if (iaqSensor.run()) { // If new data is available
//     output = String(time_trigger);
//     output += ", " + String(iaqSensor.rawTemperature);
//     output += ", " + String(iaqSensor.pressure);
//     output += ", " + String(iaqSensor.rawHumidity);
//     output += ", " + String(iaqSensor.gasResistance);
//     output += ", " + String(iaqSensor.iaq);
//     output += ", " + String(iaqSensor.iaqAccuracy);
//     output += ", " + String(iaqSensor.temperature);
//     output += ", " + String(iaqSensor.humidity);
//     output += ", " + String(iaqSensor.staticIaq);
//     output += ", " + String(iaqSensor.co2Equivalent);
//     output += ", " + String(iaqSensor.breathVocEquivalent);
//     Serial.println(output);
//   } else {
//     checkIaqSensorStatus();
//   }
// }

// // Helper function definitions
// void checkIaqSensorStatus(void)
// {
//   if (iaqSensor.status != BSEC_OK) {
//     if (iaqSensor.status < BSEC_OK) {
//       output = "BSEC error code : " + String(iaqSensor.status);
//       Serial.println(output);
//       for (;;)
//         errLeds(); /* Halt in case of failure */
//     } else {
//       output = "BSEC warning code : " + String(iaqSensor.status);
//       Serial.println(output);
//     }
//   }

//   if (iaqSensor.bme680Status != BME680_OK) {
//     if (iaqSensor.bme680Status < BME680_OK) {
//       output = "BME680 error code : " + String(iaqSensor.bme680Status);
//       Serial.println(output);
//       for (;;)
//         errLeds(); /* Halt in case of failure */
//     } else {
//       output = "BME680 warning code : " + String(iaqSensor.bme680Status);
//       Serial.println(output);
//     }
//   }
// }

// void errLeds(void)
// {
//   pinMode(LED_BUILTIN, OUTPUT);
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(100);
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(100);
// }
