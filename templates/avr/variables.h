//A4988 congi values, number of simultaneous drivers and amount of stepps for homming
#define POLOLU
#ifdef POLOLU
  #define NUM_STEPPERS 1
  #define INIT_STEPPS 30000
#endif
//Define this if you want uart enabled printf() variable report on certain functions
#ifndef UART
  #define UART
  #define BAUD 57600
  #define UART_DEBBUG
  unsigned short int UARTSetted;
#endif /* end of include guard: UART */
