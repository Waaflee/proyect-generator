#include "command_interpreter.h"

void checkData(char data[]) {
  char temp[10];
  uint16_t arg;
  uint8_t select;

  if (UARTcount > 2) {
    for (size_t i = 4; i < UARTcount; i++) {
      temp[i - 4] = data[i];
    }
    arg = atoi(temp);
  }
  if (UARTcount > 2) {
    select = atoi(&data[3]);
  }

  switch (data[1]) {
  case 'F':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Fn:nnn\t:Forward<motor>:<stepps>\n");
    } else {
      rotateNSteps(arg, PAParray[select], FORWARD);
    }
    break;
  case 'B':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Bn:nnn\t:Backward<motor>:<stepps>\n");
    } else {
      rotateNSteps(arg, PAParray[select], BACKWARD);
    }
    break;
  case 'S':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Sn:nnn\t:Speed<motor>:<RPM>\n");
    } else {
      setSpeed(arg, PAParray[select]);
    }
    break;
  case 'P':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Pn:nnn\t:Absolute Position<motor>:<position>\n");
    } else {
      goToabs(arg, PAParray[select]);
    }
    break;
  case 'R':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Rn:nnn\t:Relative Position<motor>:<percentage>\n");
    } else {
      goTorel(arg, PAParray[select]);
    }
    break;
  case 'H':
    printf("Starting all-engine referentiaton protocol\n");
    PAPsInit(5);
    break;
  case 'W':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Fn:nnn\t:Forward<motor>:<stepps>\n");
    } else {
      stopPololu(PAParray[select]);
    }
    break;
  case 'D':
    if (UARTcount < 3) {
      printf("Not enough arguments\n");
      printf("Usage:\n");
      printf("->\t:Dn\t:Diagnosic<motor> Shows current position & speed of "
             "selected engine\n");
    } else {
      printf("Diagnostico motor[%d]\n", select);
      printf("->\tPosicion actual = %d\n", PAParray[select]->motor->location);
      printf("->\tVelocidad actual = %d\n", PAParray[select]->motor->RPM);
    }
    break;
  case 'h':
    help();
    break;
  default:
    printf("Command not Found \"%s\"\n", data);
    printf("Use :h for help\n");
    break;
  }
}

void help() {
  printf("Usage:\n");
  printf("->\t:Fn:nnn\t:Forward<motor>:<stepps>\n");
  printf("->\t:Bn:nnn\t:Backward<motor>:<stepps>\n");
  printf("->\t:Sn:nnn\t:Speed<motor>:<RPM>\n");
  printf("->\t:Pn:nnn\t:Absolute Position<motor>:<position>\n");
  printf("->\t:Rn:nnn\t:Relative Position<motor>:<percentage>\n");
  printf("->\t:H\t:Homming Routine\n");
  printf("->\t:Dn\t:Diagnosic<motor> Shows current position & speed of "
         "selected engine\n");
  printf("->\t:h\t:Shows this help message\n");
};
