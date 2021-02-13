#define LED_PIN   2
#define PIEZO_PIN 14

int threshold = 500;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // Read piezo value
  int piezo = analogRead(PIEZO_PIN);
  // Print piezo value
  Serial.printf("Piezo: %d\n", piezo);
  
  // Turn on the led if the piezo value exceeds the threshold
  if (piezo >= threshold)
  {
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
}
