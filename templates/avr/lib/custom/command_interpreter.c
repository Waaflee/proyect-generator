#include "command_interpreter.h"

void checkData(char data[]) {
  char temp[15];
  int rotation;
  uint8_t direction;
  int speed;
  int coord;
  // printf("%s %s\n", "data: ", UARTData);
  switch (data[0]) {
  case 'r':
    direction = data[2] == 'f' ? FORWARD : BACKWARD;
    for (uint8_t i = 4; i < UARTcount; i++) {
      temp[i - 4] = data[i];
    }
    rotation = atoi(temp);
    rotateNSteps(rotation, PAParray[atoi(&data[1])], direction);
    break;
  case 's':
    for (uint8_t i = 4; i < UARTcount; i++) {
      temp[i - 4] = data[i];
    }
    speed = atoi(temp);
    setSpeed(speed, PAParray[atoi(&data[1])]);
    break;
  case 'b':
    stopPololu(PAParray[atoi(&data[1])]);
    break;
  case 'w':
    printf("PAP[%s] located in: %d\n", &data[1],
           PAParray[atoi(&data[1])]->motor->location);
    break;
  case 'p':
    for (uint8_t i = 4; i < UARTcount; i++) {
      temp[i - 4] = data[i];
    }
    coord = atoi(temp);
    switch (data[2]) {
    case 'r':
      goTorel(coord, PAParray[atoi(&data[1])]);
      break;
    case 'a':
      goToabs(coord, PAParray[atoi(&data[1])]);
      break;
    }
    break;
  }
}
