#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
  Serial.begin(9600);	  // Debugging
  if (!driver.init())
    Serial.println("init failed");
}

void loop()
{
  const char *msg = "5";
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(1000);
}
