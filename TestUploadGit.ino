#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Config Firebase nakarin.kul
#define FIREBASE_HOST "testpro1-8b05b.firebaseio.com"
#define FIREBASE_AUTH "h0uXRHmVaJi48ADg2p473RIJ84oaM2ETnzyNNFjc"

// Config connect WiFi
#define WIFI_SSID "Nakarin"
#define WIFI_PASSWORD "0816167210"

int i = 0;

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

//For Humid
  Firebase.setInt("Humid", i);
  if (Firebase.failed()) {
    Serial.print("set /Humid failed:");
    Serial.println(Firebase.error());
    return;
  }
  Serial.print("set /Humid to ");
  Serial.println(Firebase.getInt("Humid"));

//For Temp
  Firebase.setInt("Temp", i);
  if (Firebase.failed()) {
    Serial.print("set /Temp failed:");
    Serial.println(Firebase.error());
    return;
  }




  i++;
  delay(500);
}
