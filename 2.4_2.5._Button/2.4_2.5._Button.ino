#define Butt1  11 //Пин кнопки 1
#define Butt2  12 //Пин кнопки 2

bool flag1 = false; //Флаг нажатия кнопки 1
bool flag2 = false; //Флаг нажатия кнопки 2

void setup() {
  pinMode(Butt1, INPUT);
  pinMode(Butt2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Считываем  значение состояния кнопки 1 с обычной подтяжкой
  bool btn1State = digitalRead(Butt1);
  // Считываем интертированое (для удобства) значение состояния кнопки 2 с внутренней подтяжкой
  bool btn2State = !digitalRead(Butt2);

  // Обработка первой кнопки, с устранением дребезга контактов
  if (btn1State && !flag1)
  {
    flag1 = true;
    Serial.println("Butt 1 press");
  }
  if (!btn1State && flag1)
  {
    flag1 = false;
    Serial.println("Butt 1 release");
  }

  // Обработка второй кнопки, с устранением дребезга контактов
  if (btn2State && !flag2)
  {
    flag2 = true;
    Serial.println("Butt 2 press");
  }
  if (!btn2State && flag2)
  {
    flag2 = false;
    Serial.println("Butt 2 release");
  }
}
