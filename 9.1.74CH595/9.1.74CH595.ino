#define SER 8 //Контакт для подачи последовательных данных на вход сгвигового регистра
#define LATCH 9 // Пин для подключения входа сигнала фиксации сдвигового регистра
#define CLK 10 // Пин для подключения тактового входа свигового регистра

int numOfRegisters = 1; //Количество сдвиговых регистров
byte *registerState;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  //Прямая передача в виде бинарного кода
  digitalWrite(LATCH, LOW); //Включить передачу данных
  shiftOut(SER, CLK, MSBFIRST, B10101010); //Передаем биты, начиная со старшего
  digitalWrite(LATCH, HIGH); //Закончить передачу данных
  delay(2000);

  //Передача с помощью массивов.
  byte seq [] = {0, 11, 2, 9, 1, 4, 15, 3, 12, 5}; //Определимм массив
  for (int i = 0; i < 9; i++) {
    regWrite(seq[i], HIGH);
    delay(250);
  }
}

void regWrite(int pin, bool state) {
  byte reg = pin / 8; //Делим число на 8, остаток всегда целочисленный (0, 1 и т.д.)
  byte actualPin = pin - (8 * reg); //Определяем номер сдвигового регистра в соответствии с отправленными данными
  digitalWrite(LATCH, LOW); //Включить передачу данных

  //Запускаем цикл отработки данных для всех сдвиговых регистров
  for (byte i = 0; i < numOfRegisters; i++) {
    byte* states = &registerState[i];
    if (i == reg) {
      /*
        bitWrite изменяет состояние указанного бита переменной. bitWrite(x, n, b). Параметры:
        x: числовая переменная, у которой необходимо изменить бит
        n: номер бита, состояние которого необходимо изменить. Нумерация начинается с младшего
        значащего бита (крайнего правого) с номером 0
        b: новое значение бита (0 или 1)
      */
      bitWrite(*states, actualPin, state);
    }
    shiftOut(SER, CLK, MSBFIRST, *states); //Передаём биты
  }
  digitalWrite(LATCH, HIGH); //Закончить передачу данных
}
