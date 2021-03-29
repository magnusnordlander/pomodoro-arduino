#include <U8g2lib.h>
#include <U8x8lib.h>

// DT and CLK must be interrupt pins
#define ENCODER_SW_PIN 4
#define ENCODER_DT_PIN 3
#define ENCODER_CLK_PIN 2

#define SWITCH_PIN 14

#define ON_BOARD_LED_PIN 21

// With the exception of CS, these pins are hardware supported
#define UEXT_SPI_CS_PIN 10
#define UEXT_SPI_SCK_PIN 13
#define UEXT_SPI_MISO_PIN 12
#define UEXT_SPI_MOSI_PIN 11
#define UEXT_I2C_SCL_PIN 19
#define UEXT_I2C_SDA_PIN 18

U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI u8g2(U8G2_R2, UEXT_SPI_CS_PIN, UEXT_I2C_SCL_PIN, UEXT_I2C_SDA_PIN);


int countdownMillis = 10000;
int countdownStart = 0;
bool countdownGoing = false;


void setup() {
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(ENCODER_SW_PIN, INPUT_PULLUP);

    pinMode(ON_BOARD_LED_PIN, OUTPUT);

    u8g2.begin();
}



void loop() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);

    if (digitalRead(SWITCH_PIN) == LOW) {
      countdownStart = millis();
      countdownGoing = true;
    }
    

    int millisRemaining = countdownStart + countdownMillis - millis();


    if (countdownGoing) {
      String text = String(millisRemaining/1000) + " s";
      u8g2.drawStr(16, 16, text.c_str());
    } else {
      u8g2.drawStr(16, 16, "No timer running");

      String text = String(String("Ready for " + countdownMillis/1000) + "s");
      u8g2.drawStr(16, 26, text.c_str());
    }
    

    if (!countdownGoing || millisRemaining <= 0) {
      digitalWrite(ON_BOARD_LED_PIN, HIGH);
      countdownGoing = false;
    } else {
      digitalWrite(ON_BOARD_LED_PIN, LOW);
    }


    u8g2.sendBuffer();
}
