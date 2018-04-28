// #define POLOLU
#define NUM_STEPPERS 1

#include "./lib/AVRDuino/A4988.h"
#include "./lib/AVRDuino/A4988_interrups.h"
#include "./lib/AVRDuino/core.h"
#include <util/delay.h>
#define FALSE 0
#define TRUE 1

int main(void) {
  setPin(13, OUTPUT);
  while (1) {
    /* code */
    togglePin(13);
    _delay_ms(500);
  }
}

