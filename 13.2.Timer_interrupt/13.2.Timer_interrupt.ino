#include<TimerOne.h> //При использовании этой библиотеки исключается возможность использовать analogWrite() на пинах 9 10
#define LED 13 // Пин светодиода 1
#define LED2 6 // Пин светодиода 1

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  Timer1.initialize(100000); //Устанавливаем период таймера на 1000000 мкс = 1с
  Timer1.attachInterrupt(blinky);
}

void loop() {
  delay(1000);
  digitalWrite(LED2, !digitalRead(LED2)); //Переключаем состояние светодиода
}

void blinky () {
  digitalWrite(LED, !digitalRead(LED)); //Переключаем состояние светодиода
}
