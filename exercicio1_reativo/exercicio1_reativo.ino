#define BUTTON1 2
#define LED 12

//Flag that controls the state of the button. False means it was never pressed.
bool flag = false;

int lastTime = millis();
int currentTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON1, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Checks if the button was pressed.
  if ( digitalRead(BUTTON1) == LOW) {
    flag = true;
  }

  if (flag == false) {
    currentTime = millis();
    if (currentTime >= lastTime + 1000) {
      lastTime = currentTime;
      if (digitalRead(LED) == HIGH) {
        digitalWrite(LED, LOW);
      }
      else {
        digitalWrite(LED, HIGH);
      }
    }
  }
  else{
    digitalWrite(LED, HIGH);
    while(true);
  }
}
