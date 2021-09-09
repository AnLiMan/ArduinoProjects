#define EN 9 // Вход включения электродвигателя EN
#define MC1 3 // Вход 1 управления электродвигателем
#define MC2 2 // Вход 2 управления электродвигателем
#define POT  A0 // Вход потенциометра

int val = 0; // Переменная хранения значения потенциометра
int velocity = 0; // Переменная для хранения желаемой скорости

void setup() {
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  brake(); // Инициализация выполняется с остановленным электродвигателем
}

void loop() {
  val = analogRead(POT); //Считаем значение с потенциометра

  //Вращение вперёп
  if (val > 562) {
    velocity = map(val, 563, 1023, 0, 255);
    forward(velocity);
  }

  //Вращение назад
  else if (val < 462) {
    velocity = map(val, 461, 0, 0, 255);
    reverse(velocity);
  }

  //Торможение
  else () {
    brake();
  }
}

//Функция вращения вперёд с заданной скоростью
void forward(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  analogWrite(EN, rate);
}

//Функция вращения назад с заданной скоростью
void reverse(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  analogWrite(EN, rate);
}

//Функция торможения
void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  digitalWrite(EN, HIGH);
}
