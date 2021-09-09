#define LED 9 //Пин светодиода
#define PhotoResistor A0 //Пин фоторезистора
int MinLight = 200; // Минимальное ожидаемое значение освещённости
int Max_Light = 900; // Максимальное ожидаемое значение освещённости
int val = 0; // Переменная хранения значения аналогового значения

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(PhotoResistor); // Счиатем значение с делителя напряжения
  val = map(val, MinLight, Max_Light, 0, 255); // Масштабируем входной сигнал
  analogWrite(LED, val); // Выводим значение на светодиод
}
