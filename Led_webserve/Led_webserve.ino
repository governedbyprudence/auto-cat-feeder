
#include<ESP8266WebServer.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<Servo.h>

ESP8266WebServer server(80);
Servo left,right;
int state;
String ssid = "use bt ur own wifi";
String ssid_pass = "Deathrider";
String web_page = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>Auto Cat Feeder</title><script src='https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js'></script><script src='https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js'></script><link rel='StyleSheet' href='https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css'><script src='https://cdn.jsdelivr.net/npm/axios/dist/axios.min.js'></script></head><body class='justify-content-center'><navbar class='navbar-nav navbar-brand navbar-expand-lg bg-dark'><h3 style='color: white;'>Auto Cat Feeder</h3></navbar><h3 class='p-3'>.................................</h3><div class='p-3'><button class='btn btn-primary' id='turn_on'>Turn on</button><button class='btn btn-danger' id='turn_off'>Turn off</button></div></body><script>button_on=document.querySelector('#turn_on');button_off=document.querySelector('#turn_off');button_on.addEventListener('click',()=>axios.get('/on'));button_off.addEventListener('click',()=>axios.get('/off'));</script></html>";
int right_pin=5;
int left_pin=12;
void homepage(){
  server.send(200,"text/html",web_page);
}
void turn_off(){
  left.write(90); 
  right.write(0);
}
void turn_on(){
  left.write(0);
  right.write(90);
}

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  left.attach(left_pin);
  right.attach(right_pin);
  left.write(90);
  right.write(0);
  WiFi.begin(ssid,ssid_pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to : ");
  Serial.println(ssid);
  Serial.println("Use url : ");
  Serial.println(WiFi.localIP());
  
  server.on("/",homepage);
  server.on("/on",turn_on);
  server.on("/off",turn_off);
  //server.onNotFound(not_found);
  server.begin();
  Serial.println("Server Started");
}

void loop(){
  server.handleClient();
}
