#include "event_driven.h"

#define BUTTON 2
#define LED 13

void initialize () {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  button_listen(BUTTON);
  timer_set (1, 1000);
}


void button_changed (int pin, int v) {
  digitalWrite(LED, v);
}


void timer_expired (int timerNumber){
  switch(timerNumber){
    case 1:
      if(digitalRead(LED)==HIGH){
        digitalWrite(LED, LOW);
      }
      else{
        digitalWrite(LED, HIGH);
      }
      //timer_set (1, 1000);
    break;

    case 2:

    break;

  }

}
