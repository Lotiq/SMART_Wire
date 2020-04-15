#include <DPM8600.h>
#include <SMART_Wire.h>

DPM8600 converter;
SMART_Wire wire;

void setup() {
  Serial.begin(9600);
  converter.begin(Serial);
  wire.train(converter);
}

void loop() {
  wire.activate(5);
  delay(60000);
}
