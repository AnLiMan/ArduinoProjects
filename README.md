# ArduinoProjets
- В данном репозитории собраны все скетчи, теория, методические указания и шпаргалки по Arduino. 
- Если вы ещё не установили среду для разработки или имеются какие-то вопросы, то рекомендуется начать с файла
"Работа с Arduino. Методическое пособие". 
- Указания по настройке и работе в среде можно найти в "Работа и настройка Arduino IDE". 
- Синтаксис С++ и правила оформления можно посмотреть в файле "Синтаксис и правила оформления C++".
- Стандартные команды и функции доступные из "коробки" для программирования Arduino можно найти в файле "Основные команды и функции Arduino".

# Описание проектов

- 1.1._Blink. Классика первого скетча. Hellow world, в мире микрокроллеров. Самое простое, что можно написать на ардуино без использования хоть какого-то дополнительного оборудования, смысл заключается в моргании встроенным в плату светодиодом с определённой периодичностью.
- 2.1._LED_Turn_On. Просто включим внешнеий светодиод
- 2.2._LED_Blinkю. Тоже самое, что и скетч "1.1._Blink", но теперь мы моргаем внешним сетодиодом
- 2.3._LED_PWM. Управляем яркостью внешнего светодиода.
- 2.4_2.5._Button. Считываем значение кнопок, есть скетч на подтяжку кнопки.
- 3.1.Pot_Analog_Read. Чтение значения с потенциометрам при помощи аналогового входа ардуино
- 3.2.Temperature. Чтение сигнала с аналогового датчика температуры
- 3.3.PhotoResistor. Считывание значений фоторезистора, с помощью аналогового входа ардуино
- 4.1.Motor_auto. Подключение щёточного двигателя через транзистор, управление скоростью автоматическое при помощи ардуино
- 4.2.Motor_manual. Подключение щёточного двигателя через транзистор, управление скоростью ручное при помощи переменного резистора и ардуино
- 4.3.Motor_With_H-Bribge. Подключение щёточного двигателя по схеме Н-моста на базе микросхемы L293D
- 4.4.Mobile_Robot. Сборка самоходного робота на двух мотор-редукторах
- 5.1.Servo. Подключение сероводвигателя
- 5.2.rangefinder. Измерение расстояния на основе инфракрасного датчика расстояния.
- 5.3.Stepper_motor. Подключение шагового двигателя
- 5.3.Stepper_motor_butt. 
- 5.4.Choronograph. Хронограф.
- 6.1.music. Проигрывание простых мелодий на динамике при помощи стандартной библиотеки tone()
- 7.1.Serial.print_tab. Пример вывода таблиц в последовательный порт 
- 7.2.Serial_Char_Control. Управление Arduino через последовательный порт
- 9.1.74CH595. Работа со сдвиговым регистром 74CH595
- 9.1.74CH595___2_. Работа со сдвиговым регистром 74CH595
- 10.1.Read_temp. Чтение температуры с цифрового датчика температуры TC74A0-5.0VAT 
- 11.1.Orientation. Подключение датчика ориентации 
- 12.1.LCD_Text. Вывод текста на дисплей 1602
- 12.2.Progress_Bar. Отображение полоски загрузки на дисплее 1602
- 12.3.LCD_Thermostat. Термостат с дисплеем 1602
- 13.1.Interrupt. Скетч с примерами на прерывания 
- 13.2.Timer_interrupt. Прерывания по таймеру
- Dragon_game_LCD. Гугл динозаврик на дисплее 1602
- Kalman. Пример цифрового фильтра Калмана
- LCD_I2C. Подключение цисплея 1602 по I2С
- traffic_lights. Светофор
- Traffic_light_update. Светофор с отображением текущего цвета на дисплее 1602
- JoystickRead. Скетч для чтения значений со стандартного джойстики для ардуино
- SensorKeyboard. Скетч для сенсорной клавиатуры на микросхеме TTP229 
- ColorRead_with_TCS3200. Чтение цвета при помощи микросхемы TCS3200
- 4-digit_7-segment_LED_Display. Подключение 4-х разрядного индикатора, у которого нет управляющей микросхемы
