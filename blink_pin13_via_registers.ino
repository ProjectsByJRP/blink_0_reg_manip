// Blink for Adafruit Feather M0
// SAMD21 direct register manipulation
//
// These registers expect a bitmask because
// you can use these commands on multiple
// pins at once. Hence the cast to unsigned 32-bit
// integer, and the bit shift to set the mask
//
// setting DIRSET to 1 sets direction to output
// setting OUTSET to 1 sets output to high
// setting OUTTGL to 1 toggles the pin
//
// LED_BUILTIN is a macro for the built-in LED on pin 13
//
// this could also have been written
//void setup() {
//  // put your setup code here, to run once:
// PORT->Group[PORTA].DIRSET.reg = PORT_PA17;
// PORT->Group[PORTA].OUTSET.reg = PORT_PA17;
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
// PORT->Group[PORTA].OUTTGL.reg = PORT_PA17;
// delay(1000);
//}
//
//
// See:
// Arduino15/packages/adafruit/hardware/samd/1.0.13/variants/arduino_zero/variant.cpp
// Arduino15/packages/arduino/tools/CMSIS/4.0.0-atmel/Device/ATMEL/samd21/include/component/port.h
// on mac they're in ~/Library/
// windows try AppData/Local/
//

void setup() {
  // put your setup code here, to run once:
  PORT->Group[g_APinDescription[LED_BUILTIN].ulPort].DIRSET.reg = (uint32_t)(1<<g_APinDescription[LED_BUILTIN].ulPin);
  PORT->Group[g_APinDescription[LED_BUILTIN].ulPort].OUTSET.reg = (uint32_t)(1<<g_APinDescription[LED_BUILTIN].ulPin);
}

// setting OUTTGL to 1 toggles the pin's output
void loop() {
  // put your main code here, to run repeatedly:
  PORT->Group[g_APinDescription[LED_BUILTIN].ulPort].OUTTGL.reg = (uint32_t)(1<<g_APinDescription[LED_BUILTIN].ulPin);
  delay(1000);
}

