///**********   SAMPLE PROGRAM 2 **********/
//#include <Arduino.h>
//
//#define PIN_PTTM 0
//#define PIN_TOUCH 1
//
//void setup() {
//// initialize serial communications at 115200 bps:
//	Serial.begin(115200);
//}
//
//int remap_touch (int val) {
//	int temp = ((long)val*375)/1023;
//	return temp+75;
//}
//
//void loop() {
//	int val, touch;
//
//// read potentiometer's value
//	val = analogRead(PIN_PTTM);
//// read touch sensor's value
//	touch = analogRead(PIN_TOUCH);
//	touch = remap_touch(touch);
//
//// dump them to serial port
//	Serial.print(val);
//	Serial.print(" ");
//	Serial.print(touch);
//	Serial.println();
//
//// 200ms pause
//	delay(200);
//}
