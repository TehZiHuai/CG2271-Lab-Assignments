#include <Arduino.h>
#include "prioq.h"
#define LED_RED 7
#define LED_YELLOW 6
#define DELAY 200
#define RED_INTERVAL 1000
#define YELLOW_INTERVAL 200

TPrioQueue *queue;
unsigned long lastDebounceTime = 0;
unsigned long timer_yellow = 0;
unsigned long timer_red = 0;
bool redState = 1;
bool yellowState = 1;

// Declares a new type called "funcptr"
typedef void (*funcptr)(void);

// Flashes LED at pin 7: 5 times at 5 Hz
void int0task() {
	Serial.println("task 0");
	int i = 0;
	while (i < 7) {
		if (millis() - timer_yellow >= YELLOW_INTERVAL) {
			timer_yellow = millis();
			digitalWrite(LED_YELLOW, yellowState);
			if (!yellowState) {
				Serial.println("blinked yellow");
				i += 1;
			}
			yellowState = !yellowState;
		}
	}
	yellowState = 1;
}

// Flashes LED at pin 6: 5 times at 1HZ
void int1task() {
	Serial.println("task 1");
	int i = 0;
	while (i < 5) {
		if (millis() - timer_red >= RED_INTERVAL) {
			timer_red = millis();
			digitalWrite(LED_RED, redState);
			if (!redState) {
				Serial.println("blinked red");
				i += 1;
			}
			redState = !redState;
		}
	}
	redState = 1;
}

void int0ISR() {
	// debounce button
	if (millis() - lastDebounceTime >= DELAY) {
		Serial.println("isr0");
		// enqueue the task 1 into the queue
		funcptr task = &int0task;
		enq(queue, (void *) task, 1);
	}
	lastDebounceTime = millis();
}

void int1ISR() {
	// debounce button
	if (millis() - lastDebounceTime >= DELAY) {
		Serial.println("isr1");
		// enqueue the task 1 into the queue
		funcptr task = &int1task;
		enq(queue, (void *) task, 0);
	}
	lastDebounceTime = millis();
}

void setup() {
	// create the priority queue
	queue = makeQueue();
	// attach interrupts to the relevant pins
	attachInterrupt(digitalPinToInterrupt(2), int0ISR, FALLING);
	attachInterrupt(digitalPinToInterrupt(3), int1ISR, FALLING);
	// setup the LEDs
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_YELLOW, OUTPUT);
	Serial.begin(115200);
}

// Dequeues and calls functions if the queue is not empty
void loop() {
	if (qlen(queue) > 0) {
		Serial.println("dequeueing");
		funcptr task;
		task = (funcptr) deq(queue);
		task();
	}
}
