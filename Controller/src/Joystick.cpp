#include "Joystick.h"

// Must Check the function can run successful befor go to next function

Joystick::Joystick(const uint8_t pin_Joystick_X, const uint8_t pin_Joystick_Y)
: m_pin_Joystick_X(pin_Joystick_X), m_pin_Joystick_Y(pin_Joystick_Y){

    pinMode(m_pin_Joystick_X, INPUT);
    pinMode(m_pin_Joystick_Y, INPUT);
    m_RawX = getRawX();
    m_RawY = getRawY();

}

uint16_t Joystick::getRawX(){

    return analogRead(m_pin_Joystick_X);
    
}

uint16_t Joystick::getRawY(){
    
    return analogRead(m_pin_Joystick_X);
    
}


void Joystick::setDeadZoneX(){

    

}

void Joystick::setDeadZoneY(){

    

}


void Joystick::setDeadZoneX(uint16_t DeadZoneX_insideRight, uint16_t DeadZoneX_insideLeft, uint16_t DeadZoneX_outsideRight, uint16_t DeadZoneX_outsideLeft){

    m_DeadZoneX_insideLeft = DeadZoneX_insideLeft;
    m_DeadZoneX_insideRight = DeadZoneX_insideRight;
    m_DeadZoneX_outsideLeft = DeadZoneX_outsideLeft;
    m_DeadZoneX_outsideRight = DeadZoneX_outsideRight;

}

void Joystick::setDeadZoneY(uint16_t DeadZoneY_insideTop, uint16_t DeadZoneY_insideBottom, uint16_t DeadZoneY_outsideTop, uint16_t DeadZoneY_outsideBottom){

    m_DeadZoneY_insideTop = DeadZoneY_insideTop;
    m_DeadZoneY_insideBottom = DeadZoneY_insideBottom;
    m_DeadZoneY_outsideTop = DeadZoneY_outsideTop;
    m_DeadZoneY_outsideBottom = DeadZoneY_outsideBottom;

}


int16_t Joystick::getMapX(){

    if(getRawX() < m_DeadZoneX_insideLeft && getRawX() > m_DeadZoneX_insideRight){
        if(getRawX() > m_DeadZoneX_outsideLeft && getRawX() < m_DeadZoneX_outsideRight){
            m_MapX = map(getRawX(), 0, 1023, 0, 255);
        }
        else{
            m_MapX = getRawX() < m_DeadZoneX_outsideLeft ? m_DeadZoneX_outsideLeft : m_DeadZoneX_outsideRight;
        }
    }
    else{
        m_MapX = m_RawX;
    }

    return m_MapX;

}

int16_t Joystick::getMapY(){

    if(getRawY() < m_DeadZoneY_insideBottom && getRawY() > m_DeadZoneY_insideTop){
        if(getRawY() > m_DeadZoneY_insideBottom && getRawY() < m_DeadZoneY_outsideTop){
            m_MapY = map(getRawY(), 0, 1023, 0, 255);
        }
        else{
            m_MapY = getRawY() < m_DeadZoneY_outsideBottom ? m_DeadZoneY_outsideBottom : m_DeadZoneY_outsideTop;
        }
    }
    else{
        m_MapY = m_RawY;
    }

    return m_MapY;

}


void Joystick::showRawValue(){

    Serial.print("X: ");
    Serial.print(getRawX());
    Serial.print("  ;   Y: ");
    Serial.println(getRawY());

}

void Joystick::showMapValue(){

    Serial.print("X: ");
    Serial.print(getMapX());
    Serial.print("  ;   Y: ");
    Serial.println(getMapY());
    
}
