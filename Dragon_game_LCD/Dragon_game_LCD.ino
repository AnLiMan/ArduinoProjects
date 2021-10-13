#include <Wire.h>// библиотека для протокола IIC
#include <LiquidCrystal.h> // Подключение библиотеки ЖК-дисплея
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Инициализация экземпляра библиотеки LiquidCrystal с номерами шин интерфейса

#define Butt1  11 //Пин кнопки 1
bool flag1 = false; //Флаг нажатия кнопки 1

int level = 1; // переменная для отсчета уровня
int pause = 400; // переменная для задержки
byte p = 0;  // переменная для времени прыжка

// создаем массивы дракончика, дерева, камня и птицы
byte dracon[8] = {0b01110, 0b11011, 0b11111, 0b11100, 0b11111, 0b01100, 0b10010, 0b11011};
byte derevo[8] = {0b00000, 0b00000, 0b00000, 0b11011, 0b11011, 0b11011, 0b01100, 0b01100};
byte kamen[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01110, 0b11111};
byte ptica[8] = {0b00100, 0b00101, 0b01111, 0b11111, 0b10100, 0b00100, 0b00000, 0b00000};

void setup() {
  pinMode (10, OUTPUT); // подключаем пьезодинамик
  pinMode(Butt1, INPUT_PULLUP);
  lcd.begin(16, 2); // Настройка экземпляра дисплея - число столбцов и строк:

  // создаем символы дракончика, дерева, камня и птицы
  lcd.createChar(0, dracon);
  lcd.createChar(1, derevo);
  lcd.createChar(2, kamen);
  lcd.createChar(3, ptica);

  // начинаем игру: выводим надпись GO!
  lcd.setCursor(7, 0);
  lcd.print("GO!");
  delay(400);
  tone(10, 600);
  delay(100);
  noTone(10);
  lcd.clear();
}

void loop() {
  // первоначальное положение дракончика и препятствия
  byte d = 1;
  byte x = 15;
  byte y = 1;
  // выбираем препятствие, которое появится, рандомно
  byte i = random (1, 4);
  if (i == 3) y = 0;
  else y = 1;

  while (x > 0) {
    // очищаем экран и выводим номер уровня
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(level);

    // считываем данные с кнопки и учитываем количество циклов в прыжке
    // если дакончик находится в прыжке долго - возвращаем его вниз
    bool btn1State = digitalRead(Butt1);
    if (btn1State && !flag1)
    {
      d = 1;
    }
    else {
      d = 0;
    }

    if (p > 3) { 
      d = 1;
    }

    // выводим дракончика в нужной строке
    lcd.setCursor(4, d);
    lcd.print(char(0));
    // выводим препятствие
    lcd.setCursor(x, y);
    tone(10, 50);
    lcd.print(char(i));
    noTone(10);

    // если дракончик наткнулся на препятствие выводим надпись GAME OVER!
    if (x == 4 && y == d) {
      delay(400);
      tone(10, 50);
      delay(100);
      noTone(10);
      delay(100);
      tone(10, 20);
      delay(300);
      noTone(10);
      lcd.clear();
      delay(200);
      lcd.setCursor(3, 0);
      lcd.print("GAME OVER!");
      delay(600);
      lcd.clear();
      delay(400);
      lcd.setCursor(3, 0);
      lcd.print("GAME OVER!");
      delay(600);
      lcd.clear();
      lcd.setCursor(3, 1);
      lcd.print("LEVEL: ");
      lcd.print(level);
      delay(400);
      lcd.setCursor(3, 0);
      lcd.print("GAME OVER!");
      delay(3000);
      lcd.clear();

      // начинаем игру заново, обнулив уровень игры
      lcd.setCursor(7, 0);
      lcd.print("GO!");
      delay(400);
      tone(10, 600);
      delay(100);
      noTone(10);
      lcd.clear();

      level = 0;
      pause = 400;
      p = 0;
      y = 1;
      x = 0;
      break;
    }

    // если дракончик прыгнул, издаем звук
    if (d == 0) {
      tone(10, 200);
      delay(100);
      noTone(10);
    }
    else {
      delay(100);
    }

    // если дракончик не столкнулся, то меняем положение препятствия
    // начинаем считать сколько циклов дракончик находится в прыжке
    delay(pause);
    x = x - 1;
    p = p + 1;
    if (p > 4) p = 0;
  }

  // переходим на следующий уровень и сокращаем время задержки
  tone(10, 800);
  delay(20);
  level = level + 1;
  pause = pause - 20;
  if (pause < 0) pause = 0;
}
