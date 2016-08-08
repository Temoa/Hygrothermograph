// include the library code:
#include <LiquidCrystal.h>
#include <dht11.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up DHT11
dht11 DHT11;
#define DHT11_PIN 7

int temp = 0;
int hum = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  // 2004A have 20 columms and 4 rosw
  lcd.begin(20, 4);
  
  lcd.setCursor(3, 0);
  lcd.print("Hello, Temoa!!");
  lcd.setCursor(0, 2);
  lcd.print("Temperature(c) : ");
  lcd.setCursor(0, 3);
  lcd.print("Humidity(%) :");
  delay(1000);
}

void loop() {
  // get temperature and humidity from DHT11
  if (DHT11.read(DHT11_PIN) == DHTLIB_OK) {
    temp = DHT11.temperature - 3;
    hum = DHT11.humidity;
  }
  // show temperature and humidity into lcd
  lcd.setCursor(17, 2);
  lcd.print(temp);
  lcd.setCursor(14, 3);
  lcd.print(hum);

  delay(2000);
}
