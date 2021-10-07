#include "BluetoothSerial.h" // заголовочный файл для последовательного Bluetooth будет добавлен по умолчанию в Arduino

BluetoothSerial ESP_BT; // Объект для Bluetooth

int incoming;
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(9600); // Запускаем последовательный монитор со скоростью 9600
  ESP_BT.begin("ESP32_LED_Control"); // Задаем имя вашего устройства Bluetooth
  Serial.println("Bluetooth Device is Ready to Pair");  // По готовности сообщаем, что устройство готово к сопряжению

  pinMode (LED_BUILTIN, OUTPUT);// задаем контакт подключения светодиода как выходной
}

void loop() {

  if (ESP_BT.available()) // Проверяем, не получили ли мы что-либо от Bluetooth модуля
  {
    incoming = ESP_BT.read(); // Читаем, что получили
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49)  // Если значение равно единице, включаем светодиод
    {
      digitalWrite(LED_BUILTIN, HIGH);
      ESP_BT.println("LED turned ON");
    }

    if (incoming == 48)  // Если значение равно нулю, выключаем светодиод
    {
      digitalWrite(LED_BUILTIN, LOW);
      ESP_BT.println("LED turned OFF");
    }
  }
  delay(20);
}
