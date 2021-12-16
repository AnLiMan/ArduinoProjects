#include <LiquidCrystal.h> // Подключение библиотеки ЖК-дисплея
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Инициализация экземпляра библиотеки LiquidCrystal


#define LED_RED 13 // Порт 13, красный светодиод
#define LED_YELLOW 12 // Порт 12, желтый светодиод
#define LED_GREEN 11 // Порт 11, зеленый светодиод
#define TIMEOUT_RED 3000 // Время горения красного сетодиода
#define TIMEOUT_YEL 1690 // Время горения желтого светодиода
#define TIMEOUT_GREEN 2000 // Время горения зеленого светодиода

#define TIMEOUT_FLASH_GREEN 500 // Время мигания зеленого светодиода
String array1[] = {"RED", "YELLOW", "GREEN"};

void setup() { // Все порты светодиодов будут у нас установлены в режим "внешняя нагрузка", OUTPUT
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  // Устанавливаем начальное значение светодиодов
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  lcd.begin(16, 2); // Настройка экземпляра дисплея - число столбцов и строк:

}
void loop() {
  // Включаем зеленый цвет светофора
  digitalWrite(LED_GREEN, HIGH);    // Включаем светодиод
  lcd.setCursor(0, 0); // Установить курсор на вторую строку в первую позицию
  lcd.print(array1[2]);
  delay(TIMEOUT_GREEN);             // Ждем
  
  // Мигаем зеленым светодиодом 3 раза
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(LED_GREEN, LOW);
    delay(TIMEOUT_FLASH_GREEN);
    digitalWrite(LED_GREEN, HIGH);
    delay(TIMEOUT_FLASH_GREEN);
  }
  lcd.clear();

  // Теперь отключаем зеленый и включаем желтый светодиод
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  lcd.setCursor(0, 0); // Установить курсор на вторую строку в первую позицию
  lcd.print(array1[1]);
  delay(TIMEOUT_YEL);
  lcd.clear();

  // Отключаем желтый светодиод.
  digitalWrite(LED_YELLOW, LOW);
  // Теперь включаем красный цвет
  digitalWrite(LED_RED, HIGH);
  lcd.setCursor(0, 0); // Установить курсор на вторую строку в первую позицию
  lcd.print(array1[0]);
  delay(TIMEOUT_RED);

  // Включаем желтый светодиод,не выключая красный
  digitalWrite(LED_YELLOW, HIGH);
  lcd.setCursor(0, 1); // Установить курсор на вторую строку в первую позицию
  lcd.print(array1[1]);
  delay(TIMEOUT_YEL);

  // Отключаем желтый и красный светодиоды.
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  lcd.clear();
}
