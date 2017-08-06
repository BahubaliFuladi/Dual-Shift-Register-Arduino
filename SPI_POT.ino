#include <SPI.h>
#include"value.h"
byte address = 0x00;
int pot1CS= 10;
int pot2CS= 11;

void setup()
{
pinMode (pot1CS, OUTPUT);
pinMode (pot2CS, OUTPUT);
SPI.begin();
digitalPotWrite(pot1,pot1CS);
digitalPotWrite(pot2,pot2CS);
}

void loop()
{
  
  }

int digitalPotWrite(int value,int CS)
{
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}
