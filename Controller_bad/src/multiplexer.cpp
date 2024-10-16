#include "multiplexer.h"

Multiplexer::Multiplexer(uint8_t pin_multiplexer_S0, uint8_t pin_multiplexer_S1, uint8_t pin_multiplexer_S2, uint8_t pin_multiplexer_S3, uint8_t pin_multiplexer_SIG)
:m_pin_multiplexer_S0(pin_multiplexer_S0), m_pin_multiplexer_S1(pin_multiplexer_S1), m_pin_multiplexer_S2(pin_multiplexer_S2), m_pin_multiplexer_S3(pin_multiplexer_S3), m_pin_multiplexer_SIG(pin_multiplexer_SIG) {

    pinMode(m_pin_multiplexer_S0, OUTPUT);
    pinMode(m_pin_multiplexer_S1, OUTPUT);
    pinMode(m_pin_multiplexer_S2, OUTPUT);
    pinMode(m_pin_multiplexer_S3, OUTPUT);
    digitalWrite(m_pin_multiplexer_S0, LOW);
    digitalWrite(m_pin_multiplexer_S1, LOW);
    digitalWrite(m_pin_multiplexer_S2, LOW);
    digitalWrite(m_pin_multiplexer_S3, LOW);

}

void Multiplexer::selectChannel(uint8_t selChannel){

    Bit0 = bitRead(selChannel, 0);
    Bit1 = bitRead(selChannel, 1);
    Bit2 = bitRead(selChannel, 2);
    Bit3 = bitRead(selChannel, 3);
    digitalWrite(m_pin_multiplexer_S0, Bit0);
    digitalWrite(m_pin_multiplexer_S1, Bit1);
    digitalWrite(m_pin_multiplexer_S2, Bit2);
    digitalWrite(m_pin_multiplexer_S3, Bit3);

}

void Multiplexer::getAllDate(){

    for(int i = 0;i < 16;i++){
        selectChannel(i);
        arr[i] = analogRead(m_pin_multiplexer_SIG);
    }

}

uint16_t Multiplexer::getAngData(uint8_t num){

    return arr[num];
    
}

uint16_t Multiplexer::getDigitalData(uint8_t num){

    uint16_t ButtonState = arr[num];
    if(ButtonState >= 682){
        return 1;
    }
    else if(ButtonState >= 341){
        return 2;
    }
    else{
        return 0;
    }

}

void Multiplexer::showAngData(){

    for (int i = 0; i < 16; i++) {
        if(i == 15){
           Serial.println(arr[i]);  
        }
        else{
            Serial.print(arr[i]);
            Serial.print(",");
        }
    }
}

uint16_t Multiplexer::readValue(uint8_t num){

    if(num == 0){
        return digitalRead(m_pin_multiplexer_S0);
    }
    else if(num == 1){
        return digitalRead(m_pin_multiplexer_S1);
    }
    else if(num == 2){
        return digitalRead(m_pin_multiplexer_S2);
    }
    else if(num == 3){
        return digitalRead(m_pin_multiplexer_S3);
    }
    
}

void Multiplexer::showValue(){

    Serial.print("JY X/Y: ");
    Serial.print(arr[1]);
    Serial.print(", ");
    Serial.print(arr[14]);
    Serial.print("  ;  ");
    Serial.print("Button(UP1): ");
    Serial.print(arr[13]);
    Serial.print(", ");
    Serial.print(arr[7]);
    Serial.print(", ");
    Serial.print(arr[5]);
    Serial.print(", ");
    Serial.print(arr[11]);
    Serial.print(", ");
    Serial.print(arr[9]);
    Serial.print(", ");
    Serial.print(arr[3]);
    Serial.print(", ");
    Serial.print(arr[2]);
    Serial.print(", ");
    Serial.print(arr[10]);
    Serial.print("  ;  ");
    Serial.print("Potentiometer(Left1): ");
    Serial.print(arr[0]);
    Serial.print(", ");
    Serial.print(arr[8]);
    Serial.print(", ");
    Serial.print(arr[4]);
    Serial.print(", ");
    Serial.println(arr[12]);

}