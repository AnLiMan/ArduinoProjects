#include <TTP229.h>

const int SCL_PIN = 2;  // The pin number of the clock pin.
const int SDO_PIN = 3;  // The pin number of the data pin.

TTP229 ttp229(SCL_PIN, SDO_PIN); // TTP229(sclPin, sdoPin)

void setup()
{
	Serial.begin(115200);
	Serial.println("Start Touching One Key At a Time!");
}

void loop()
{
	uint8_t key = ttp229.ReadKey16(); // Blocking
	if (key) Serial.println(key);
}
