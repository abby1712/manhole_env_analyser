#define GASSENSORPIN D0 //Gas Sensor Reading

#include <Buzzer.h>
Buzzer buzzer(D8);
void setup()
{
pinMode(LIGHTSENSORPIN, INPUT);

Serial.begin(9600);
}
void loop()
{
 int reading;
reading = analogRead(GASSENSORPIN);//Read light level
Serial.println("Gas Sensor Reading: ");
Serial.println(reading);
if (reading ==0)
{
  Buzzer_alert();
}

Serial.println("\n");

delay(500);

}


void Buzzer_alert()
{

  Serial.println("Buzzer Activated");
   buzzer.begin(0);

  buzzer.distortion(NOTE_C3, NOTE_C5);
  buzzer.distortion(NOTE_C5, NOTE_C3);

  buzzer.end(1000);
           
}

