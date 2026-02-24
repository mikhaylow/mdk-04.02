#include <LiquidCrystal_I2C.h> // библиотека для LCD дисплеев с I2C

LiquidCrystal_I2C lcd(0x27, 16, 2); // lcd: I2C адрес 0x27, 16x2 символа

// определяем пользовательские символы (каждый - 8 байт = 5x8 пикселей)
// порядок байтов: сверху вниз, каждый бит = пиксель (1=вкл, 0=выкл)
byte bell[]     = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};      // колокольчик
byte note[]     = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};      // музыкальная нота
byte clock[]    = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};    // часы
byte heart[]    = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};    // сердце
byte duck[]     = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};      // утка
byte check[]    = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};    // галочка
byte cross[]    = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};    // крестик
byte retarrow[] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};    // стрелка возврата

void setup() {
  lcd.init();            // инициализация LCD
  lcd.backlight();       // включить подсветку
  
  // создаём пользовательские символы 0..7 из массивов
  // createChar(номер_символа, массив_байтов) - символы доступны как lcd.write(0)..lcd.write(7)
  lcd.createChar(0, bell);      // символ #0 = колокольчик
  lcd.createChar(1, note);      // символ #1 = нота
  lcd.createChar(2, clock);     // символ #2 = часы
  lcd.createChar(3, heart);     // символ #3 = сердце
  lcd.createChar(4, duck);      // символ #4 = утка
  lcd.createChar(5, check);     // символ #5 = галочка
  lcd.createChar(6, cross);     // символ #6 = крестик
  lcd.createChar(7, retarrow);  // символ #7 = стрелка возврата
  
  // возвращаемся в начало 1-й строки (0,0)
  lcd.home();
  
  // выводим все 8 символов подряд на первой строке для демонстрации
  lcd.write(0);  // колокольчик
  lcd.write(1);  // нота
  lcd.write(2);  // часы
  lcd.write(3);  // сердце
  lcd.write(4);  // утка
  lcd.write(5);  // галочка
  lcd.write(6);  // крестик
  lcd.write(7);  // стрелка возврата
}

void loop() {
  // пустой - статичная демонстрация
}
