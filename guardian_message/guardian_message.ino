/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 */

#include <SoftwareSerial.h>
SoftwareSerial Serialdata(10,11); //(rx,tx)
String p;
int x,num,num1,num2;
char phone_no[] = "+88018********"; 

#define buzzer 48
char* names[]={"null","Ordatun Jannat","Rahad Arman Nabid","Nafhatul Zinan Shifa","Naima Tasnim","Mahmudul Islam","Sheikh Tabrej Alam","X","Y","Z"};
String text;

void setup() {
  message_begin();
  Serialdata.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void message_begin()
{
Serial.begin(9600);  //Open Serial connection at baud 9600
delay(2000);
Serial.println("AT+CMGF=1"); //set GSM to text mode
delay(200);
Serial.println("message begin end");
}

void loop() {
if (Serialdata.available()) {
    Serial.println("");
    Serial.println("data asche");
    p= Serialdata.readString();
    num=p.toInt();
    Serial.println(num);
    num1=num/10;
    num2=num%10;
    if(num2==1){
      text= names[num1] + String(" is at university now");
    }
    else if (num2==2){
      text= names[num1] + String(" has left university");
    }
     guardian();
      }

    }

void guardian()
{ 
  digitalWrite(buzzer,HIGH);  
  delay(1000);
  digitalWrite(buzzer,LOW);   
  delay(1000);
  message();
  delay(4000);
  Serial.println("msg done");
  delay(1000);
   
}

void call(){
  delay(500);
  Serial.print("ATD");; //Dial the phone number using ATD command
  Serial.print(phone_no);
  Serial.println(";"); // Semicolon is a must at the end
  delay(12000);
  Serial.println("ATH"); // After a delay of 5 secs Hang the call
  
}

void message()
{
 Serial.print("AT+CMGS=\"");
Serial.print(phone_no);
Serial.println("\"");

delay(1000);  // delay is must it waits for > symbol

//Serial.print("absent");  //SMS body
Serial.print(text);  //SMS body
Serial.write(0x1A);  // sends ctrl+z end of message
//Serial.write(0x0D);  // Carriage Return in Hex
//Serial.write(0x0A);  // Line feed in Hex

//The 0D0A pair of characters is the signal for the end of a line and beginning of another.
delay(1000); 
}
