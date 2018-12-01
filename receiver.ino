#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;
String data;
void setup()
{
  pinMode(5, OUTPUT);
  Serial.begin(9600);	// Debugging
  if (!driver.init())
    Serial.println("init failed");
}

void loop()
{
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen))
  {
    Serial.print("Message: ");
    Serial.println((char*)buf);
    data = ((char*)buf);
    Serial.println(data);
    if (data) {
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
    }
    else {
      digitalWrite(5, LOW);
    }
  }
}
