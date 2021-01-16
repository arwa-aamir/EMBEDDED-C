#include <WiFi.h>  // esp32 library
#include <IOXhop_FirebaseESP32.h> // firebase library 
#define FIREBASE_HOST "ledcontrol-62944.firebaseio.com/"  //Your Firebase //Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "OxzrkO3madFgyyp4CNRCco0dS4ZLzXmtUG88SJ5k"
//Your Firebase Database Secret goes here
#define WIFI_SSID "PinkPanther"  //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "AFA123E185"    //Password of your wifi network 
String fireStatus = ""; // led status received from firebase 
String fireStatus2 = "";
const int led1 = 4; const int led2=5;

void setup() { Serial.begin(9600); delay(1000);
pinMode(4, OUTPUT); pinMode(5, OUTPUT);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //try to connect with wifi

Serial.print("Connecting to "); Serial.print(WIFI_SSID);
while (WiFi.status() != WL_CONNECTED) { Serial.print(".");
delay(500);

}

Serial.println(); Serial.print("Connected to ");

Serial.println(WIFI_SSID); Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());  //print local IP address

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // connect to firebase

Firebase.setString("LED1", "0");  //send initial string of led status 
Firebase.setString("LED2", "0");
}

void loop() {

fireStatus = Firebase.getString("LED1");  // get led status input from firebase

if (fireStatus == "1") {  // compare the input of led status received from firebase

Serial.println("Led1 Turned ON");

digitalWrite(4, HIGH);  // make output led ON

}

else if (fireStatus == "0") { // compare the input of led status received from firebase

Serial.println("Led1 Turned OFF");

digitalWrite(4, LOW); // make output led OFF

}

else {

Serial.println("Wrong Credential for LED1! Please send ON/OFF");

}

fireStatus2 = Firebase.getString("LED2");
if (fireStatus2 == "1") {  // compare the input of led status received from firebase

Serial.println("Led2 Turned ON");

digitalWrite(5, HIGH);  // make output led ON

}

else if (fireStatus2 == "0") {  // compare the input of led status received from firebase

Serial.println("Led2 Turned OFF");

digitalWrite(5, LOW); // make output led OFF

}

else {

Serial.println("Wrong Credential for LED2! Please send ON/OFF");

}
}
