#include "Wire.h"
#include "MPU6050.h"

// I2C pins
#define I2C_SDA 33
#define I2C_SCL 32

#define OUTPUT_READABLE_ACCELGYRO

MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup()
{
  Serial.begin(115200);

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL, 400000);
  // Initialize MPU6050
  accelgyro.initialize();
  // Verify connection
  if (accelgyro.testConnection())
    Serial.println("MPU6050 connection successful");
  else
    Serial.println("MPU6050 connection failed");
}

void loop()
{
  // Read raw accel/gyro measurements
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print raw accel/gyro measurements
  Serial.printf("Accel (x,y,z), gyro (x,y,z): %6d,%6d,%6d,\t%6d,%6d,%6d\n",
      ax, ay, az, gx, gy, gz);

  delay(500);
}
