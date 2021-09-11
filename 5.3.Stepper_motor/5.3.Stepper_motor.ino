#include <Stepper.h. //Библиотека шагового двигателя
const int STEPS_PER_REV = 200; //200 шагов на оборот

#define COIL1_MC1 2 // Контакт для управления переключателем 1 фазы 1
#define COIL1_MC2 3 // Контакт для управления переключателем 1 фазы 2
#define COIL2_MC1 4 // Контакт для управления переключателем 1 фазы 1
#define COIL2_MC2 5 // Контакт для управления переключателем 1 фазы 2

Stepper myStepper(STEPS_PER_REV, COIL1_MC1, COIL1_MC2, COIL2_MC1, COIL2_MC2);

void setup() {
  myStepper.setSpeed(60); //Устанавливаем скорость шагового двигателя 60 об/мин
}

void loop() {
  myStepper.step(STEPS_PER_REV); // Один пошаговый оборот вала в одном направлении
  delay(500);
  myStepper.step(-STEPS_PER_REV); // Один пошаговый оборот вала в обратном направлении
  delay(500);
}
