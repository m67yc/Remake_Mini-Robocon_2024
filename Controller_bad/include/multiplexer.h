#pragma once
#include "Arduino.h"

class Multiplexer{
    private:
        uint8_t m_pin_multiplexer_S0;
        uint8_t m_pin_multiplexer_S1;
        uint8_t m_pin_multiplexer_S2;
        uint8_t m_pin_multiplexer_S3;
        uint8_t m_pin_multiplexer_SIG;

        uint8_t Bit0;
        uint8_t Bit1;
        uint8_t Bit2;
        uint8_t Bit3;

        uint16_t arr[16];

    public:
        Multiplexer(uint8_t pin_multiplexer_S0, uint8_t pin_multiplexer_S1, uint8_t pin_multiplexer_S2, uint8_t pin_multiplexer_S3, uint8_t pin_multiplexer_SIG);
        void selectChannel(uint8_t selChannel);
        void getAllDate();
        uint16_t getAngData(uint8_t num);
        uint16_t getDigitalData(uint8_t num);
        void showAngData();
        uint16_t readValue(uint8_t num);
        void showValue();
};


