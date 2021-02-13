#define RED_PIN   5
#define GREEN_PIN 16
#define BLUE_PIN  4

void setup()
{
  // Configure PWM
  ledcSetup(0, 1000, 8); // Channel: 0, Freq: 1kHz, Resolution: 8-bit
  ledcSetup(1, 1000, 8); // Channel: 1, Freq: 1kHz, Resolution: 8-bit  
  ledcSetup(2, 1000, 8); // Channel: 2, Freq: 1kHz, Resolution: 8-bit
  
  // Attach the PWM channel to the LED
  ledcAttachPin(RED_PIN, 0);
  ledcAttachPin(GREEN_PIN, 1);
  ledcAttachPin(BLUE_PIN, 2);  
}

void loop()
{
  // Red
  rgb_led_write(255, 0, 0);
  delay(1000);
  // Orange
  rgb_led_write(255, 50, 0);
  delay(1000);
  // Yellow
  rgb_led_write(255, 150, 0);
  delay(1000);
  // Green
  rgb_led_write(0, 255, 0);
  delay(1000);
  // Light Blue
  rgb_led_write(0, 150, 255);
  delay(1000);
  // Blue
  rgb_led_write(0, 0, 255);
  delay(1000);
  // Purple
  rgb_led_write(150, 0, 255);
  delay(1000);
  // White
  rgb_led_write(255, 255, 255);
  delay(1000);
}

void rgb_led_write(byte red, byte green, byte blue)
{
  ledcWrite(0, 255-red);
  ledcWrite(1, 255-green);
  ledcWrite(2, 255-blue);
}
