#define BUTTON1 2
#define BUTTON2 4
#define LED 12

bool flag = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if( digitalRead(BUTTON1) == LOW){
    flag = true;
  }
  
  if(flag == false){
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
    delay(1000);
  }
}
