#define LED_RED 13 // Порт 13, красный светодиод
#define LED_YELLOW 12 // Порт 12, желтый светодиод
#define LED_GREEN 11 // Порт 11, зеленый светодиод

#define TIMEOUT_RED 3000 // Время горения красного сетодиода
#define TIMEOUT_YEL 1690 // Время горения желтого светодиода
#define TIMEOUT_GREEN 2000 // Время горения зеленого светодиода

#define TIMEOUT_FLASH_GREEN 500 // Время мигания зеленого светодиода

void setup()
{
  // Все порты светодиодов будут у нас установлены в режим "внешняя нагрузка", OUTPUT
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  // Устанавливаем начальное значение светодиодов
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void loop()
{
  // Включаем зеленый цвет светофора
  digitalWrite(LED_GREEN, HIGH);    // Включаем светодиод
  delay(TIMEOUT_GREEN);             // Ждем

  // Мигаем зеленым светодиодом 3 раза
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(LED_GREEN, LOW);
    delay(TIMEOUT_FLASH_GREEN);
    digitalWrite(LED_GREEN, HIGH);
    delay(TIMEOUT_FLASH_GREEN);
  }

  // Теперь отключаем зеленый и включаем желтый светодиод
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  delay(TIMEOUT_YEL);

  // Отключаем желтый светодиод.
  digitalWrite(LED_YELLOW, LOW);
  // Теперь включаем красный цвет
  digitalWrite(LED_RED, HIGH);
  delay(TIMEOUT_RED);

  // Включаем желтый светодиод,не выключая красный
  digitalWrite(LED_YELLOW, HIGH);
  delay(TIMEOUT_YEL);

  // Отключаем желтый и красный светодиоды.
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}
