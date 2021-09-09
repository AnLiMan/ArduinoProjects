#define LED_BLUE 9 //Пин катода синего светодиода
#define LED_GREEN 10 //Пин катода зелёного светодиода
#define LED_RED 11 //Пин катода красного светодиода

#define BUTT  2 //Пин кнопки 
bool flag = false; //Флаг нажатия кнопки
byte ModeNumber = 0;

void setup() {
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUTT, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Считываем интертированое (для удобства) значение состояния кнопки с внутренней подтяжкой
  bool btnState = !digitalRead(BUTT);

  // Обработка  кнопки, с устранением дребезга контактов
  if (btnState && !flag)
  {
    flag = true;
    ModeNumber++;
    //Закольцуем режиы
    if (ModeNumber > 7) {
      ModeNumber = 0;
    }
    Serial.println(ModeNumber);
  }
  if (!btnState && flag)
  {
    flag = false;
  }
  // Управление режимами цвета
  switch (ModeNumber) {
    case 0: //
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      break;
    case 1: // Красный
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_BLUE, HIGH);
      break;
    case 2: // Зелёный
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, HIGH);
      break;
    case 3: // Синий
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_BLUE, LOW);
      break;
    case 4: // Фиолетовый (Красный + Синий)
      analogWrite(LED_RED, 127);
      analogWrite(LED_GREEN, 255);
      analogWrite(LED_BLUE, 127);
      break;
    case 5: // Зеленовато-голубой
      analogWrite(LED_RED, 255);
      analogWrite(LED_GREEN, 127);
      analogWrite(LED_BLUE, 127);
      break;
    case 6: // Оранжевый
      analogWrite(LED_RED, 127);
      analogWrite(LED_GREEN, 127);
      analogWrite(LED_BLUE, 255);
      break;
    case 7: // Белый
      analogWrite(LED_RED, 170);
      analogWrite(LED_GREEN, 170);
      analogWrite(LED_BLUE, 170);
      break;
  }
}
