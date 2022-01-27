#define GASSENSORPIN D0 //Ambient light sensor reading

void setup()
{
pinMode(GASSENSORPIN, INPUT);

Serial.begin(9600);
}

void loop()
{
 int reading;
reading = analogRead(GASSENSORPIN);//Read light level
Serial.println("GAS Sensor Reading: ");
Serial.println(reading);

Serial.println("\n");
}
