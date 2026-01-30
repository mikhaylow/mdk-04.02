void setup() {
  Serial.begin(9600);

  // настройка пина как вход с подтяжкой к питанию
  pinMode(3, INPUT_PULLUP);
}

// флаг для отслеживания состояния кнпоки
bool flag = false;

// переменная для хранения времени изменения состояния
uint32_t btnTimer = 0;

void loop() {
  // читаем инвертированное значение для удобства (1 нажата, 0 отпущена)
  bool btnState = !digitalRead(3);

  // если кнопка нажата, флаг равен false и с последнего изменения прошло больше 100 мс
  if (btnState && !flag && millis() - btnTimer > 100) {
    // флаг в true (кнопка нажата)
    flag = true;
    // текущее время изменения состояния
    btnTimer = millis();
    // выводим press
    Serial.println("press");
  }

  // если кнопка отпущена, флаг равен true, и с последнего изменения прошло больше 100 мс
  if (!btnState && flag && millis() - btnTimer > 100) {
    // флаг в false (кнопка отпущена)
    flag = false;
    // текущее время изменения состояния
    btnTimer = millis();
    // выводим realese
    Serial.println("release");
  }
}