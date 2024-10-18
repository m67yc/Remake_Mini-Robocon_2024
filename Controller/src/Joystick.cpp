#include "Joystick.h"

// Must Check the function can run successful befor go to next function

Joystick::Joystick(){

    

}

// uint16_t Joystick::getRawX(){

//     return analogRead(m_pin_Joystick_X);
    
// }

// uint16_t Joystick::getRawY(){
    
//     return analogRead(m_pin_Joystick_X);
    
// }


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


uint16_t Joystick::getMapX(uint16_t value){

    uint16_t m_value = value;

    if(m_value < m_DeadZoneX_insideLeft && m_value > m_DeadZoneX_insideRight){
        if(m_value > m_DeadZoneX_outsideLeft && m_value < m_DeadZoneX_outsideRight){
            m_MapX = map(m_value, 0, 1023, -255, 255);
        }
        else{
            m_MapX = map((m_value < m_DeadZoneX_outsideLeft ? m_DeadZoneX_outsideLeft : m_DeadZoneX_outsideRight), 0, 1023, 0, 255);
        }
    }
    else{
        m_MapX = 0;
    }

    return m_MapX;

}

uint16_t Joystick::getMapY(uint16_t value){

    uint16_t m_value = value;

    if(m_value < m_DeadZoneY_insideBottom && m_value > m_DeadZoneY_insideTop){
        if(m_value > m_DeadZoneY_insideBottom && m_value < m_DeadZoneY_outsideTop){
            m_MapY = map(m_value, 0, 1023, -255, 255);
        }
        else{
            m_MapY = map((m_value < m_DeadZoneY_outsideBottom ? m_DeadZoneY_outsideBottom : m_DeadZoneY_outsideTop), 0, 1023, 0, 255);
        }
    }
    else{
        m_MapY = 0;
    }

    return m_MapY;

}


// void Joystick::showRawValue(){

//     Serial.print("X: ");
//     Serial.print(getRawX());
//     Serial.print("  ;   Y: ");
//     Serial.println(getRawY());

// }

void Joystick::showMapValue(uint16_t valueX, uint16_t valueY){

    Serial.print("X: ");
    Serial.print(getMapX(valueX));
    Serial.print("  ;   Y: ");
    Serial.println(getMapY(valueY));
    
}
