#include <DHT.h> 
#define DHTTYPE DHT11
#define DHTPIN 8

#define b 9
#define c 13
#define d 10
#define e 11
#define f 12
#define g 6

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(7, OUTPUT);  //Led and Buzzer
    
    Serial.begin(9600);
    Serial.println("Program Started!");
    dht.begin();

}

void loop() {
 delay(2000); // Wait a few seconds between measurements
 float h = dht.readHumidity();  // Reading temperature or humidity takes about 250 milliseconds!
 float t = dht.readTemperature(); // Read temperature as Celsius (the default)
 float f_temp = dht.readTemperature(true); // Read temperature as Fahrenheit (isFahrenheit = true) 
 
 if (isnan(h) || isnan(t) || isnan(f_temp))  // Check if any reads failed and exit early (to try again).
{
 Serial.println("Failed to read from DHT sensor!");
 return;
 }

 if(h < 41){
  
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH); //
  digitalWrite(e, HIGH); //
  digitalWrite(f, HIGH); //
  digitalWrite(g, LOW);
  digitalWrite(7, LOW);
  Serial.println ("-----------------------------------------");
  Serial.print ("Humidity: ");
  Serial.print (h);
  Serial.println ("%\t");
  Serial.println ("Humidity < 40% hense 'L' \t");
  Serial.println ("Relay = OFF\t");
  Serial.println ("-----------------------------------------");
  
  
  
 }else{
  if(h > 40 && h < 71){
    
   digitalWrite(b, HIGH);
   digitalWrite(c, HIGH); //
   digitalWrite(d, HIGH); //
   digitalWrite(e, HIGH); //
   digitalWrite(f, HIGH); //
   digitalWrite(g, LOW);
   digitalWrite(7, HIGH);
   Serial.println ("-----------------------------------------");
   Serial.print ("Humidity: ");
   Serial.print (h);
   Serial.println ("%\t");
   Serial.println ("40% < Humidity > 70% hense 'U' \t");
   Serial.println ("Relay = OFF");
   Serial.println ("-----------------------------------------");
   
  }else{
    if(h < 70 && h < 101){
      
      digitalWrite(b, HIGH); //
      digitalWrite(c, HIGH); //
      digitalWrite(d, LOW);
      digitalWrite(e, HIGH); //
      digitalWrite(f, HIGH); //
      digitalWrite(g, HIGH); //
      digitalWrite(7, HIGH);
      Serial.println ("-----------------------------------------");
      Serial.print ("Humidity: ");
      Serial.print (h);
      Serial.println ("% \t");
      Serial.println ("70% < Humidity < 100% hense 'H' \t");
      Serial.println ("Relay = ON\t");
      Serial.println ("-----------------------------------------");
      
    }
  }
 }
 }
