#include <IRremote.h>
IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  //if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      irsend.sendRaw(0xA10C8C03, 32, 40); // 0
      delay(100);
    }
    delay(1000);
    for (int i = 0; i < 3; i++) {
      irsend.sendRaw(0xA10C540B, 32, 40); // 3
      delay(100);
    }
    delay(1000);
    for (int i = 0; i < 3; i++) {
      irsend.sendRaw(0xA10C940B, 32, 40); // 2
      delay(100);
    }
  //}
  delay(5000);
} 
