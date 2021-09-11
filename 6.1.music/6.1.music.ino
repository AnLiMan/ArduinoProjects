#include "pitches.h" //Заголовочный файл с определениями частот нот
#define SPEAKER 9 //Пин динамика

//Массив нот
int notes [] = {
  NOTE_A4, NOTE_E3, NOTE_A4, 0,
  NOTE_A4, NOTE_E3, NOTE_A4, 0,
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B4,
  NOTE_A4, NOTE_B4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_E3, NOTE_A4, 0
};

//Массив длительностей звучания каждой ноты (в мс)
int times [] = {
  250, 250, 250, 250,
  250, 250, 250, 250,
  125, 125, 125, 125,
  125, 125, 125, 125,
  250, 250, 250, 250
};

void setup() {
}

void loop() {
  //Воспроизводим каждую ноту в течение соответствующего времени
  for (int i = 0; i < 20; i++) {
    tone(SPEAKER, notes[i], times[i]);
    delay(times[i];
  }
  delay(1500);
}
