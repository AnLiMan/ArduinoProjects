#define LED_BLUE 9 //Пин катода синего светодиода
#define LED_GREEN 10 //Пин катода зелёного светодиода
#define LED_RED 11 //Пин катода красного светодиода

#define TEMP A0 // Подключаем вывод датчика температуры к контакту 
int LOWER_BOUND = 139; // Нижнее пороговое значение
int UPPER_BOUND = 147; // Верхнее пороговое значение
int val = 0; // Переменная для хранения аналогового значения

void setup() {
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(9600); //Откроем последовательный порт для общения с микроконтроллером
}

void loop() {
  val = analogRead(TEMP);
  Serial.println(val);
  // Синий
  if (val < LOWER_BOUND) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, LOW);
  }
  // Красный
  if (val > UPPER_BOUND) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
  }
  //Зелёный
  else {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_BLUE, HIGH);
  }
}
