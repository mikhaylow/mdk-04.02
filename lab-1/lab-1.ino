String fio = "Михайлов Андрей Алексеевич";
String group = "РЭУ-23.251";
int journalNum = 13;
int result = journalNum * 100;

void setup() {
  Serial.begin(9600);
  
  Serial.println("ФИО: " + fio);
  
  Serial.println("Номер группы: " + group);
  
  Serial.println("Номер по журналу: " +  String(journalNum));

  Serial.println("Умноженный на 100: " + String(result));
  
  Serial.print("Десятичное: ");
  Serial.println(result);
  
  Serial.print("Двоичное: ");
  Serial.println(result, BIN);
  
  Serial.print("Восьмеричное: ");
  Serial.println(result, OCT);
  
  Serial.print("Шестнадцатеричное: ");
  Serial.println(result, HEX);
}

void loop() {
}