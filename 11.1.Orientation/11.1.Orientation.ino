#include <Adafruit_LIS3DH.h> //Библиотека акселерометра

#define RED 6 //Пин  красного светодиода
#define GREEN 5 //Пин  зелёного светодиода
#define CS_PIN 10 //Пин  акселерометра 

Adafruit_LIS3DH accel = Adafruit_LIS3DH(CS_PIN); //Конфигурируем аккселерометр через аппаратный интерфейс SPI

void setup () {
  Serial.begin(9600); //Открываем последовательный порт
  
  //Подключаемся к акселерометру
  if (!accel.begin()) {
    Serial.println("Accel not a found");
    while (1); //Входим в бесконечный цикл
  }

  accel.setRange(LIS3DH_RANGE_2_G);

  pinMode(RED, OUTPUT);  // Настройка пина на выход
  pinMode(GREEN, OUTPUT);  // Настройка пина на выход
  digitalWrite(RED, HIGH);   //Устанавливаем пин на высокое напряжение
  digitalWrite(GREEN, HIGH);   //Устанавливаем пин на высокое напряжение
}

void loop() {
  accel.read(); //Получаем значения ускорения по осям X,Y,Z
  //Выводим в монитор порта исходное значение показания по оси Z
  Serial.print("Raw: ");
  Serial.print(accel.z);

  //Сопостовляем исходное значение ускорения по оси Z значение в диапазоне +-2g
  Serial.print("\Actual: ");
  Serial.print((float(accel.z) / 32768.0) * 2.0);
  Serial.println("G");

  //Если устройство вверх ногами
  if (accel.z < 0 ) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
  //Если нет
  else {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
  }
  delay(100); // Ждём 100 мс
}
