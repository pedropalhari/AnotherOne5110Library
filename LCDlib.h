#ifndef LCDh
#define LCDh


extern int RST, CE, DC, DIN, CLK, VCC;

void sendCommand(char command);
void sendData(char data);
void clearLCD();
void initialize();

#endif
