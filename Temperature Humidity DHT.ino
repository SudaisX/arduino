
#include <DHT.h> 

#define DHTTYPE DHT11
#define DHTPIN`13

DHT dht(DHTPIN, DHTTYPE);

void setup() {

    Serial.begin(9600);
    Serial.println("DHTxx test!");
    dht.begin();

}

void loop() {
 delay(2000); // Wait a few seconds between measurements
 float h = dht.readHumidity();
 // Reading temperature or humidity takes about 250 milliseconds!

 float t = dht.readTemperature();
 // Read temperature as Celsius (the default)

 float f = dht.readTemperature(true);
 // Read temperature as Fahrenheit (isFahrenheit = true)
 // Check if any reads failed and exit early (to try again).
 if (isnan(h) || isnan(t) || isnan(f))
{
 Serial.println("Failed to read from DHT sensor!");
 return;
 }

 // Compute heat index in Fahrenheit (the default)
 float hif = dht.computeHeatIndex(f, h);

 // Compute heat index in Celsius (isFahreheit = false)
 float hic = dht.computeHeatIndex(t, h, false);
 Serial.print ("Humidity: ");
 Serial.print (h);
 Serial.print (" %\t");
 Serial.print ("Temperature: ");
 Serial.print (t);
 Serial.print (" *C ");
 Serial.print (f);
 Serial.print (" *F\t");
 Serial.print ("Heat index: ");
 Serial.print (hic);
 Serial.print (" *C ");
 Serial.print (hif);
 Serial.println (" *F");
}
