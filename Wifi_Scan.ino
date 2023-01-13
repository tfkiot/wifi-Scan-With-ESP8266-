#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.disconnect();  // disconnect previously connected access point 
  delay(200); // delay 200ms

  Serial.println("***** WiFi Scan Started *****");
}

void loop() {
  
  int n = WiFi.scanNetworks(); // WiFi.scanNetworks will return the number of networks found
   
  Serial.println("Scan done");
  
  if (n == 0)
    Serial.println("No Network Found");
  else
  {
    Serial.print(n);
    Serial.println(" Networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID, RSSI, MAC, Encryption for each network found
      Serial.print(i + 1);  //Sr. No
      Serial.print(": ");
      Serial.print(WiFi.SSID(i)); //SSID
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); //Signal Strength
      Serial.print(") MAC:");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)? " Unsecured" : " Secured" );
      delay(10);
    }
  }
  Serial.println("");

  delay(6000); // delay 6sec 
}
