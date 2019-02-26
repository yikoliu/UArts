/* Photo Light Sensor */
int lightPin = A0;
int ledPin = 13;
int lastLevel = 0;
int potPin = A1;
int potValue = 0;

void setup() {
  // set the led pin to output
  pinMode(ledPin, OUTPUT);
  // turn on the serial monitor
  Serial.begin(9600);
  Serial.println("Serial enabled");
}

void loop() {
  // read in the light level
  int lightLevel = analogRead(lightPin);

  // map the lightlevel to 0<=lightlevel<=255
  lightLevel = map(lightLevel, 0, 900, 0, 255);
  if (lightLevel != lastLevel) {
    lastLevel = lightLevel; 
    Serial.print("lightLevel mapped value: ");
    Serial.println(lightLevel);   
  }

  // turn on the LED, write the light level to the LED
  analogWrite(ledPin, lightLevel); 

  // read the value from the sensor: 0 - 1023
  potValue = analogRead(potPin);

  //  WAIT : leave the LED on at this level for this amount of milliseconds
  delay(potValue);
  
  // only blink if the potentiometer is set below 1000
  if (potValue < 1000) {

    // turn off the LED, write the 0 to the LED
    analogWrite(ledPin, 0);

    // WAIT : leave the LED off for this amount of milliseconds
    delay(potValue);

  }

}
