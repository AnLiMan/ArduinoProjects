#define LED 9 //Пин светодиода
#define PhotoResistor A0 //Пин фоторезистора
int MinLight = 120; // Минимальное ожидаемое значение освещённости
int Max_Light = 1000; // Максимальное ожидаемое значение освещённости
int val = 0; // Переменная хранения значения аналогового значения

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(PhotoResistor); // Счиатем значение с делителя напряжения
  val = map(val, MinLight, Max_Light, 0, 255); // Масштабируем входной сигнал
  Serial.println(val); // Выводим значение
  analogWrite(LED, val); // Выводим значение на светодиод
}
