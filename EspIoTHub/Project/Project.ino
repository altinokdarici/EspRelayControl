#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* ssid = "950xl_AD";
const char* password = "12345678";
const char* mqtt_server = "esprelay.azure-devices.net";
const char* deviceId="1000";
const char * pass="SharedAccessSignature sr=EspRelay.azure-devices.net%2fdevices%2f1000&sig=7LbpZinqsIC7P5ZqRZHr7ge0OMlG4twlw3TAXGqEerA%3d&se=1493760863";
const char * userName="esprelay.azure-devices.net/1000";
const char * subscriptionName="devices/1000/messages/devicebound/#";
const int port=8883;

WiFiClientSecure espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  attachInterrupt(digitalPinToInterrupt(0), blink, CHANGE);
  pinMode(2, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '0') {
    digitalWrite(2, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(2, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    if (client.connect(deviceId,userName,pass)) {
      Serial.println("connected");
      // ... and resubscribe
      client.subscribe(subscriptionName);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, port);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

int inputVal=0;//should be read from eprom
void blink() {
  int val1 = digitalRead(0); 
  if(inputVal!=val1){
    inputVal=val1;
    digitalWrite(2,val1);  
  }
}
