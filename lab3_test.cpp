#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#define STACK_SIZE   200
#define LED_PIN      6
void task1(void *p) {
	for (;;) {

	}
}
void setup() {
	pinMode(LED_PIN, OUTPUT);
}
void loop() {
	xTaskCreate(task1,         // Pointer to the task entry function
			"Task1",// Task name
			STACK_SIZE,// Stack size
			NULL,// Pointer to the parameters
			1,// Task priority
			NULL);// A handle by which the created task can be referenced.
	vTaskStartScheduler();
}
