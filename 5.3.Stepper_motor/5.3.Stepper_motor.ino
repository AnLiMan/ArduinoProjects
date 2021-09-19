#include <Stepper.h> // Шаговые электродвигатели 28BYJ-48 в режиме полного шага делают за один полный оборот вала 2048 шагов
const int STEPS_PER_REV = 2048; // 2048 шагов на оборот
// Создаем экземпляр класса Stepper и указываем количество шагов и контакты для подключения
Stepper myStepper(STEPS_PER_REV, 2, 3, 4, 5);

void setup() {
  myStepper.setSpeed(1); // Устанавливаем скорость вращения в об./мин
}
void loop() {
  myStepper.step(STEPS_PER_REV); // Поворот вала на один шаг в одном направлении
  delay(500);
  myStepper.step(-STEPS_PER_REV); // Поворот вала на один шаг в другом направлении
  delay(500);
}
