#define SER 8 //Контакт для подачи последовательных данных на вход сдвигового регистра
#define LATCH 9 // Пин для подключения входа сигнала фиксации сдвигового регистра
#define CLK 10 // Пин для подключения тактового входа свигового регистра

int numOfRegisters = 2; //Количество сдвиговых регистров
byte *registerState;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  //---------Передача в виде массива-------

  Serial.println("Array");
  //Передача с помощью массивов.
  byte seq [] = {0, 2, 15, 13, 7, 6, 4, 11, 1, 5, 9}; //Определимм массив
  for (int i = 0; i < 12; i++) {
    regWrite(seq[i], HIGH);
    delay(500);
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
