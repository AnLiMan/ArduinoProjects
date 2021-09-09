#define RIGHT_EN 9 // Вход включения электродвигателя EN1 (правого)
#define RIGHT_MC1 2 // Вход 1 управления электродвигателем
#define RIGHT_MC2 3 // Вход 2 управления электродвигателем

#define LEFT_EN 10 // Вход включения электродвигателя EN2 (левого)
#define LEFT_MC1 4 // Вход 3 управления электродвигателем
#define LEFT_MC2 5 // Вход 4 управления электродвигателем

#define LEFT_LIGHT_RESISTOR A0 // Пин левого фоторезистора
#define RIGHT_LIGHT_RESISTOR A1 // Пин левого фоторезистора

int LIGHT_THRESHOLD_MIN = 810; //Минимальный уровень освещения для начала движения
int LIGHT_THRESHOLD_MAX = 1100; //Максимальный уровень освещения для начала движения
int SPEED_MIN = 150; // Минимальная скорость вращения двигателя
int SPEED_MAX = 255; // Максимальная скорость вращения двигателя

void setup() {
  pinMode(RIGHT_EN, OUTPUT);
  pinMode(RIGHT_MC1, OUTPUT);
  pinMode(RIGHT_MC2, OUTPUT);
  
  pinMode(LEFT_EN, OUTPUT);
  pinMode(LEFT_MC1, OUTPUT);
  pinMode(LEFT_MC2, OUTPUT);

  //Остановим двигатели
  brake("left");
  brake("right");
  Serial.begin(9600); //Откроем последовательный порт для калибровки уровней освещения
}

void loop() {
  int left_light = analogRead(LEFT_LIGHT_RESISTOR);
  int right_light = analogRead(RIGHT_LIGHT_RESISTOR);
  delay(50); // Небольшая пауза, чтобы обеспечить считывание последовательного вывода
  /*
    Для каждого фоторезистора задаём пропорционально скорость вращения противоположного двигателя.
    Не включаем противоположный двигатель ниже минимального значения освещения. Левый датчик управляет
    скоростью правого электродвигателя и наоборот. тобы повернуть влево, нужно ускорить вращение правого электродвигателя и наоборот.
  */
  Serial.print("Right: ");
  Serial.print(right_light);
  Serial.print("");

  if (right_light >= LIGHT_THRESHOLD_MIN) {
    int left_speed = map(right_light, LIGHT_THRESHOLD_MIN, LIGHT_THRESHOLD_MAX, SPEED_MIN, SPEED_MAX); //Состовляем уровень освещённости со значением скорости
    left_speed = constrain(left_speed, SPEED_MIN, SPEED_MAX); // Устанавливаем предел на скорость
    Serial.print(left_speed); //Отображаем на экране скорость вращения
    forward("left", left_speed); //Вращаем противоположный двигатель с вычисленной скоростью
  }
  // Если освещённость ниже минимальной, тормозим противоположный двигатель
  else {
    Serial.print("0");
    brake("left");
  }

  Serial.print("\tLeft: ");
  Serial.print(left_light);
  Serial.print("");

  if (left_light >= LIGHT_THRESHOLD_MIN) {
    int right_speed = map(left_light, LIGHT_THRESHOLD_MIN, LIGHT_THRESHOLD_MAX, SPEED_MIN, SPEED_MAX); //Состовляем уровень освещённости со значением скорости
    right_speed = constrain(right_speed, SPEED_MIN, SPEED_MAX); // Устанавливаем предел на скорость
    Serial.print(right_speed); //Отображаем на экране скорость вращения
    forward("right", right_speed); //Вращаем противоположный двигатель с вычисленной скоростью
  }
  // Если освещённость ниже минимальной, тормозим противоположный двигатель
  else {
    Serial.print("0");
    brake("right");
  }
}

/* Функция вращения вперёд сзаданной скоростью (от 0 до 255)
  двигатель может быть "left" (левый) или "right" (правый)
*/

void forward(String motor, int rate) {
  if (motor == "left") {
    digitalWrite(LEFT_EN, LOW);
    digitalWrite(LEFT_MC1, HIGH);
    digitalWrite(LEFT_MC2, LOW);
    analogWrite(LEFT_EN, rate);
  }
  else if (motor == "right") {
    digitalWrite(RIGHT_EN, LOW);
    digitalWrite(RIGHT_MC1, HIGH);
    digitalWrite(RIGHT_MC1, LOW);
    analogWrite(RIGHT_EN, rate);
  }
}

//Функция торможения электродвигателя
void brake(String motor) {
  if (motor == "left") {
    digitalWrite(LEFT_EN, LOW);
    digitalWrite(LEFT_MC1, LOW);
    digitalWrite(LEFT_MC2, LOW);
    analogWrite(LEFT_EN, HIGH);
  }

    else if (motor == "right") {
    digitalWrite(RIGHT_EN, LOW);
    digitalWrite(RIGHT_MC1, LOW);
    digitalWrite(RIGHT_MC1, LOW);
    analogWrite(RIGHT_EN, HIGH);
  }
}
