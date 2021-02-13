#define RED_PIN   5
#define GREEN_PIN 16
#define BLUE_PIN  4

byte red, green, blue;

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
  // 1000 K
  temp_to_rgb(1000, &red, &green, &blue);
  rgb_led_write(red, green, blue);
  delay(1000);
  // 1500 K
  temp_to_rgb(1500, &red, &green, &blue);
  rgb_led_write(red, green, blue);
  delay(1000);
  // 2000 K
  temp_to_rgb(2000, &red, &green, &blue);
  rgb_led_write(red, green, blue);
  delay(1000);
  // 3000 K
  temp_to_rgb(3000, &red, &green, &blue);
  rgb_led_write(red, green, blue);
  delay(1000);
  // 4000 K
  temp_to_rgb(4000, &red, &green, &blue);
  rgb_led_write(red, green, blue);
  delay(1000);
}

void rgb_led_write(byte red, byte green, byte blue)
{
  ledcWrite(0, 255-red);
  ledcWrite(1, 255-green);
  ledcWrite(2, 255-blue);
}

void temp_to_rgb(int temp, byte *red, byte *green, byte *blue)
{
  float t, r, g, b;

  t = temp;
  t = (t < 1000) ? 1000 : t;
  t = (t > 40000) ? 40000 : t;
  t = t / 100;

  // Calculate red value
  if (t <= 66)
  {
    r = 255;
  }
  else
  {
    r = t - 60;
    r = 329.698727446 * pow(r, -0.1332047592);
    r = (r < 0) ? 0 : r;
    r = (r > 255) ? 255 : r;
  }

  // Calculate green value
  if (t <= 66)
  {
    g = t;
    g = 99.4708025861 * log(g) - 161.1195681661;
    g = (g < 0) ? 0 : g;
    g = (g > 255) ? 255 : g;
  }
  else
  {
    g = t - 60;
    g = 288.1221695283 * pow(g, -0.0755148492);
    g = (g < 0) ? 0 : g;
    g = (g > 255) ? 255 : g;
  }

  // Calculate blue value
  if (t >= 66)
  {
    b = 255;
  }
  else
  {
    if (t <= 19)
    {
      b = 0;
    }
    else
    {
      b = t - 10;
      b = 138.5177312231 * log(b) - 305.0447927307;
      b = (b < 0) ? 0 : b;
      b = (b > 255) ? 255 : b;
    }
  }
  
  *red = (byte) r;
  *green = (byte) g;
  *blue = (byte) b;
}
