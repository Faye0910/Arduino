#include <SPI.h>
#include <moto_MFRC522.h>
MFRC522 rfid(10,9);
String dump_byte_array(byte *buffer, byte bufferSize) {
String uid;
for (byte i = 0; i < bufferSize; i++) {
uid+=String(buffer[i], HEX);
if(i < bufferSize-1)uid+=":";
}
return uid;
}
void setup()
{
Serial.begin(9600);
SPI.begin();
rfid.PCD_Init();
}
void loop()
{
if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
Serial.println(dump_byte_array(rfid.uid.uidByte, rfid.uid.size));
}
rfid.PICC_HaltA();
rfid.PCD_StopCrypto1();
}
