#ifndef LCDh
#define LCDh

#include <Arduino.h>
#include "LCDlibChars.h"

void initialize();

void sendCommand(char command);
void sendData(char data);
void sendMultipleData(char data[], int dataLength);
void writeString(String string);

void clearLCD();

#endif
