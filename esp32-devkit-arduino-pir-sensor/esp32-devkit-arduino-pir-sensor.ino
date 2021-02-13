#define LED_PIN  2
#define PIR_PIN  23

int current_state = LOW;
int last_state = LOW;
 
void setup()
{
  Serial.begin(115200);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}
 
void loop()
{
  // Read PIR state
  current_state = digitalRead(PIR_PIN);
  
  if (current_state == HIGH)
  {
    // Turn on LED
    digitalWrite(LED_PIN, HIGH);
    if (last_state == LOW)
    {
      // We have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      last_state = HIGH;
    }
  }
  else
  {
    // Turn off LED
    digitalWrite(LED_PIN, LOW);
    if (last_state == HIGH)
    {
      // We have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      last_state = LOW;
    }
  }
}
