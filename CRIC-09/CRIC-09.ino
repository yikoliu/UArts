// CIRC09 - Light
int lightPin = A0;
int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT); 
  Serial. begin(9600);
  Serial. println("Serial Monitor Started");
}

void loop()
{
  int lightLevel = analogRead(lightPin); 
  Serial.print("photo sensor level ：");
  Serial.print(lightLevel);
  lightLevel = map(lightLevel, 0, 900, 0, 255);
  Serial.print(": LED mapped level : ");
  Serial.println(lightLevel);
  analogWrite(ledPin, lightLevel);
}
