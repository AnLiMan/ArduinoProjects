#define LED 9 //Пин светодиода
char data; //ПЕременная для хранения получаемого символа

void setup() {
  Serial.begin(9600); //Запускаем последовательный порт, скорость 9600 бод
  pinMode(LED, OUTPUT);
}

void loop() {
  //Предпринимаем действие только при наличии данных в буфере

  if (Serial.available() > 0) {
    data = Serial.read();
    //Если отправили единицу, то включаем светодиод
    if (data == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("LED On");
    }
    //Если отправили ноль, то выключаем светодиод
    else if (data == '0') {
      digitalWrite(LED, LOW);
      Serial.println("LED Off");
    }
  }
}
