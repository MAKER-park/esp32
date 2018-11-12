// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(34);
  int sensorValue2 = analogRead(35);
  int sensorValue3 = analogRead(39);

  Serial.print("A : ");
  Serial.println(sensorValue1);
  Serial.print("B : ");
  Serial.println(sensorValue2);
  Serial.print("C : ");
  Serial.println(sensorValue3);
  delay(500);

  
}
