/*  Piscar o LED a cada 1 segundo.
    Botão 1: Acelerar o pisca­pisca a cada pressionamento.
    Botão 2: Desacelerar a cada pressionamento.
    Botão 1+2 (em menos de 500ms): Parar.
*/

#include <limits.h>
#define BUTTON1 2
#define BUTTON2 4
#define LED 12
#define LEAP 80
#define TOLERANCE 500
#define INTERVAL 1000

short interval = INTERVAL;
int lastTime = millis();
int currentTime;

char buttons[2] = {BUTTON1, BUTTON2};
bool pressed[2] = {false, false};
bool released[2] = {true, true};
int stampRelease[2] = {INT_MIN, INT_MIN};

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < 2; i++) {
    pinMode(buttons[i], INPUT);
  }
  pinMode(LED, OUTPUT);

}

void loop() {

  for (int i = 0; i < 2; i++) {
    
    //Checks if the buttoni was pressed.
    if ( digitalRead(buttons[i]) == LOW) {
      released[i] = false;
      pressed[i] = true;
    }

    //Checks if the buttoni was released and makes the action happen.
    if ( digitalRead(buttons[i]) == HIGH && pressed[i] == true) {
      released[i] = true;
      pressed[i] = false;
      if (i == 0) {
        interval += LEAP;
      }
      else {
        interval -= LEAP;
      }
      stampRelease[i] = millis();
    }
  }

  //Checks if the buttons were pressed at the same time.
  if(abs(stampRelease[0] - stampRelease[1]) <= TOLERANCE && stampRelease[0] != INT_MIN && stampRelease[1] != INT_MIN){
     digitalWrite(LED, LOW);
     Serial.println(abs(stampRelease[0] - stampRelease[1]));
     Serial.println("Both pressed");
     while(true);
  }


  //Makes the led blink.
  currentTime = millis();
  if (currentTime >= lastTime + interval) {
    lastTime = currentTime;
    if (digitalRead(LED) == HIGH) {
      digitalWrite(LED, LOW);
    }
    else {
      digitalWrite(LED, HIGH);
    }
  }
}
