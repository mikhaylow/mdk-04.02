# define BUTTON_PIN 3 // кнопкна подключена к пину 3

int bounceTime = 10; // время для защиты от дребезга
int doubleTime = 500; // максимальное время между нажатиями для распознавания
int i = 0; // счетчика многократных нажатий
boolean lastReading = false; // флаг предыдущего состояния кнопки
boolean buttonSingle = false; // флаг что было одиночное нажатие
boolean buttonMulti = false; // флаг что было многократное нажатие
long onTime = 0; // переменная обработки когда кнопка была нажата
long lastSwitchTime = 0; // переменная времени предыдущего переключения состояния

void setup() {
  Serial.begin(9600);
  // настройка пина как вход с подтяжкой к питанию
  pinMode(3, INPUT_PULLUP);

}

void loop() {
  // получаем текущее состояние кнопки
  boolean reading = digitalRead(BUTTON_PIN);

  // если текущее состояние true и последнее состояние false (если кнопку отпустили)
  if (reading && !lastReading) {
    // получаем время отпускания кнопки
    onTime = millis();
  }

  // если reading = false и lastReading = true то (если кнопку нажали)
  if (!reading && lastReading) {
    // если текущее время минус время нажатия кнопки, больше чем время для защиты от дребезга
    if (((millis() - onTime) > bounceTime)) {
      // если текущее время минус время предыдущего переключения состояния то
      if ((millis() - lastSwitchTime) >= doubleTime) {
        // обновляем время переключения состояния
        lastSwitchTime = millis();
        // одиночное нажатие кнопки true
        buttonSingle = true;
        // счетчик нажатия кнопки равен 1
        i = 1;
      } else { // иначе
        // инкрементируем счетчик нажатия кнопки
        i++;
        // обновляем время переключения состояния
        lastSwitchTime = millis();
        // одиночное состояние кнопки false
        buttonSingle = false;
        // состояние при многократном нажатии true
        buttonMulti = true;
      }
    }
  }

  // предыдущее состояние кнопки заменяем на текущее состояние
  lastReading = reading;
  // если флаг одиночного нажатия равен true и текущее время минус время последнего переключения состояния больше чем максимальное время между нажатиями
  if (buttonSingle && (millis() - lastSwitchTime) > doubleTime) {
    // то кнопка нажата 1 раз
    isButtonSingle();
  }
  // если флаг многократного нажатия равен true и текущее время минус время последнего переключения состояния больше чем максимальное время между нажатиями
  if (buttonMulti && (millis() - lastSwitchTime) > doubleTime) {
    // то кнопка нажата многократно
    isButtonMulti(i);
  }
}

// Метод для одиночного нажатия
void isButtonSingle() {
  // флаг многократного нажатия переводим в false
  buttonMulti = false;
  // флаг одиночного нажатия переводим в false
  buttonSingle = false;
  // выводим 1
  Serial.println(1);
}

// Метод для многократных нажатий
void isButtonMulti( int count ) {
  // флаг одиночного нажатия переводим в false
  buttonSingle = false;
  // флаг многократного нажатия переводим в false
  buttonMulti = false;
  // выводим количество переданное в параметре метода
  Serial.println(count);
}
