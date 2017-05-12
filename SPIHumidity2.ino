#include <SPI.h>
const int slaveselect = 10;

SPISettings Hum(100000, MSBFIRST, SPI_MODE0);
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
 
 byte Dat1=SPI.transfer(0);
 byte Dat2=SPI.transfer(0);
 byte Dat3=SPI.transfer(0);
 byte Dat4=SPI.transfer(0);
 digitalWrite(slaveselect, HIGH);
uint16_t data = ((Dat4 & 0xff) << 8 | Dat2);
uint16_t data1 = ((Dat4));

 Serial.print(data);
  Serial.print("\t");
 Serial.print(data1);
 Serial.print("\t");
 Serial.print((data/(pow(2,14) -2)*(100)));
  Serial.print("\t");
  Serial.println((data1/(pow(2,14))*(165) - 40));
 SPI.endTransaction();
 //Serial.print(Dat1, BIN);//(( pow)(2, 14)-2))*(100));
 //Serial.print(" ");
 //Serial.print(Dat2, BIN);
 //Serial.print(" ");
 //Serial.print(Dat3, BIN);
 //Serial.print(" ");
 //Serial.println(Dat4, BIN);
 delay(10);
}
