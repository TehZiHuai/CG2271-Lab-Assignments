//#include <Arduino.h>
//#define PIN_LED  6
//#define PIN_LED_TOUCH 7
//#define PIN_PTTM A0
//#define PIN_TOUCH A1
//#define DELAY 75
//#define INT_POT 2
//#define INT_TOUCH 3
//
//unsigned long lastDebounceTimePot = 0;
//unsigned long lastDebounceTimeTouch = 0;
//unsigned long previousMillis = 0;
//int potPinState = 0;
//int lastPotState = 0;
//int touchPinState = 0;
//int lastTouchState = 0;
//int permaVal = 0;
//long permaTouch = 0;
//bool ledState = 0;
//bool flagPot = 0;
//bool flagTouch = 0;
//
//void isr_pot() {
//	potPinState = digitalRead(INT_POT);
//	if (millis() - lastDebounceTimePot >= DELAY
//			&& (potPinState == 1 && lastPotState == 0)) {
//		flagPot = 1;
//	}
//	lastDebounceTimePot = millis();
//	lastPotState = potPinState;
//}
//
//void isr_touch() {
//	touchPinState = digitalRead(INT_TOUCH);
//	if (millis() - lastDebounceTimeTouch >= DELAY
//			&& (touchPinState == 1 && lastTouchState == 0)) {
//		flagTouch = 1;
//	}
//	lastDebounceTimeTouch = millis();
//	lastTouchState = touchPinState;
//}
//
//void setup() {
//	pinMode(PIN_LED, OUTPUT);
//	pinMode(PIN_LED_TOUCH, OUTPUT);
//	attachInterrupt(digitalPinToInterrupt(2), isr_pot, CHANGE);
//	attachInterrupt(digitalPinToInterrupt(3), isr_touch, CHANGE);
//	Serial.begin(115200);
//}
//
//long remap_touch(long touch) {
//	long temp = round((touch * 375) / 1023.0);
//	return temp + 75;
//}
//
//long remap(long val) {
//	return round((val * 255) / 2013.0);
//}
//
//void touchBlink(long touch) {
//	if (!flagTouch) {
//		for (int i = 0; i < 50; i++) {
//			touch = analogRead(PIN_TOUCH);
//		}
//		touch = remap_touch(touch);
//		Serial.println(touch);
//		permaTouch = touch;
//		if (millis() - previousMillis >= touch) {
//			previousMillis = millis();
//			ledState = !ledState;
//		}
//		digitalWrite(PIN_LED_TOUCH, ledState);
//	} else {
//		if (millis() - previousMillis >= permaTouch) {
//			previousMillis = millis();
//			ledState = !ledState;
//		}
//		digitalWrite(PIN_LED_TOUCH, ledState);
//	}
//}
//
//void potBright(int val) {
//	if (!flagPot) {
//		for (int i = 0; i < 50; i++) {
//			val = analogRead(PIN_PTTM);
//		}
//		val = remap(val);
//		permaVal = val;
//		analogWrite(PIN_LED, val);
//	} else {
//		analogWrite(PIN_LED, permaVal);
//	}
//}
//
//void loop() {
//	long val = 0;
//	long touch = 0;
//	touchBlink(touch);
//	potBright(val);
//}
