#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200
#define LED_PIN1 6
#define LED_PIN2 7
#define LED_PIN3 8
#define LED_PIN4 9

void task1(void *p) {
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 1250;

	xLastWakeTime = xTaskGetTickCount();

	for (;;) {
		digitalWrite(LED_PIN1, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		digitalWrite(LED_PIN1, LOW);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void task2(void *p) {
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 2500;

	xLastWakeTime = xTaskGetTickCount();
	for (;;) {
		digitalWrite(LED_PIN2, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		digitalWrite(LED_PIN2, LOW);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void task3(void *p) {
	TickType_t xLastWakeTime;
	const TickType_t xFrequency = 5000;

	xLastWakeTime = xTaskGetTickCount();
	for (;;) {
		digitalWrite(LED_PIN3, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		digitalWrite(LED_PIN3, LOW);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
	}
}

void setup() {
	pinMode(LED_PIN1, OUTPUT);
	pinMode(LED_PIN2, OUTPUT);
	pinMode(LED_PIN3, OUTPUT);
}

void loop() {
	xTaskCreate(task1, // Pointer to the task entry function
				"Task1", // Task name
				STACK_SIZE, // Stack size
				NULL, // Pointer to the parameters
				1, // Task priority
				NULL); // A handle by which the created task can be referenced.
	xTaskCreate(task2, // Pointer to the task entry function
					"Task2", // Task name
					STACK_SIZE, // Stack size
					NULL, // Pointer to the parameters
					2, // Task priority
					NULL); // A handle by which the created task can be referenced.
	xTaskCreate(task3, // Pointer to the task entry function
					"Task3", // Task name
					STACK_SIZE, // Stack size
					NULL, // Pointer to the parameters
					3, // Task priority
					NULL); // A handle by which the created task can be referenced.

	vTaskStartScheduler();
}
