#include "event_driven.h"
#include <limits.h>

#define BUTMAX 13
#define TIMEMAX 2

char button[BUTMAX];
bool lastState[BUTMAX];
char nButtons;

int timerValue[TIMEMAX];
unsigned long timerSet[TIMEMAX];
bool expired[TIMEMAX];

void button_listen (int pin) {
  if (nButtons == BUTMAX) {
    Serial.println("Maximum number of buttons used. Aborting");
    exit(1);
  }
  button[nButtons] = pin;
  nButtons++;
}


void timer_set (int timerNumber, int ms) {
  if (timerNumber > TIMEMAX) {
    Serial.println("Maximum number of timers used. Aborting");
    exit(1);
  }
  timerValue[timerNumber - 1] = ms;
  timerSet[timerNumber - 1] = millis();
  expired[timerNumber - 1] = false;
}


void setup() {
  nButtons = 0;
  for (int i = 0; i < BUTMAX; i++) {
    lastState[i] = HIGH;
  }

  initialize();

  for (int i = 0; i < nButtons; i++) {
    pinMode(button[i], INPUT);
  }
}


void loop() {

  for (int k = 0; k < BUTMAX; k++) {
    char aux = digitalRead(button[k]);
    if (aux != lastState[k]) {
      lastState[k] = aux;
      button_changed(button[k], aux);
    }
  }

  for (int j = 0; j < TIMEMAX; j++) {
    if (millis() - timerSet[j] >= timerValue[j] && !expired[j]) {
      expired[j] = true;
      timer_expired(j + 1);
    }
  }

}
