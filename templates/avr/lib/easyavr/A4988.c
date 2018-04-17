#include "A4988.h"
// #define MANSET
// #define SETPOL

#ifdef MANSET
void setPololu(pololu *drive, int dir, int step, int enable, int MS1, int MS2,
               int MS3, double degrees_per_step, int RPM) {
  drive->dir = dir;
  drive->step = step;
  drive->enable = enable;
  drive->MS1 = MS1;
  drive->MS2 = MS2;
  drive->MS3 = MS3;
  drive->degrees_per_step = degrees_per_step;
  drive->RPM = RPM;
  setPin(dir, OUTPUT);
  setPin(step, OUTPUT);
  setPin(enable, OUTPUT);
  setPin(MS1, OUTPUT);
  setPin(MS2, OUTPUT);
  setPin(MS3, OUTPUT);
}

A4988 newPololu(int dir, int step, int enable, int MS1, int MS2, int MS3,
                double degrees_per_step, int RPM) {
  pololu drive;
  drive.dir = dir;
  drive.step = step;
  drive.enable = enable;
  drive.MS1 = MS1;
  drive.MS2 = MS2;
  drive.MS3 = MS3;
  drive.degrees_per_step = degrees_per_step;
  drive.RPM = RPM;
  setPin(dir, OUTPUT);
  setPin(step, OUTPUT);
  setPin(enable, OUTPUT);
  setPin(MS1, OUTPUT);
  setPin(MS2, OUTPUT);
  setPin(MS3, OUTPUT);
  return drive;
}
#endif

#ifdef SETPOL
void setPololuFA(pololu *drive, DriveArray array) {
  drive->dir = (int)array[0];
  drive->step = (int)array[1];
  drive->enable = (int)array[2];
  drive->MS1 = (int)array[3];
  drive->MS2 = (int)array[4];
  drive->MS3 = (int)array[5];
  drive->degrees_per_step = array[6];
  drive->RPM = (int)array[7];

  for (uint8_t i = 0; i < 6; i++) {
    setPin((int)array[i], OUTPUT);
  }
}
#endif

A4988 newPololuFA(DriveArray array) {
  pololu drive;
  drive.dir = (int)array[0];
  drive.step = (int)array[1];
  drive.enable = (int)array[2];
  drive.MS1 = (int)array[3];
  drive.MS2 = (int)array[4];
  drive.MS3 = (int)array[5];
  drive.degrees_per_step = array[6];
  drive.RPM = (int)array[7];

  for (uint8_t i = 0; i < 3; i++) {
    setPin((int)array[i], OUTPUT);
  }

  return drive;
}

void setSpeed(int speed, STEPPER *drive) { drive->motor->RPM = speed; };

void rotateNSteps(int n, STEPPER *drive, int dir) {
  drive->motor->stepps = n;
  pinOn(drive->motor->enable);
  drive->enabled = TRUE;
  if (dir) {
    drive->motor->direction = FORWARD;
    pinOn(drive->motor->dir);
  } else {
    drive->motor->direction = BACKWARD;
    pinOff(drive->motor->dir);
  }
}
