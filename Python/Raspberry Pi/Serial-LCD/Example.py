from LCD_Serial import LCD_Serial
import time

# Initialize the Module for a LCD with 20 Columns per Line
LCD = LCD_Serial("/dev/ttyAMA0", 9600, 20)

# Delete Display
LCD.Clr()

# Outputstring
String = "Test"

while True:
	for I in range(1, 21 - len(String)):
		LCD.Position(3, I)
		LCD.Write(String)
		time.sleep(1)
		LCD.Clr()
	
	for I in range(21 - len(String), 0, -1):
		LCD.Position(3, I)
		LCD.Write(String)
		time.sleep(1)
		LCD.Clr()
