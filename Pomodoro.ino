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

void setup() {
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(ENCODER_SW_PIN, INPUT_PULLUP);

    pinMode(ON_BOARD_LED_PIN, OUTPUT);
}



void loop() {
    if (digitalRead(SWITCH_PIN) == LOW) {
      digitalWrite(ON_BOARD_LED_PIN, HIGH);
    } else {
      digitalWrite(ON_BOARD_LED_PIN, LOW);
    }
}
