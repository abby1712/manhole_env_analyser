#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN 6
#define NUMPIXELS 4

// Header Files and Definitons
int ledPin = 13;
int buttonApin = 7;
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Neopixel Definition

#define DELAYVAL 500 
// Time (in milliseconds)  to pause between pixels


int pin8 = 8, pin9= 9, pin10=10;
// Digital pin 8 will be called 'pin8' and   Digital pin 9  will be called 'pin9'


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Digital Pins Connected to The LCD

int sensor = A0;
// Analog pin 0 will be called 'sensor'


int sensorValue = 0;
// Set the initial sensorValue to 0


// The setup routine runs once when you press reset
void setup() 
{
  pinMode(pin8, OUTPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);   
  pinMode(pin10, OUTPUT);
   pinMode(A1, INPUT);
  pinMode(pin9, OUTPUT);
  // Begin Defintion to all the various Modules.
  Serial.begin(9600);
  lcd.begin(16, 2);
 
  pixels.begin();
}


// The loop routine runs over and over again forever



// The loop routine runs over and over again forever
void loop()
{
  
  Bulb();
  
  // Read the input on analog pin 0 (named 'sensor')
  sensorValue = analogRead(sensor);
  
  // Print out the value you read
 
  
  // If sensorValue is greater than 800
  if (sensorValue > 800) 
  {
    // Activate digital output pin 8 - the LED will light up
    digitalWrite(pin8, HIGH); // Red LED GLows
    digitalWrite(pin9, LOW); // Green LED Stops
    digitalWrite(pin10, HIGH); 
    lcd.setCursor(0,0 );  // Printing Danger In LCD
    lcd.print("Gas:Danger\n");
    pixel_red();       // Calling the Pixel_Red Glow  Function.
     
  }
  else {
    // Deactivate digital output pin 8 - the LED will not light up
    digitalWrite(pin8, LOW);
      lcd.setCursor(0, 0);
    digitalWrite(pin9, HIGH); // Green LED Glows
    lcd.print("\nGas:Safe\n");
      digitalWrite(pin10, LOW);
    pixel_green();  //Calling the Pixel_Green Glow  Function.
  }
  
  //Temp Module ---->
  baselineTemp = 40;
  celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  delay(1000);
  if(celsius>0||celsius<0)
  {
    
  if(celsius>60||celsius< -8)
  {
     lcd.setCursor(1,1 );  // Printing Danger In LCD
    lcd.print("Temp:Danger\n");
    delay(1000);
     lcd.clear();
  }
   else if(celsius<60||celsius> -8)
  {
     lcd.setCursor(1,2 );  // Printing Danger In LCD
    lcd.print("Temp:Safe\n");
     delay(1000);
     lcd.clear();
     
  }
    
  }
  
  
}
  
  void pixel_green() // User Defined pixel_Green Glow Function
{
  pixels.clear();
       pixels.setBrightness(255);
       pixels.setPixelColor(0, pixels.Color(0, 255, 0));
       pixels.setPixelColor(1, pixels.Color(0, 255, 0));
       pixels.setPixelColor(2, pixels.Color(0, 255, 0));
       pixels.setPixelColor(3, pixels.Color(0, 255, 0));
       pixels.show();
}
  
void pixel_red()  // User Defined pixel_Red Glow Function
{
       pixels.clear();
       pixels.setBrightness(255);
       pixels.setPixelColor(0, pixels.Color(255, 0, 0));
       pixels.setPixelColor(1, pixels.Color(255, 0, 0));
       pixels.setPixelColor(2, pixels.Color(255, 0, 0));
       pixels.setPixelColor(3, pixels.Color(255, 0, 0));
       pixels.show();
}

void Bulb()

{
   if (digitalRead(buttonApin) == HIGH)
	{
		digitalWrite(ledPin, HIGH);
	}
	else
	{
		digitalWrite(ledPin, LOW);
    }
}

