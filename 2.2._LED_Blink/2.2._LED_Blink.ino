#define LED1 6 //Пин светодиода 1

void setup() {
  pinMode(LED1, OUTPUT);  // Настройка пина на выход
}

void loop() {
  for (int i = 100; i <= 1000; i+=100) {
    digitalWrite(LED1, HIGH);   //Устанавливаем пин на высокое напряжение
    delay(i); // Выставляем паузу по текущему значению
    digitalWrite(LED1, LOW);    //Устанавливаем пин на низкое напряжение
    delay(i);
    
//Зацикливаем
    if (i > 1000) {
      i = 100;
    }
  }
}
