#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(11, OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
    if (results.value == 0xFFA25D) {
        digitalWrite(11, HIGH);
        delay(500);
    }
    digitalWrite(11, LOW);
    irrecv.resume();
  }
}
