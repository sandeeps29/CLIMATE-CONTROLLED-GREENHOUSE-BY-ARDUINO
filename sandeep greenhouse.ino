#include<LiquidCrystal.h>
#include "DHT.h" #define dht_dpin 13
#define dhtTYPE DHT11 // dht 11
#define LUX A0
LiquidCrystal lcd(2,3,4,5,6,7);
13
DHT dht(dht_dpin, dhtTYPE);
#define light 10
#define fan 8
#define spray 11
#define motor 12
#define soil 9
float temperature, humidity, temp,Temp;
int check;
int test,test1,test2,test3;
float volt,lux,value;
byte degree[8] =
{
0b00011, 0b00011, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000
};
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
dht.begin();
pinMode(soil, INPUT);
pinMode(light, OUTPUT);
pinMode(fan, OUTPUT);
pinMode(spray, OUTPUT);
14
pinMode(motor, OUTPUT);
lcd.createChar(1, degree);
lcd.setCursor(0,0);
lcd.print("Green House ");
lcd.setCursor(0,1);
lcd.print(" Monitering");
delay(2000)
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SANDEEP");
lcd.setCursor(0,1);
lcd.print("https://github.com/sandeeps29");
delay(2000);
lcd.clear();
}
void loop()
{
//dht.read11(dht_dpin);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" humidity=");
lcd.print(humidity=dht.readHumidity());
lcd.print(" % ");
// lcd.clear();
lcd.setCursor(0,1);
lcd.print("temperature=");
lcd.print(temperature=dht.readTemperature());
lcd.write(1);
lcd.print("C ");
delay(2000);
15
//lcd.clear();
value=analogRead(LUX);
volt=(value/1023.0)*5;
lux=((2500/volt)-500)/3.3;
delay(10);
if(lux<1)
{
digitalWrite(light, HIGH);
//sSerial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("LOW LIGHT ");
Serial.println("LIGHT TURNED ON");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" Degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Low light ");
lcd.print(lux);
lcd.print(" LUX");
lcd.setCursor(0,1);
lcd.print("Lights turned ON");
check=1;
16
test=1;
delay(2000);
}
else
{
if(check==1)
{
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.print("LIGHT TURNED OFF");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
check=0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("light int: ");
lcd.print(lux);
lcd.print(" LUX");
lcd.setCursor(0,1);
lcd.print("Lights turned OFF");
}
digitalWrite(light, LOW);
17
test=0;
delay(2000);
}
if(temperature >32)
{
digitalWrite(fan, HIGH);
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("TEMPERATURE INCREASES FROM CRITICAL LEVEL");
Serial.println("FAN TURNED ON");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp increases ");
lcd.setCursor(0,1);
lcd.print("Fan Turned ON ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temperature");
lcd.setCursor(0,1);
18
lcd.print(temperature);
lcd.write(1);
lcd.print("C");
check=2;
test2=1;
delay(2000);
}
else
{
if(check==2)
{
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("FAN TURNED OFF");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
check=0;
test1=0;
}
digitalWrite(fan, LOW);
delay(1000);
}
19
if(humidity < 90)
{
digitalWrite(spray, HIGH);
digitalWrite(13, HIGH);
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("HUMIDITY INCREASES FROM DEFINED LEVEL ");
Serial.println("SPRAY TURNED ON");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Humidity increase");
lcd.setCursor(0,1);
lcd.print("Spray Turned ON ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Humidity");
lcd.setCursor(0,1);
lcd.print(humidity);
lcd.print(" %");
20
check=3;
test2=1;
delay(2000);
}
else
{
if(check==3)
{
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("SPRAY TURNED OFF");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
check=0;
}
digitalWrite(13, LOW);
digitalWrite(spray, LOW);
test2=0;
delay(2000);
}
if(digitalRead(soil)==1)
{
21
digitalWrite(motor, HIGH);
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
Serial.println("WATER REQUIRED ");
Serial.println("MOTOR TURNED ON ");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
check=4;
test3=1;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Water Required ");
lcd.setCursor(0,1);
lcd.print("Motor turned ON");
delay(2000);
}
else
{
if(check==4)
{
//Serial.println("AT+CMGF=1");
//Serial.println("AT+CMGS="8921798096"");
22
Serial.println("WATER REQUIRED ");
Serial.println("MOTOR TURNED OFF ");
Serial.print("Light Intensity: ");
Serial.print(lux);
Serial.println(" LUX");
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" degree Celsius");
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.write(26);
check=0;
}
digitalWrite(motor, LOW);
test3=0;
}
delay(100);
}
