/* Mahmudul Islam
 * EEE,Bangladesh University of Engineering and Technology (BUET)
 * Email: mahmudulislam299@gmail.com
 */
//E7 61 6B DD
//67 A9 63 DD
//87 F1 69 DD
//17 9F 66 DD
//55 96 3D E7

/*
* RC522 MODULE    Uno/Nano     MEGA
* SDA             D10          D9
* SCK             D13          D52
* MOSI            D11          D51
* MISO            D12          D50
* IRQ             N/A          N/A
* GND             GND          GND
* RST             D9           D8
* 3.3V            3.3V         3.3V
*/

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN D4
#define RST_PIN D2
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
char* rfid_id[]={"E7 61 6B DD","67 A9 63 DD","87 F1 69 DD","17 9F 66 DD","55 96 3D E7","02001047EABF","0200108156C5","0200108040D2","18003D858929","020010811182"};
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{

//  Serial.println("shuru");
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
//    Serial.println("funct 1");
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
//    Serial.println("funct 2");
    return;
  }

//  Serial.println("funct 1 and func2 par hoice");
  //Show UID on serial monitor
//  Serial.print("UID tag :");
  String cardID= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.println(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.println(mfrc522.uid.uidByte[i], HEX);
     cardID.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     cardID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.print("Message : ");
  cardID.toUpperCase();
//  Serial.println("");
  Serial.println(cardID);
  if (cardID.substring(1) == rfid_id[0]) //cardID.substring(1) change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    delay(3000);
  }
 
 else   {
    Serial.println(" Access denied");
    delay(3000);
  }
} 
