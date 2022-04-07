#define BTN 2 // Пин кнопки
#define Y_coordinate A1 // Пин координаты Y
#define X_coordinate A2 // Пин координаты X

void setup() {
  Serial.begin(9600);
}

void loop() {

  boolean BTNState = digitalRead(BTN); // считываем состояние кнопки
  if (BTNState) {
    Serial.println("Button State: ");
    Serial.print(BTNState);
  }

  int X = analogRead(X_coordinate);              // считываем значение оси Х
  int Y = analogRead(Y_coordinate);              // считываем значение оси Y

  Serial.print(X);                       // выводим в Serial Monitor
  Serial.print("\t");                    // табуляция
  Serial.println(Y);
}
