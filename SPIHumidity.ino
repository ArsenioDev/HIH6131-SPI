#include <SPI.h>
const int slaveselect = 10;

SPISettings Hum(2000000, MSBFIRST, SPI_MODE0);
int Dat1, Dat2, Dat3, Dat4;

void setup() {
  Serial.begin(115200);
  pinMode(slaveselect, OUTPUT);
  SPI.setMISO(12);
  SPI.setSCK(13);
  SPI.begin();
  }

void loop() {
 SPI.beginTransaction(Hum);
 digitalWrite(slaveselect, LOW);
 SPI.transfer(0);
 delay(37);
 
 Dat1=SPI.transfer(0);
 byte Dat2=SPI.transfer(0);
 byte Dat3=SPI.transfer(0);
 byte Dat4=SPI.transfer(0);
 digitalWrite(slaveselect, HIGH);
 SPI.endTransaction();
 Serial.print(Dat1, BIN);//(( pow)(2, 14)-2))*(165-40));
 Serial.print(" ");
 Serial.print(Dat2, BIN);
 Serial.print(" ");
 Serial.print(Dat3, BIN);
 Serial.print(" ");
 Serial.println(Dat4, BIN);
 delay(100);
}
