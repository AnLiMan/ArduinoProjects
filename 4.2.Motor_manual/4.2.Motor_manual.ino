#define MOTOR 9 //Пин двигателя
#define POT A0 //Пин потенциометра

int val = 0; // Величина напряжения с потенциометра

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  val = analogRead(POT); //Считаем значение с потенциометра
  // Масштабирование входного значения потенциометра в размеры от 0 до 255
  val = map (val, 0, 1023, 0, 255);
  analogWrite(MOTOR, val);
}
