# Use it with the SerLCD Module from Sparkfun
# www.kampis-elektroecke.de

import serial

class LCD_Serial:
	
	# Init
	def __init__(self, device, baudrate, Zeichen):
	
		self.device = device
		self.baudrate = baudrate
		self.Zeichen = Zeichen

		self.UART = serial.Serial(self.device, self.baudrate)

		# Opening COM-Port
		if(not(self.UART.isOpen())):
			self.UART.open()

	def Clr(self):

		# Commandcode
		self.UART.write(chr(0xFE))
	
		# Reset Display
		self.UART.write(chr(0x01))

	# Sets the Position of the Cursor
	# Line = 1 - 4
	# Position = 1 - 20
	def Position(self, Line, CharPosition):

		self.Line = Line
		self.CharPosition = CharPosition

		self.UART.write(chr(0xFE))
	
		if(self.Zeichen == 16):

			if(self.Line == 1):
				self.CharPosition = self.CharPosition - 1
			elif(self.Line == 2):
				self.CharPosition = self.CharPosition + 63
			elif(self.Line == 3):
				self.CharPosition = self.CharPosition + 15
			elif(self.Line == 4):
				self.CharPosition = self.CharPosition + 79
			else:
				print("Wrong Number of Columns!")
				return -1

		elif(self.Zeichen == 20):

			if(self.Line == 1):
				self.CharPosition = self.CharPosition - 1
			elif(self.Line == 2):
				self.CharPosition = self.CharPosition + 63
			elif(self.Line == 3):
				self.CharPosition = self.CharPosition + 19
			elif(self.Line == 4):
				self.CharPosition = self.CharPosition + 83
			else:
				print("Wrong Number of Rows!")
				return -1

		else:
			print("Ungueltige Zeichenangabe!")
			return -1

		self.CharPosition = self.CharPosition + 128
		self.UART.write(chr(self.CharPosition))

	# Set the Brightness from 0 to 30
	def SetBrightness(self, Brightness):
	
		self.Brightness = Brightness

		# Check Value
		if(self.Brightness > 30):
			print("Wrong Brightness!")
			return -1

		self.Brightness = 128 + self.Brightness
	
		self.UART.write(chr(0x7C))
		self.UART.write(chr(self.Brightness))		

	# Activate blinking Cursor
	# On = Enable
	# Off = Disable
	def EnableBlink(self, Enable):
	
		self.Enable = Enable

		if(self.Enable == "Off"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0C))
		elif(self.Enable == "On"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0D))
		else:
			print("Wrong Cursorsettings!")
			return -1

	# Activate Underline
	# On = Enable
	# Off = Disable	
	def EnableUnderline(self, Enable):

		self.Enable = Enable

		if(self.Enable == "Off"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0C))
		elif(self.Enable == "On"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0E))
		else:
			print("Wrong Cursorsettings!")
			return -1
	
	# Enable Display
	# On = Enable
	# Off = Disable	
	def EnableVisual(self, Enable):

		self.Enable = Enable
		
		if(self.Enable == "Off"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x08))
		elif(self.Enable == "On"):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0C))
		else:
			print("Wrong Cursorsettings!")
			return -1
	
	def SwitchSplash(self):

		self.UART.write(chr(0x7C))
		self.UART.write(chr(0x09))

	# Set Cursorposition
	def SetCursor(self, CursorPosition):
	
		self.CursorPosition = 128 + self.CursorPosition + 1
	
		self.UART.write(chr(0xFE))
		self.UART.write(chr(self.CursorPosition))
	
	# Change Baud
	def ChangeBaud(self, Baud):
	
		self.Baud = Baud
		
		if(self.Baud == 2400):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0B))
		elif(self.Baud == 4800):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0C))
		elif(self.Baud == 9600):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0D))
		elif(self.Baud == 14400):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0E))
		elif(self.Baud == 19200):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x0F))
		elif(self.Baud == 38400):
			self.UART.write(chr(0xFE))
			self.UART.write(chr(0x10))
		else:
			print("Wrong Baudrate!")
			return -1

	# Write Text
	def Write(self, Text):

		self.Text = Text
		self.UART.write(self.Text)
