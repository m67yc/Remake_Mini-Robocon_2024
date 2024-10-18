#include <Arduino.h>
#include <multiplexer.h>
#include <Joystick.h>

Multiplexer Multiplexer(4, 5, 6, 7, A4);
Joystick Joystick;

void setup() {

  Serial.begin(9600);

}

void loop() {

  Multiplexer.getAllDate();
  Multiplexer.showValue();
  Joystick.showMapValue(Multiplexer.getAngData(1), Multiplexer.getAngData(14));
  // Serial.println(Joystick.getMapX(Multiplexer.getAngData(1)));
  // Multiplexer.showAngData();

}