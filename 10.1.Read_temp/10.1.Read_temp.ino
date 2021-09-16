//Чтение температуры из I2C-датчика и вывод значений в последовательный порт
#include <Wire.h> //Подключение библиотеки Wire 
int temp_address = 72; //Запись адреса 1001000

void setup()
{
Serial.begin(9600); //Запуск последовательного порта на скорости 9600 бод
Wire.begin(); //Создание объекта Wire
}
void loop()
{
// Отправка запроса

Wire.beginTransmission(temp_address); // Выбор устройства отправкой адреса устройства
Wire.write(0); // Установка бита asking в 0 для чтения
Wire.endTransmission(); //Отправка стоп-бита

//Чтение температуры из устройства
Wire.requestFrom(temp_address, 1); //Получить 1 байт по адресу устройства
while(Wire.available() == 0); //Ожидание ответа
int c = Wire.read(); //Чтение данных в переменную
int f = round(c*9.0/5.0 +32.0); //Перевод данных из шкалы Цельсия в шкалу Фаренгейта

//Отправка значения в градусах Цельсия и Фаренгейта в последовательный порт
Serial.print(c);
Serial.print("C ");
Serial.print(f);
Serial.println("F");
delay(500);
}
