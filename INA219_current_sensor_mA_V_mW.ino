// Medición de consumo de pequeños componentes electrónicos con el módulo sensor de corriente INA219.
// Muestra por pantalla OLED de 128x64 las magnitudes: mA, V y mW.
// Written by PLÉYADES IT

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#define OLED_ADDR 0x3C
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);   // OLED display starts
  display.clearDisplay();       // Clear OLED display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15,15);     // Horizontal x vertical
  display.print("Pleyades");
  display.setCursor(55,40);
  display.print("IT");
  display.display();
  delay(4000);
  display.clearDisplay();       
  //display.setTextSize(2);
  display.setCursor(30,12);
  display.print("INA219");
  display.setTextSize(1);
  display.setCursor(10,40);
  display.print("current measurement");
  display.setCursor(48,53);
  display.print("module");
  display.display();
  delay(3000);
  display.clearDisplay();
  ina219.begin();  // INA219 starts
}

void loop()
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;
  // Get data from sensor
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  // Show data
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(10,0);
  display.print(current_mA);
  display.setCursor(70,0);
  display.print(" mA");
  display.setCursor(10,25);
  display.print(loadvoltage);
  display.setCursor(70,25);
  display.print(" V");
  display.setCursor(10,50);
  display.print(power_mW);
  display.setCursor(70,50);
  display.print(" mW");
  display.display();
  delay(2000);
}
