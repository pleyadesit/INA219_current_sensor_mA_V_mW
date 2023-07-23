Code to measure the consumption of small electronic components with the INA219 current sensor module, controlled by an Arduino UNO or Nano board and showing the three magnitudes measured (mA, V and mW) through a 128x64 OLED screen.
Library used: Adafruit_INA219 (https://github.com/adafruit/Adafruit_INA219)

INA219 module (I2C interface)
- Module pin SDA --> Arduino pin A4
- Module pin SCK --> Arduino pin A5

OLED display: (SPI interface)
- OLED pin MOSI --> Arduino pin 9
- OLED pin CLK --> Arduino pin 10
- OLED pin DC --> Arduino pin 11
- OLED pin CS --> Arduino pin 12
- OLED pin RESET --> Arduino pin 13
