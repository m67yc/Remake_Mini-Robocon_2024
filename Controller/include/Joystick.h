#pragma once
#include <Arduino.h>

//You can add arguments and values by yourself if you need

class Joystick {
    private:
        const uint8_t m_pin_Joystick_X;
        const uint8_t m_pin_Joystick_Y;
        uint16_t m_RawX;
        uint16_t m_RawY;

        uint8_t m_DeadZoneX_insideRight;
        uint8_t m_DeadZoneX_insideLeft;
        uint8_t m_DeadZoneX_outsideRight;
        uint8_t m_DeadZoneX_outsideLeft;

        uint8_t m_DeadZoneY_insideTop;
        uint8_t m_DeadZoneY_insideBottom;
        uint8_t m_DeadZoneY_outsideTop;
        uint8_t m_DeadZoneY_outsideBottom;

        uint8_t m_MapX;
        uint8_t m_MapY;

        /*...*/

    public:
        Joystick(const uint8_t pin_Joystick_X, const uint8_t pin_Joystick_Y);

        uint16_t getRawX();
        uint16_t getRawY();

        void setDeadZoneX();
        void setDeadZoneY();

        void setDeadZoneX(uint16_t DeadZoneX_insideRight, uint16_t DeadZoneX_insideLeft, uint16_t DeadZoneX_outsideRight, uint16_t DeadZoneX_outsideLeft);
        void setDeadZoneY(uint16_t DeadZoneY_insideTop, uint16_t DeadZoneY_insideBottom, uint16_t DeadZoneY_outsideTop, uint16_t DeadZoneY_outsideBottom);

        int16_t getMapX();
        int16_t getMapY();

        void showRawValue();
        void showMapValue();

};
