#include <Servo.h> //Библиотека управления сервоприводами 

#define SERVO 9 // Сервопривод
#define POT A0 // Потенциометр

Servo myServo; // Объявляем переменную myServo как сервопривод
int val = 0; // Хранение значения потенциометра

void setup() {
  myServo.attach(SERVO); //Подключаем объект сервопривода
}

void loop() {
  val = analogRead(POT);
  val = map(val, 0, 1023, 0, 179); // Масштабируем сигнал с потенциометра в угол поворота сервопривода
  myServo.write(val); // Задаем положение приводу
  delay(15);
}
