int a, b;

void setup() {
  Serial.begin(9600);
  Serial.println("Введите первое число");
}

void loop() {
  if (Serial.available()) {

    a = Serial.parseInt();

    Serial.println(a);

    Serial.println("Введите второе число");

    b = Serial.parseInt();

    Serial.println(b);

    Serial.print("Сложение: ");
    Serial.print(a);
    Serial.print(" + ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.print(a + b);

    Serial.println();

    Serial.print("Вычитание: ");
    Serial.print(a);
    Serial.print(" - ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.print(a - b);

    Serial.println();

    Serial.print("Умножение: ");
    Serial.print(a);
    Serial.print(" * ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.print(a * b);

    Serial.println();

    Serial.print("Деление: ");
    Serial.print(a);
    Serial.print(" / ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.print(a / b);
  }
}