/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 */

#include <EEPROM.h>
#include <SPI.h>
#include <MFRC522.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

#define SS_PIN D4
#define RST_PIN D2
#define buzzer D1
#define red_led D0
#define green_led D8
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
HTTPClient http;    //Declare object of class HTTPClient

char* ValidCard_id[]={"020010811182", "E7 61 6B DD","67 A9 63 DD","87 F1 69 DD","17 9F 66 DD","55 96 3D E7","21 9D 2E 30","0200108156C5","0200108040D2","18003D858929"};
char* names[]={"khali","MAHMUD","NABID","NAIMA","SHIFA","JOJO","PRINCE","TRACY","JIMMY","DANIEL"};
char* sid[]={"1506100","1506101","1506102","1506103","1506104","1506105","1506106","1506107","1506108","1506109"};
char* sequence[]={"0","1","2","3","4","5","6","7","8","9"};

const char *ssid = "******";  
const char *password = "******";

//Web/Server address to read/write from 
const char *host = "192.168.0.106";  
int presence[10];
 String cardID= "";


 String state, postData;

long pm=0;
int i=0,j=0, presentNum=0;
int n,p,q;


void setup() {
  rfid_begin();
  eeprom_begin();
  led_buzzer_begin();
  website_begin();  
}
void website_begin(){
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}
void led_buzzer_begin(){
  pinMode(buzzer,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
}
void eeprom_begin(){
  presentNum=EEPROM.read(1000);
  for(i=0;i<10;i++) 
  presence[i]=EEPROM.read(i);
}
void rfid_begin() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  Serial.println("RFID start reading......");
}
 
void loop() {

  check_rfid();



   for( n=0; n<10; n++)
{
  if(cardID.substring(1)==ValidCard_id[n])//User1 rfid received
        {
          
          cardID="";
         if(presence[n]==0 || presence[n]==2){
          presence[n]=1;

          state = "Present";
          website();
          Serial.print("WELCOME "); Serial.println(names[n]); 
          digitalWrite(buzzer,HIGH); digitalWrite(green_led,HIGH); delay(1000);
          digitalWrite(buzzer,LOW); digitalWrite(green_led,LOW);delay(2000);
          presentNum++; EEPROM.write(1000,presentNum);
          

  }

         else{
         presence[n]=2;

         state = "Left";
         website();
         Serial.print("SEE YOU "); Serial.println(names[n]);
          digitalWrite(buzzer,HIGH); digitalWrite(green_led,HIGH); delay(1000);
          digitalWrite(buzzer,LOW); digitalWrite(green_led,LOW);delay(2000);
          presentNum--;  EEPROM.write(1000,presentNum);  
              
      }   
      break;        
        }
}

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}

void check_rfid(){
  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

cardID= "";
  for (byte i = 0; i < rfid.uid.size; i++) 
  {
//     Serial.println(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
//     Serial.println(rfid.uid.uidByte[i], HEX);
     cardID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
     cardID.concat(String(rfid.uid.uidByte[i], HEX));
  }

  Serial.print("cardID : ");
  cardID.toUpperCase();
  Serial.println(cardID);
}

void website() {
  //Post Data
  postData = String("sid=") + sequence[n] + String("&name=") + names[n] +String("&state=") + state ;
  Serial.println(postData);

  
  http.begin("http://192.168.0.106/studentattendance/postdemo.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection
  
}
