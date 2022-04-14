#include <Stepper.h> // Шаговые электродвигатели 28BYJ-48 в режиме полного шага делают 
//за один полный оборот вала 2048 шагов
const int STEPS_PER_REV = 2048; // 2048 шагов на оборот
// Создаем экземпляр класса Stepper и указываем количество шагов и контакты для подключения
Stepper myStepper(STEPS_PER_REV, 2, 3, 4, 5);

#define START  7 // Кнопка Start
#define STOP_Butt  12 // Кнопка Stop

bool flag1 = false; //Флаг нажатия кнопки 1
bool flag2 = false; //Флаг нажатия кнопки 2

void setup() {
  myStepper.setSpeed(8); // Устанавливаем скорость вращения в об./мин
  pinMode(START, INPUT_PULLUP);
  pinMode(STOP_Butt, INPUT_PULLUP);
}
void loop() {
  // Считываем  значение состояния кнопки 1 с обычной подтяжкой
  bool btn1State = !digitalRead(START);
  // Считываем интертированое (для удобства) значение состояния кнопки 2 с внутренней подтяжкой
  bool btn2State = !digitalRead(STOP_Butt);

  if (btn1State)
  {
    flag1 = true;
    myStepper.step(STEPS_PER_REV); // Поворот вала на один шаг в одном направлении
    delay(500);
  }

  if (btn2State)
  {
    flag2 = true;
    myStepper.step(-STEPS_PER_REV); // Поворот вала на один шаг в одном направлении
    delay(500);
  }
}
