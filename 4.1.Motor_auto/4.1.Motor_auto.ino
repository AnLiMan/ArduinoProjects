#define MOTOR 9 //Пин двигателя

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  //Плавный разгон
  for (int i = 0; i < 256 : i++) {
    analogWrite(MOTOR, i);
    delay(10);
  }
  delay(2000);
  
  //Плавное торможение
  for (int i = 255; i >= 0 : i--) {
    analogWrite(MOTOR, i);
    delay(10);
  }
  delay(2000);
}
