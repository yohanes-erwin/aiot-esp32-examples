#define LED_PIN   2
#define HALL_PIN  23

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(HALL_PIN, INPUT);
}

void loop()
{
  if (digitalRead(HALL_PIN) == LOW)
  {
    // If magnet is detected, then turn on LED   
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    // If magnet is not detected, then turn off LED   
    digitalWrite(LED_PIN, LOW);
  }
}
