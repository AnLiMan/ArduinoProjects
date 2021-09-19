#define BUTTON 2 // Пин кнопки

#define RED 11 // Катод красного светодиода
#define GREEN 10 // Катод зелёного светодиода
#define BLUE 9 // Катод синего светодиода

//Объявляем переменную типа volatile для возможности использования в функции прерывания
volatile int selectedLED = RED;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //Выключаем светодиоды (сигнал инвертирован, поскольку мы управляем катодами)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  pinMode(BUTTON, INPUT_PULLUP); //Использем внутреннюю подтяжку кнопки
  //Подключаем прерывание по нажатию кнопки с выполнением функции swap()
  attachInterrupt(digitalPinToInterrupt(BUTTON), swap, FALLING);
}

void loop() {
  //Постепенно повышаем яркость светодиода
  for (int i = 255; i >= 0; i--) {
    analogWrite(selectedLED, i);
    delay(10);
  }

  //Постепенно понижаем яркость светодиода
  for (int i = 0; i < 255; i++) {
    analogWrite(selectedLED, i);
    delay(10);
  }
  delay(1000);
}

void swap {
  digitalWrite(selectedLED, HIGH);   //Выключаем текущий светодиод
  //Включаем следующие
  if (selectedLED == GREEN) {
    selectedLED = RED;
  }

  else if (selectedLED == RED) {
    selectedLED = BLUE;
  }

  else if (selectedLED == BLUE) {
    selectedLED = GREEN;
  }
}
