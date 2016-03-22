#ifndef EVENT_DRIVEN
#define EVENT_DRIVEN

/* Funções de registro que estão implementadas em event_driven.ino */
void button_listen (int pin); //Número máximo de botões: 13
void timer_set (int timerNumber, int ms); //Número máximo de timers: 2

/* Callbacks que devem ser escritas pelo usuário da API*/
void initialize();
void button_changed (int pin, int v); // notifica que “pin” mudou para “v”
void timer_expired (int timerNumber);


#endif
