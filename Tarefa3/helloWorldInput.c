#include "event_driven.h"

#define BUTTON 2
#define LED 13

void init () {
  Serial.begin(9600);
  button_listen(BUT_PIN);
  timer_set (1, 10000);
  timer_set (2, 20000);
}


void button_changed (int pin, int v) {
  digitalWrite(LED_PIN, v);
}


void timer_expired (int timerNumber){
  switch(timerNumber){
    case 1:
      Serial.println("Timer 1 has expired!");
    break;

    case 2:
      Serial.println("Timer 2 has expired!");
    break;

    default:

  }


}
