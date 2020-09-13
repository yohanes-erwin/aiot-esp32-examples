// Author: Erwin Ouyang, aiotedge.tech
// Date  : 12 Sep 2020

#include <Wire.h>
#include <BH1750.h>

// I2C pins
#define I2C_SDA 33
#define I2C_SCL 32

// BH1750 object declaration
BH1750 light_sensor;

void setup()
{
  // Initialize serial port
  Serial.begin(115200);
  
  // Initialize I2C pins
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  
  // Initialize BH1750
  light_sensor.begin();
}

void loop()
{
  // Read light intensity
  float lux = light_sensor.readLightLevel();
  
  // Print light intensity 
  Serial.print("Light intensity: ");
  Serial.print(lux);
  Serial.println(" lx");
  
  delay(1000);
}
