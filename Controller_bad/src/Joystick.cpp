#include "Joystick.h"

// Must Check the function can run successful befor go to next function

Joystick::Joystick(){

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


uint16_t Joystick::getMapX(uint16_t raw){

    if(raw < m_DeadZoneX_insideLeft && raw > m_DeadZoneX_insideRight){
        if(raw > m_DeadZoneX_outsideLeft && raw < m_DeadZoneX_outsideRight){
            m_MapX = map(raw, 0, 1023, 0, 255);
        }
        else{
            m_MapX = raw < m_DeadZoneX_outsideLeft ? m_DeadZoneX_outsideLeft : m_DeadZoneX_outsideRight;
        }
    }
    else{
        m_MapX = m_RawX;
    }

    return m_MapX;

}

uint16_t Joystick::getMapY(uint16_t raw){

    if(raw < m_DeadZoneY_insideBottom && raw > m_DeadZoneY_insideTop){
        if(raw > m_DeadZoneY_insideBottom && raw < m_DeadZoneY_outsideTop){
            m_MapY = map(raw, 0, 1023, 0, 255);
        }
        else{
            m_MapY = raw < m_DeadZoneY_outsideBottom ? m_DeadZoneY_outsideBottom : m_DeadZoneY_outsideTop;
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
