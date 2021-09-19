#include <LiquidCrystal.h> // Подключение библиотеки ЖК-дисплея
#define TEMP_ADDR 72 // Адрес датчика температуры
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Инициализация экземпляра библиотеки LiquidCrystal с номерами шин интерфейса

byte degree[8] {B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000}; //Спец символ градуса
byte fan_on[8] {B00100, B10101, B01110, B11111, B01110, B10101, B00100, B00000}; //Спец символ включения вентилятора
byte fan_off[8] {B00100, B00100, B00100, B11111, B00100, B00100, B00100, B00000}; //Спец символ выключения вентилятора

//Константы для контактов Arduino
#define SPEAKER 8
#define DOWN_BUTTON 9
#define UP_BUTTON 10
#define FAN 11

//Переменные для состояния кнопок
boolean LastDownTempButton = false;
boolean CurrentDownTempButton = false;
boolean LastUpTempButton = false;
boolean CurrentUpTempButton = false;

int set_temp = 23; //Порговое значение температуры по умолчанию
bool one_time = false; //Переменная для подачи звукового сигнала оповещения

void setup() {
  pinMode(FAN, OUTPUT);
  Wire.begin();

  lcd.begin(16, 2); // Настройка экземпляра дисплея - число столбцов и строк:
  lcd.print("My Display"); // Вывод текстового сообщения на экран дисплея

  //Создаём спец символы
  lcd.createChar(0, degree);
  lcd.createChar(1, fan_on);
  lcd.createChar(2, fan_off);

  //Выводим статический текст на ЖКД
  lcd.setCursor(0, 1); // Установить курсор на вторую строку в первую позицию
  lcd.print("Current: "); // Пишем "Current: "

  lcd.setCursor(10, 0); // Установить курсор на первую строку в 11-ю позицию
  lcd.write((byte)0);

  lcd.setCursor(11, 0); // Установить курсор на первую строку в 12-ю позицию
  lcd.print("C"); // Пишем "C"

  lcd.setCursor(0, 1); // Установить курсор на вторую строку в первую позицию
  lcd.print("Set:"); // Пишем "Set:"

  lcd.setCursor(10, 1); // Установить курсор на вторую строку в 11-ю позицию
  lcd.write((byte)0);

  lcd.setCursor(11, 1); // Установить курсор на вторую строку в 12-ю позицию
  lcd.print("C"); // Пишем "C"

  lcd.setCursor(15, 1); // Установить курсор на вторую строку в 16-ю позицию
  lcd.write((byte)0);
}

void loop() {
  Wire.beginTransmission(TEMP_ADDR); //Начинаем взаимодействие с датчиком температуры
  Wire.write(0); // Запрашиваем нулевой оегистр
  Wire.endTransmission(); //Завершаем передачу

  int returned_bytes = Wire.requestFrom(TEMP_ADDR, 1); //Запрашиваем 1 байт

  //Если не возращено никаких данных, выводим сообщение об ошибке
  if (returned_bytes == 0) {
    lcd.clear(); //Очищаем дисплей
    lcd.print()"I2CError"); //Печать отчёта
    while (1); //Переходим в бесконечный цикл
  }

int c = Wire.read(); // Сохраняем значение температуры с переменной "с"
  lcd.setCursor(8, 0); //Перемещаем курсор ЖКД
  lcd.print(c); // Отображаем новое значение

  //Устраняем дребезг контактов на обеих кнопках
  CurrentDownTempButton = debounce(LastDownTempButton, DOWN_BUTTON);
  CurrentUpTempButton = debounce(LastUpTempButton, UP_BUTTON);

  //Если нажали кнопку понижения порогового значения температуры
  if (LastDownTempButton == false && CurrentDownTempButton == HIGH) {
    set_temp--;
  }
  //Если нажали кнопку повышения порогового значения температуры
  if (LastUpTempButton == false && CurrentUpTempButton == HIGH) {
    set_temp++;
  }

  //Выводим пороговое значение температуры на ЖКД
  lcd.setCursor(8, 1); //Перемещаем курсор ЖКД
  lcd.print(set_temp); // ОТображаем новое значение

  //Обновляем значения прошлых значений кнопок
  LastDownTempButton = CurrentDownTempButton;
  LastUpTempButton = CurrentUpTempButton;

  //Если текущая температура выше порогового значения
  if (c >= set_temp) {
    //Чтобы сигнал оповещения сработал только 1 раз
    if ((!one_time) {
    tone(SPEAKER, 400);
      delay(500);
      one_time = true;
    }
    else {
      noTone(SPEAKER);
    }
    //Включаем вентилятор и обновляем ЖКД
    digitalWrite(FAN, HIGH);
    lcd.setCursor(15, 1);
    lcd.write(2);
  }
  //Если текущая температура ниже порогового значения
  else {
    //Выключаем динамик, сбрасываем переменную состояния подачи звукового сигнала, обновляем индикатор состояния вентилятора на ЖКД
    noTone(SPEAKER);
    one_time = false;
    digitalWrite(FAN, LOW);
    lcd.setCursor(15, 1);
    lcd.write(1);
  }
}

//Функция устранения дребезга контактов
boolean debounce (boolean last, int pin) {
  bool current = digitalRead(pin);
  if (last = !current) {
    delay(5);
    current = digitalRead(pin);
  }
  return current;
}
