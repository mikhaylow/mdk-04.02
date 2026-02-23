#include <GyverSegment.h>

Disp1637_4 disp(2, 3);

void setup() {
  disp.printRight(true);  // печатать справа
  disp.setCursorEnd();    // курсор в конец
}

int n = 0;

void loop() {
  disp.clear();
  disp.print(n);
  disp.update();
  n++;
  disp.delay(100);  // для дин. дисплеев
}
