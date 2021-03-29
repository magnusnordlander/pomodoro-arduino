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


void setup() {
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(ENCODER_SW_PIN, INPUT_PULLUP);

    pinMode(ON_BOARD_LED_PIN, OUTPUT);

    u8g2.begin();
}



void loop() {
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_ncenB08_tr);

    int millisRemaining = countdownMillis - millis();

    String text = String(millisRemaining/1000) + " s";
    u8g2.drawStr(16, 16, text.c_str());


    u8g2.sendBuffer();
}
