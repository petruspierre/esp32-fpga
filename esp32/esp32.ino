#include <WiFi.h>

#define ssid "Digital"
#define password "123123123"

#define R 13
#define D0 12
#define D1 14
#define D2 27
#define D3 26
#define EN 25

WiFiClient client;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(EN, OUTPUT);

  pinMode(R, INPUT);
  
  configurarWifi();
}

void loop(){
  client = server.available();   // listen for incoming clients

  if(client){
    String req = client.readStringUntil('\r');
    
    if(req.indexOf("/0")!= -1){

      digitalWrite(D0,0);
      digitalWrite(D1,0);
      digitalWrite(D2,0);
      digitalWrite(D3,0);
      
      delay(10);
      
      digitalWrite(EN,1);

      delay(100);
      
      Serial.print("O estado da chave 0 é: ");
      Serial.println(digitalRead(R));

      digitalWrite(EN,0);
      delay(10);
      
    }
  }
 
}


void configurarWifi(){
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("|");
    delay(200);
  }
  Serial.println();
  Serial.println("Conectado com sucesso.");
  Serial.print("Servidor hospedado em: ");
  Serial.println(WiFi.localIP());
}
