# INTRODUCTON
Project using Arduino to introduce smart greenhouse.
Today agriculture is changing in response to the requirements of modern society, where ensuring food supply through practices such as water conservation, reduction of agrochemicals and the required planted surface, which guarantees high quality crops are in demand. Greenhouses have proven to be a reliable solution to achieve these goals; however, a greenhouse as a means for protected agriculture has the potential to lead to serious problems. The most of these are related to the inside greenhouse climate conditions where controlling the temperature and relative humidity (RH) are the main objectives of engineering. Achieving appropriate climate conditions to ensure high yield and quality crops reducing energy consumption have been the objective of investigations for some time. Our system is used to control the climate inside the greenhouse. Indeed Greenhouses are considered as too difficult to maintain as the temperature needs continuous monitoring. As of today farmers are forced to appoint labor for monitoring the climate. This system would help farmers to control the climates of the greenhouse effortlessly by using various controlling units as they get instructions from Arduino. Arduino is the heart of the system which is coded according to the climate measures we want. Therefore, when the conditions fail Arduino would generate the signals for maintaining those variations and fix them as fast as they can. This system will be more functional and responsive instead of affording the labor. Here we have the hardware control units which are exactly appropriate for the corresponding climate variations. So the response from the Arduino will be executed successfully by the fans and motors. The changes like Temperature, Humidity, Light, and Soil will be recovered by the controlling units such as fans, sprays and heaters. Arduino works as a heart which can pump every unit that is connected to it. Every single change captured by the sensors will be responded to by Arduino as soon as possible. Greenhouses are considered as sensitive to climate fluctuations which can cause the plants affected, So that the farmers are eager to correct even the small changes.

# HARDWARE REQUIRMENTS
Relays

Arduino UNO

DHT11 sensor (Temperature + Humidity sensor)

Soil moisture sensor

LDR

LCD

Hook wires

Breadboard
# SOFTWARE REQUIRMENTS
Arduino IDE
# CIRCUIT DESIGN
In this system Arduino is the heart of the whole system which takes control over the process. When sensors sense any change in environment or in soil Arduino comes into action and processes the required operation. When the soil moisture sensor does not sense moisture in soil then Arduino turns on the water pump and sends a message to the owner of status that the motor is turned on. And if LDR senses low light then Arduino takes control and turns on the artificial lights.In this system a 16×2 LCD is used for displaying status for all operations like Motor turned on or off, temperature, humidity and light status. The LCD’s data pins are connected in 4-bit mode (data pin d5, d6, d7, d8 pin of LCD is directly connected with pin no. 4, 5, 6, 7 of Arduino and command pins of LCD’s Rs and En are connected with pin no. 2, 3 of Arduino). LDR is used for sensing light intensity and its output is connected to Analog pin A0 of Arduino while the artificial light is connected using relay. The relay is operated by using ULN2003 and controlled using pin number 10 of the arduino. Humidity and temperature sensors are used for sensing humidity and temperature that are connected directly with Analog pin A1 of Arduino. Fan is directly connected with pin 8 of Arduino and led light (in place of Sprays i used an led bulb to indicate humdity) is connected with pin 11 of arduino by using Relay. Water pump is also connected by using relay and is controlled by Arduino’s pin number 12(instead of waterpump i used a led bulb to indicate the working) and the sensor for measuring the soil moisture, pin number 9 is used.

# DETAIL REPORT LINK
https://drive.google.com/file/d/1qCJneNjyJcSFDIpgxZ4ZgghuXy9rEW1V/view?usp=sharing
# SAMPLE VIDEOS AND IMAGES
https://drive.google.com/drive/folders/1bzZkHxuyaT9sf7IUqkG53ZqWHNJwzEgb?usp=sharing


