/* rawSend.ino Example sketch for IRLib2
 *  Illustrates how to send a code Using raw timings which were captured
 *  from the "rawRecv.ino" sample sketch.  Load that sketch and
 *  capture the values. They will print in the serial monitor. Then you
 *  cut and paste that output into the appropriate section below.
 */
#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender

IRsendRaw mySender;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}
/* Cut and paste the output from "rawRecv.ino" below here. It will 
 * consist of a #define RAW_DATA_LEN statement and an array definition
 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes
 * with "…,1000};"
 */


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


/*
 * Cut-and-paste into the area above.
 */
   
void loop() {
  //if (Serial.read() != -1) {
    //send a code every time a character is received from the 
    // serial port. You could modify this sketch to send when you
    // push a button connected to an digital input pin.
    mySender.send(zero_rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    delay(100);
    mySender.send(three_rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency    
    delay(100);
    mySender.send(two_rawData,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("Sent signal."));
  //}
  delay(5000);
}
