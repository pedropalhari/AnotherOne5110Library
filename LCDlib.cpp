
#include <Arduino.h>
#include "LCDlib.h"

int RST = 14, CE = 15, DC = 16, DIN = 17, CLK = 18, VCC = 19;

void initialize(){
  // put your setup code here, to run once:
  pinMode(RST, OUTPUT);
  pinMode(CE, OUTPUT);
  pinMode(DC, OUTPUT);
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(VCC, OUTPUT);
  
  digitalWrite(VCC, HIGH); 
  digitalWrite(RST, HIGH);   
  delay(100);
  
  //Seguindo o manual moleque, niceta
  //Modo de comandos avançados
  sendCommand(0x21);

  //Tensao de ligar/desligar LCD, importante 
  sendCommand(0xC5);
  //Temp control (???)
  sendCommand(0x07);

  //Voltage Bias 
  sendCommand(0x10);

  //Modo de comando normal
  sendCommand(0x20);

  //LCD em modo normal e pointeiro em 0,0;
  sendCommand(0x0C);
  sendCommand(0x80);
  sendCommand(0x40);

  //sendCommand(0xFF);
  clearLCD();
}

void sendCommand(char command){
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE, LOW);
  digitalWrite(DC, LOW);  
  shiftOut(DIN, CLK, MSBFIRST, command);  
  
  digitalWrite(CE, HIGH);
}

void sendData(char data){
  digitalWrite(CLK, LOW);
  
  digitalWrite(CE, LOW);
  digitalWrite(DC, HIGH);
  shiftOut(DIN, CLK, MSBFIRST, data);  
  
  digitalWrite(CE, HIGH);  
}

void clearLCD(){
  for(int i = 0; i < 504; i++)
    sendData(0x00);
}

