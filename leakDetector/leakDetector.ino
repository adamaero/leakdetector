/* https://circuitdigest.com/microcontroller-projects/interfacing-rain-sensor-with-arduino


https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/ESP8266_01_PinOut.png/662px-ESP8266_01_PinOut.png
ESP-01 pins
0 - SPI
1 - LED (blue) and TX
2 - 2
3 - RX



 */


#define ledPin 1
#define sensorPin 2

void setup()
{

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, OUTPUT);

  digitalWrite(ledPin, LOW);

}

void loop()
{

  Serial.println(readSensor());

  delay(500);

}

int readSensor()
{

  int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor

  int outputValue = map(sensorValue, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data

  analogWrite(ledPin, outputValue); // generate PWM signal

  return outputValue;             // Return analog rain value

}

