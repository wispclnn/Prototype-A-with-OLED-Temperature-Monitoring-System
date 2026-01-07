##Prototype A with OLED – Temperature Monitoring System
 
 ##Description

Prototype A with OLED is a simple temperature monitoring system built using a DHT11 sensor, OLED display, and LED indicators. It displays real-time temperature readings on the OLED screen and visually indicates whether the environment is hot or cool using LEDs.

##Components Used

* DHT11 Temperature Sensor

* OLED Display (128×64, I2C)

* Red LED (Hot indicator)

* Green LED (Cool indicator)

Microcontroller (Arduino / ESP32)

##How It Works

* Reads temperature from the DHT11 sensor

* Compares the value to a preset threshold (25°C)

* Turns RED LED ON if temperature is above the threshold

* Turns GREEN LED ON if temperature is below or equal to the threshold

* Displays temperature and status on the OLED screen

* Updates every 2 seconds

##Output

* OLED Display: Temperature value and status

* LEDs: Visual hot/cool indicator

* Serial Monitor: Debug and temperature logs

##Use Case

* Beginner Arduino/ESP32 project

* Basic environmental monitoring
