#ifndef EVENT_DRIVEN
#define EVENT_DRIVEN

/* Funções de registro que estão implementadas em event_driven.c */
void button_listen (int pin);
void timer_set (int timerNumber, int ms);

/* Callbacks que deven ser escritas pelo usuário da API*/
void init();
void button_changed (int pin, int v); // notifica que “pin” mudou para “v”
void timer_expired (int timerNumber);


#endif
