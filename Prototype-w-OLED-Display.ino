
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define HOTLED 16
#define COLDLED 17
#define TEMP 25

// OLED setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(HOTLED, OUTPUT);
  pinMode(COLDLED, OUTPUT);

  digitalWrite(HOTLED, LOW);
  digitalWrite(COLDLED, LOW);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // I2C address 0x3C is common
    Serial.println(F("LCD init failed"));
    for(;;); // Halt if display fails
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  float temp = dht.readTemperature();

  if(isnan(temp)) {
    Serial.println("Check DHT11 Sense Pin!");
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Sensor Error!");
    display.display();
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" degrees Celsius");

  String status;
  if (temp > TEMP) {
    digitalWrite(HOTLED, HIGH);
    digitalWrite(COLDLED, LOW);
    status = "HOT → RED LED";
  } else {
    digitalWrite(HOTLED, LOW);
    digitalWrite(COLDLED, HIGH);
    status = "COOL → GREEN LED";
  }

  // OLED output
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");
  display.println(status);
  display.display();

  delay(2000);
}