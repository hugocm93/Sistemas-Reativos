#include "event_driven.h"

#define BUTTON 2
#define LED 13

void initialize () {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  button_listen(BUTTON);
}


void button_changed (int pin, int v) {
  digitalWrite(LED, v);
}


void timer_expired (int timerNumber){
  
}
