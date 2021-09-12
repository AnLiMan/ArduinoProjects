#define LED1  A5 //Пин светодиода 1

void setup() {
  pinMode(LED1, OUTPUT); // Настройка пинов на выход
  Serial.begin(9600); //Откроем последовательный порт для общения Arduino с компьютером
}

void loop() {
  for (byte i = 0; i <= 255; i++) {
    analogWrite(LED1, i); // Генерирование скважности на уровне текущей градации
    Serial.println(i);
    delay(75);
  }
}
