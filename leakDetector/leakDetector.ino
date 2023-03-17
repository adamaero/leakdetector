/* https://circuitdigest.com/microcontroller-projects/interfacing-rain-sensor-with-arduino


https://upload.wikimedia.org/wikipedia/commons/thumb/0/08/ESP8266_01_PinOut.png/662px-ESP8266_01_PinOut.png
__ESP-01 pins__
0 - SPI
1 - LED (blue) and TX
2 - 2
3 - RX
6 - TOUT (analogIn) //i.imgur.com/yIE7II0.png

__  Circuit  __
Rain sensor       https://www.amazon.com/dp/B01DK29K28       https://www.aliexpress.us/item/3256802038114485.html

Voltage divider:
6200 Ω
2700 Ω
3v3 to 1 V (E24 5%)

ESP-01            https://www.amazon.com/dp/B010N1ROQS

Voltage regulator 3v3

Power supply or battery

 */


#define ledPin 1
#define sensorPin 2
#define analogIn 6  // only 0 to 1 V
//forum.arduino.cc/t/is-it-possible-to-have-analog-input-on-esp-01/630310

void setup()
{

  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, OUTPUT);
  pinMode(analogIn, INPUT);          
  
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

