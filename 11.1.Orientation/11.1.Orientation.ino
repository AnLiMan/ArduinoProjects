#include <SPI.h>

// Определяем назначение контактов платы Arduino для светодиодов
#define RED_PIN  6;
#define GREEN_PIN  5
#define CS_Pin  10

/* Контакты Arduino аппаратного интерфейса SPI
  заданы по умолчанию
  pin 11 as MOSI (SDI),
  pin 12 as MISO (SDO) ,
  pin 13 as clock (SPC)
  Определение скорости, порядка отправки битов информации и режима передачи данных */

SPISettings settingsA(2000000, MSBFIRST, SPI_MODE3);
int x, y, z;
float K = 0.061; // (4000/65535) милли-g на единицу для полного диапазона +/-2g с использованием цифрового выхода 16 bit

void setup() {
  Serial.begin(9600);
  pinMode (CS_Pin, OUTPUT); // Выбор ведомого устройства (регистра) SPI
  digitalWrite(CS_Pin, HIGH); // Конец передачи по шине SPI
  SPI.begin(); // Инициализация интерфейса SPI
  SPI.beginTransaction(settingsA);
  digitalWrite(CS_Pin, LOW); // Начало передачи данных по шине SPI
  SPI.transfer(0x20); // Обращение к регистру 'Control register 4'
  SPI.transfer(0x7F); // Настройка его для записи значений x, y, z акселерометра
  digitalWrite(CS_Pin, HIGH); // Конец передачи по шине SPI
  // Задаем выходной режим работы для контактов светодиодов
  pinMode(RED_PIN, OUTPUT);
  digitalWrite(RED_PIN, HIGH);
  pinMode(GREEN_PIN, OUTPUT);
  digitalWrite(GREEN_PIN, HIGH);
}

void loop() {
  delay(1000);
  digitalWrite(CS_Pin, LOW); // Начало передачи данных по шине SPI
  SPI.transfer(0xA8); // Принимаем байт по шине SPI
  x = SPI.transfer(0) | SPI.transfer(0) << 8; // x acceleration
  y = SPI.transfer(0) | SPI.transfer(0) << 8; // y acceleration
  z = SPI.transfer(0) | SPI.transfer(0) << 8; // z acceleration
  digitalWrite(CS_Pin, HIGH); // Конец передачи по шине SPI
  Serial.println("x=" + String(K * x) + " mg \ty=" + String(K * y) + " mg \tz=" + String(K * z) + " mg");

  // Проверяем, "вверх ногами" устройство или нет
  if (z < 0) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  }
  else {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  }
  // Получаем новые данные каждые 100 мс
  delay(100);
}
