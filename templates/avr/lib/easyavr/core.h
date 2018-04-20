#ifndef CORE
#define CORE
#define OUTPUT 0
#define INPUT 1
#define FALSE 0
#define TRUE 1

#include <avr/io.h>

int *getPort(int pin);
int *getDDPort(int pin);
void setPin(int pin, int state);
void pinOn(int pin);
void pinOff(int pin);
void togglePin(int pin);

int readDPin(int pin);


#endif
