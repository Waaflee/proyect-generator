#include "core.h"
#define DIGITAL
//#define ANALOG

#ifdef DIGITAL
// int pinout[] = {DDD0, DDD1, DDD2, DDD3, DDD4, DDD5, DDD6,
//                 DDD7, DDB0, DDB1, DDB2, DDB3, DDB4, DDB5};
//
// int pinD[] = {PORTD0, PORTD1, PORTD2, PORTD3, PORTD4, PORTD5, PORTD6,
//               PORTD7, PORTB0, PORTB1, PORTB2, PORTB3, PORTB4, PORTB5};

int pinout[] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5};
int pinD[] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5};

int *getPort(int pin) {
  if (pin <= 7) {
    return (int *)&PORTD;
  } else {
    return (int *)&PORTB;
  }
}

int *getDDPort(int pin) {
  if (pin <= 7) {
    return (int *)&DDRD;
  } else {
    return (int *)&DDRB;
  }
}

void setPin(int pin, int state) {
  int *port = getDDPort(pin);
  if (!state) {
    *port |= _BV(pinout[pin]);
  } else {
    *port &= ~_BV(pinout[pin]);
  }
}

void pinOn(int pin) {
  int *puerto = getPort(pin);
  *puerto |= _BV(pinD[pin]);
}

void pinOff(int pin) {
  int *puerto = getPort(pin);
  *puerto &= ~_BV(pinD[pin]);
}

void togglePin(int pin) {
  int *puerto = getPort(pin);
  *puerto ^= _BV(pinD[pin]);
}

int readDPin(int pin) {
  int *Port = pin <= 7 ? (int *)&PIND : (int *)&PINB;
  if (*Port & _BV(pinIn[pin])) {
    return 1;
  } else {
    return 0;
  }
}


#endif

#ifdef ANALOG
// int pinA[] = {PORTC0, PORTC1, PORTC2, PORTC3, PORTC4, PORTC5};
#endif
