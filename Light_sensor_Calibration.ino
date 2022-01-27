#define LIGHTSENSORPIN A0 //Ambient light sensor reading

void setup()
{
pinMode(LIGHTSENSORPIN, INPUT);

Serial.begin(9600);
}

void loop()
{
 int reading;
reading = analogRead(LIGHTSENSORPIN);//Read light level
Serial.println("Light Sensor Reading: ");
Serial.println(reading);

Serial.println("\n");
}
