#include <Firmata.h>

void setup()
{
  //
  pinMode( 0, INPUT_PULLUP);
  pinMode( 1, INPUT_PULLUP);
  pinMode( 2, INPUT_PULLUP);
  pinMode( 3, INPUT_PULLUP);
  pinMode( 4, INPUT_PULLUP);
  pinMode( 5, INPUT_PULLUP);
  pinMode( 6, INPUT_PULLUP);
  pinMode( 7, INPUT_PULLUP);
  //
  pinMode( 8, INPUT_PULLUP);
  pinMode( 9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  //
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);

  Firmata.setFirmwareVersion(FIRMATA_FIRMWARE_MAJOR_VERSION, FIRMATA_FIRMWARE_MINOR_VERSION);
  //NOTE: Firmata wants to 'blink' LED to inform firmware version, so ...
  //      by default, set LED pin to be OUTPUT,
  //      which will distract/confuse us from using pin 13 as normal input.
  Firmata.disableBlinkVersion();
  Firmata.begin(57600);
}

void loop()
{
  byte port = 0;

  static byte port0_prev = 0;
  port = 0x00;
  port |= (digitalRead( 0) ? 0x01 : 0x00);
  port |= (digitalRead( 1) ? 0x02 : 0x00);
  port |= (digitalRead( 2) ? 0x04 : 0x00);
  port |= (digitalRead( 3) ? 0x08 : 0x00);
  port |= (digitalRead( 4) ? 0x10 : 0x00);
  port |= (digitalRead( 5) ? 0x20 : 0x00);
  port |= (digitalRead( 6) ? 0x40 : 0x00);
  port |= (digitalRead( 7) ? 0x80 : 0x00);
  if (port0_prev != port) Firmata.sendDigitalPort(0, port);
  port0_prev = port;

  static byte port1_prev = 0;
  port = 0x00;
  port |= (digitalRead( 8) ? 0x01 : 0x00);
  port |= (digitalRead( 9) ? 0x02 : 0x00);
  port |= (digitalRead(10) ? 0x04 : 0x00);
  port |= (digitalRead(11) ? 0x08 : 0x00);
  port |= (digitalRead(12) ? 0x10 : 0x00);
  port |= (digitalRead(13) ? 0x20 : 0x00);
  port |= (digitalRead(14) ? 0x40 : 0x00);
  port |= (digitalRead(15) ? 0x80 : 0x00);
  if (port1_prev != port) Firmata.sendDigitalPort(1, port);
  port1_prev = port;

  static byte port2_prev = 0;
  port = 0x00;
  port |= (digitalRead(24) ? 0x01 : 0x00);
  port |= (digitalRead(25) ? 0x02 : 0x00);
  port |= (digitalRead(26) ? 0x04 : 0x00);
  port |= (digitalRead(27) ? 0x08 : 0x00);
  port |= (digitalRead(28) ? 0x10 : 0x00);
  port |= (digitalRead(29) ? 0x20 : 0x00);
  port |= (digitalRead(30) ? 0x40 : 0x00);
  port |= (digitalRead(31) ? 0x80 : 0x00);
  if (port2_prev != port) Firmata.sendDigitalPort(2, port);
  port2_prev = port;

  delay(20);
}
