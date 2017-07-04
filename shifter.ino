#include"value.h"
int latchPin = 4; //connected to pin 12 (ST_CP) of both shift register ic
int clockPin = 5; //connected to pin 11 (SH_CP) of both shift register ic
int dataPin = 6; //connected to pin 12 (DS) of first shift register ic
void setup()
{
  pinMode(latchPin, OUTPUT); //seting direction of pins
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  //convertion relay status in array to bytes
  byte firstByte = 0;
  byte secondByte = 0;
  Serial.println("B1***************************");
  for (int i = 0; i < 8; i++)
  {
    firstByte = firstByte << 1;
    firstByte = firstByte | (relay[i] & 0x01);
    Serial.print(relay[i]);
    Serial.print(" ----  ");
    Serial.println(firstByte);
  }
  Serial.println("B1***************************");

  for (int i = 0; i < 8; i++)
  {
    secondByte = secondByte << 1;
    secondByte = secondByte | (relay[i + 8] & 0x01);
    Serial.print(relay[i]);
    Serial.print(" ----  ");
    Serial.println(secondByte);
  }
  Serial.print("firstByte");
  Serial.println(firstByte);
  Serial.print("secondByte");
  Serial.println(secondByte);
  digitalWrite(latchPin, LOW); //make the latch pin low. so that output will not change during shifting
  shiftOut(dataPin, clockPin, MSBFIRST, firstByte); //shift out first byte(relay#1 to #8)
  shiftOut(dataPin, clockPin, MSBFIRST, secondByte); //shift out second byte(relay#9 to #16)
  digitalWrite(latchPin, HIGH); //make the latch pin high. so thate relay status will be writen on it
}
void loop()
{
  //do noting
}
