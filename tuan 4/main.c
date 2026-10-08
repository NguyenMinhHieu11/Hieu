#include <stdint.h>

#include "stm32f10x.h"

#include "FreeRTOS.h"
#include "task.h"


/* =========================================================
   GPIO PA0, PA1, PA2
   ========================================================= */
static void GPIO_Init(void)
{
    /* Enable clock GPIOA */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    /* PA0, PA1, PA2 = Output Push-Pull, 2 MHz */
    GPIOA->CRL &= ~(
        (0xFUL << 0) |
        (0xFUL << 4) |
        (0xFUL << 8)
    );

    GPIOA->CRL |= (
        (0x2UL << 0) |
        (0x2UL << 4) |
        (0x2UL << 8)
    );

    /* Initial state = LOW */
    GPIOA->BRR =
        (1UL << 0) |
        (1UL << 1) |
        (1UL << 2);
}


/* =========================================================
   Toggle LED
   ========================================================= */
static void LED_Toggle(uint8_t pin)
{
    GPIOA->ODR ^= (1UL << pin);
}


/* =========================================================
   LED Blink Function
   pin       : LED GPIO pin
   frequency : blink frequency in Hz
   ========================================================= */
static void LED_Blink(uint8_t pin, float frequency)
{
    uint32_t delay_ms;

    /*
       Mỗi chu kỳ gồm:
       ON  -> OFF

       Vì vậy thời gian giữa 2 lần toggle:

       T/2 = 1 / (2*f)
    */

    delay_ms =
        (uint32_t)(1000.0f / (2.0f * frequency));

    while (1)
    {
        LED_Toggle(pin);

        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}


/* =========================================================
   Task LED1
   PA0 = 0.1 Hz
   ========================================================= */
static void LED_Task_01(void *argument)
{
    (void)argument;

    LED_Blink(0, 0.1f);
}


/* =========================================================
   Task LED2
   PA1 = 1 Hz
   ========================================================= */
static void LED_Task_02(void *argument)
{
    (void)argument;

    LED_Blink(1, 1.0f);
}


/* =========================================================
   Task LED3
   PA2 = 10 Hz
   ========================================================= */
static void LED_Task_03(void *argument)
{
    (void)argument;

    LED_Blink(2, 10.0f);
}


/* =========================================================
   MAIN
   ========================================================= */
int main(void)
{
    /* GPIO */
    GPIO_Init();


    /* Task LED1 */
    xTaskCreate(
        LED_Task_01,
        "LED01",
        128,
        NULL,
        1,
        NULL
    );


    /* Task LED2 */
    xTaskCreate(
        LED_Task_02,
        "LED02",
        128,
        NULL,
        1,
        NULL
    );


    /* Task LED3 */
    xTaskCreate(
        LED_Task_03,
        "LED03",
        128,
        NULL,
        1,
        NULL
    );


    /* Start FreeRTOS Scheduler */
    vTaskStartScheduler();


    /* Normally never reaches here */
    while (1)
    {
    }

    return 0;
}
