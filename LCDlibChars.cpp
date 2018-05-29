#include "LCDlibChars.h"

char charSmallSize = 5;

//MSB em baixo, LSB em cima, de baixo pra cima
char lib[][5] = {
  {0x7e, 0x11, 0x11, 0x11, 0x7e}, //A
  {0x7f, 0x49, 0x49, 0x49, 0x36}, //B
};

char* getChar(char index) {
  if(index <= 'Z' && index >= 'A')
    return lib[index - 65];
}

