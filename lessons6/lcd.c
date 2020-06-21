// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 9, 8, 7, 6, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  delay(10);
  // Print a message to the LCD.
  lcd.print("display program");
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("input data:");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  const String tempString=Serial.readString();
  Serial.println(tempString);
  lcd.print(tempString);
  while(!Serial.available()){}
}
 