#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender

IRsendRaw mySender; // on pin d3

int buttonPin = 7;
int buttonState = 0;
int buttonSeq = 0; //0-3-2

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("MSNBC It!"));
  pinMode(buttonPin, INPUT);
}

#define RAW_DATA_LEN 68
uint16_t zero_rawData[RAW_DATA_LEN]={
  8986, 4542, 522, 1686, 522, 586, 522, 1694, 
  526, 582, 530, 574, 526, 582, 522, 586, 
  526, 1686, 518, 586, 526, 586, 522, 586, 
  526, 582, 526, 1686, 522, 1686, 534, 574, 
  526, 582, 526, 1714, 506, 574, 522, 586, 
  522, 586, 526, 1710, 510, 1686, 518, 582, 
  530, 582, 526, 582, 518, 586, 522, 586, 
  522, 586, 526, 578, 530, 578, 522, 1694, 
  522, 1686, 526, 1000};

uint16_t three_rawData[RAW_DATA_LEN]={
  8990, 4534, 518, 1694, 526, 582, 526, 1686, 
  526, 586, 522, 586, 522, 586, 526, 574, 
  522, 1722, 498, 582, 526, 582, 518, 590, 
  522, 582, 526, 1718, 502, 1686, 518, 586, 
  526, 578, 530, 578, 522, 1718, 498, 582, 
  530, 1686, 522, 586, 530, 1678, 534, 578, 
  522, 586, 522, 586, 522, 586, 526, 582, 
  518, 582, 526, 1718, 498, 586, 514, 1694, 
  526, 1686, 534, 1000};

uint16_t two_rawData[RAW_DATA_LEN]={
  8990, 4534, 518, 1694, 526, 582, 530, 1686, 
  518, 594, 518, 586, 526, 578, 530, 578, 
  522, 1722, 494, 586, 526, 578, 522, 582, 
  526, 582, 526, 1718, 502, 1686, 526, 578, 
  526, 586, 526, 1686, 518, 586, 526, 586, 
  522, 1686, 526, 582, 522, 1694, 526, 582, 
  518, 590, 518, 586, 526, 578, 530, 578, 
  522, 586, 522, 1718, 502, 578, 522, 1694, 
  526, 1682, 534, 1000};


void loop() {
    buttonState = digitalRead(buttonPin);
    if(buttonState == HIGH) {
      if(buttonSeq == 0) {
        mySender.send(zero_rawData,RAW_DATA_LEN,36);
        buttonSeq = 3;
        delay(500);
      }
      if(buttonSeq == 3) {
        mySender.send(three_rawData,RAW_DATA_LEN,36);    
        buttonSeq = 2;
        delay(500); 
      }
      if(buttonSeq == 2) {
        mySender.send(two_rawData,RAW_DATA_LEN,36);
        buttonSeq = 0;
        delay(500);
      }
    }
}
