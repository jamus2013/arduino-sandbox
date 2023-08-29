#include <DHT.h>

#define DHTPIN 2      // Connect DHT sensor output pin here
#define DHTTYPE DHT22 // DHT 22 (AM2303) Sensor type

DHT dht(DHTPIN, DHTTYPE);
float humidity      = 0.0;  // Relative humidity [%]     
float temperature   = 0.0;  // Temperature [°C]
int sample_period   = 1;    // Sensor sample period [s]

// Boot up
void setup() {
  Serial.begin(9600);
  dht.begin();
}

// MAIN
void loop() {
  readSensor(true);
  delay(sample_period * 1000);  // Poll sensor at 
}

// Read DHT22 Sensor
void readSensor(bool display_enabled) {
  humidity    = dht.readHumidity();
  temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)){
    Serial.println("Error reading sensor data");
  } else {
    if (display_enabled) {}
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\t");

      Serial.print("Rel. Humidity: ");
      Serial.print(humidity);
      Serial.println(" %");
  }
}
