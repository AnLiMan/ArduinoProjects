#define POT A0 //Пин потенциометра

void setup() {
  Serial.begin(9600); //Запускаем последовательный порт, скорость 9600 бод
}

void loop() {
  Serial.println("\nAnalog Pin \tRaw Value \tPercentage"); // \n - новая строка, \t - табуляция
  Serial.println("-------------------------------");

  for (int i = 0; i < 10; i++) {
    int val = analogRead(POT); //Считывание аналогового сигнала
    int per = map(val, 0, 1023, 0, 100); //Масштабируем значение с потенциометра
    Serial.print("A0\t\t"); //Выводим текст "А0" и вставляем табуляцию дважды
    Serial.print("\t\t"); //Вставляем табуляцию дважды
    Serial.print(per); //Выводим на экран аналоговое значение в процентах
    Serial.println("%"); // Отображаем символ
    delay(500); //Ждём полсекунды
  }

}
