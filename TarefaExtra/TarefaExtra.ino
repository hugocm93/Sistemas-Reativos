/*Usando um sensor de temperatura,
  fazer um termômetro com vários LEDs
  empilhados. Quanto mais quente,
  mais leds acendem*/

 /*Material consultado sobre charlieplexing: http://www.instructables.com/id/Charlieplexing-the-Arduino/*/

/*Pinos para fazer o charlieplexing
(Acender 6 Leds com apenas 3 portas digitais)*/
#define pin13 13
#define pin12 12
#define pin11 11

/*Porta analógica que lê o sensor de temperatura*/
#define SENSOR A0


/*Funções auxiliares para fazer o charlieplexing.
Cada função define um estado do pino correspondente
(H, L ou Z)*/
void setH(int pin);
void setL(int pin);
void setZ(int pin);

/*Função que acende determinado led. 
Cada arranjo entre H, L, Z determina o 
acender de um led. O total de arranjos é 6.*/
void turnOnLed(int number);

void setup() {
  //Serial.begin(9600);
  pinMode(SENSOR, INPUT);
}

void loop() {
  int sensorValue = analogRead(SENSOR);
  //Serial.println(sensorValue);

  /*Mapeia o valor lido para acender uma quantidade 
  específica de leds. Os parâmetros 30 e 40 são empíricos
  e foram escolhidos de modo a permitir a visualização dos
  leds com uma pequena variação de temperatura. Não foi feita
  nenhuma conversão para apresentar a temperatura em uma 
  unidade de medida padronizada.*/
  int numberOfLeds = map(sensorValue, 30, 40, 1, 6);


  /*Acende uma quantidade de leds proporcional à temperatura lida. 
  Somente um led é aceso por vez, mas como o loop acontece muito rápido, 
  o efeito visual faz com que pensemos que estejam acesos simultaneamente.
  Similar ao efeito do PWM*/
  for(int i=1; i<=numberOfLeds; i++){
    turnOnLed(i);
    delay(2);
  }
}

void turnOnLed(int number) {
  switch (number) {
    case 1:
    setL(pin13);
    setH(pin12);
    setZ(pin11);
      break;

    case 2:
    setH(pin13);
    setL(pin12);
    setZ(pin11);
      break;

    case 3:
    setZ(pin13);
    setL(pin12);
    setH(pin11);
      break;

    case 4:
    setZ(pin13);
    setH(pin12);
    setL(pin11);
      break;

    case 5:
    setL(pin13);
    setZ(pin12);
    setH(pin11);
      break;

    case 6:
    setH(pin13);
    setZ(pin12);
    setL(pin11);
      break;

    default:
    setL(pin13);
    setL(pin12);
    setL(pin11);
  }
}

void setH(int pin){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void setL(int pin){
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW); 
}

void setZ(int pin){
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
}

