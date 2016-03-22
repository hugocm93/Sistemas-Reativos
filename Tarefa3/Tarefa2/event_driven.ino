#include "event_driven.h"

#define BUTMAX 13
#define TIMEMAX 2

char button[BUTMAX];
bool lastState[BUTMAX];
char nButtons;

int timerValue[TIMEMAX];
unsigned long timerSet[TIMEMAX];

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
    if (millis() - timerSet[j] >= timerValue[j] && timerValue[j] > 0) {
      timerValue[j] = -1;
      timer_expired(j + 1);
    }
  }

}
