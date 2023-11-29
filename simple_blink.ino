//Pin 14 for this module and pin 13 for arduino uno
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
