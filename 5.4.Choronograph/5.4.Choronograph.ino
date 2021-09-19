#include <Stepper.h> // Шаговые электродвигатели 28BYJ-48 в режиме полного шага делают за один полный оборот вала 2048 шагов
const int STEPS_PER_REV = 2048; // 2048 шага/оборот
/* Чтобы выполнить один оборот вала за одну минуту,
  // вычисляем количество миллисекунд на каждый шаг:
  60 секунд * 1000 мс / 2048 шагов = 30 мс/шаг */
const int MS_PER_STEP = 30;

// Контакты для управления драйвером ULN2003
#define COIL1_MC1  2 // Контакт Arduino для подключения к контакту IN1
#define COIL1_MC2  3 // Контакт Arduino для подключения к контакту IN2
#define COIL2_MC1  4 // Контакт Arduino для подключения к контакту IN3
#define COIL2_MC2  5 // Контакт Arduino для подключения к контакту IN3

// Контакты Arduino для считывания сигнала с кнопок
#define START  8 // Кнопка Start
#define STOP  9 // Кнопка Stop

// Переменные для отслеживания
unsigned long last_time = 0;
unsigned long curr_time = 0;
int steps_taken = 0;

// Инициализируем библиотеку Servo.h — передаем ей контакты Arduino для управления переключателями Н-моста
Stepper chronograph(STEPS_PER_REV, COIL1_MC1, COIL1_MC2, COIL2_MC1, COIL2_MC2);

void setup()
{
  // Задаем высокую скорость вращения вала шагового двигателя для быстрого выполнения каждого шага
  chronograph.setSpeed(1); // Включаем встроенные повышающие резисторы для контактов

  // для снятия сигнала кнопок
  pinMode(START, INPUT_PULLUP);
  pinMode(STOP, INPUT_PULLUP);
}
void loop()
{
  /* Выполняем цикл, ожидая нажатия кнопки запуска Start
    Оператор цикла задерживает ход исполнения
    в этом месте, пока удовлетворяется указанное условие. */
  while (digitalRead(START) == HIGH);
  last_time = millis(); // Получаем время при запуске
  
  // Исполняем этот цикл, пока не истечет одна минута или не будет нажата кнопка Stop
  while (digitalRead(STOP) == HIGH && steps_taken < STEPS_PER_REV)
  {
    curr_time = millis();
    
    if (curr_time - last_time >= MS_PER_STEP) // Если прошло 300 мс, вращаем вал на один шаг
    {
      chronograph.step(1); // Вращаем вал на одни шаг
      steps_taken++; // Инкрементируем переменную счетчика шагов steps_taken
      last_time = curr_time; // Обновляем переменную last_time текущим временем
    }
  }
  /* Если мы в этой точке, значит, была нажата кнопка Stop или истекла одна минута
  Если не выполнен полный оборот, возвращаем стрелку в исходную точку. */
  if (steps_taken < STEPS_PER_REV) chronograph.step(-steps_taken);
  steps_taken = 0; // Сброс счетчика шагов
}
