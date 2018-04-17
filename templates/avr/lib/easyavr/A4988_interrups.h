#ifndef A49INTERRUPS
#define A49INTERRUPS
#include "core.h"
#include <avr/interrupt.h>

enum t0_prescaler
{
    T0_PRESCALER_1 = _BV(CS00),
    T0_PRESCALER_8 = _BV(CS01),
    T0_PRESCALER_64 = _BV(CS00) | _BV(CS01),
    T0_PRESCALER_256 = _BV(CS02),
    T0_PRESCALER_1024 = _BV(CS02) | _BV(CS00),
};

void setTimer0(enum t0_prescaler PS);
void setTimer0PS(enum t0_prescaler ps);



#endif
