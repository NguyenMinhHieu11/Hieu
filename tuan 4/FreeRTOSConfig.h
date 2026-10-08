#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/* =========================
 * CPU CLOCK
 * STM32F103C8: HSI = 8 MHz
 * ========================= */
#define configCPU_CLOCK_HZ              ( ( uint32_t ) 8000000UL )

/* FreeRTOS tick = 1 ms */
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )

/* =========================
 * TASK CONFIGURATION
 * ========================= */
#define configMAX_PRIORITIES             5
#define configMINIMAL_STACK_SIZE         128
#define configMAX_TASK_NAME_LEN          16

/* =========================
 * MEMORY
 * ========================= */
#define configTOTAL_HEAP_SIZE            ( ( size_t ) ( 10 * 1024 ) )

#define configSUPPORT_DYNAMIC_ALLOCATION 1
#define configSUPPORT_STATIC_ALLOCATION  0

/* =========================
 * SCHEDULER
 * ========================= */
#define configUSE_PREEMPTION             1
#define configUSE_IDLE_HOOK              0
#define configUSE_TICK_HOOK              0

/* =========================
 * TICK
 * ========================= */
#define configUSE_16_BIT_TICKS            0

/* =========================
 * API FUNCTIONS
 * ========================= */
#define INCLUDE_vTaskDelay                1
#define INCLUDE_vTaskDelete               1
#define INCLUDE_vTaskSuspend              1

/* =========================
 * INTERRUPT PRIORITY
 * ========================= */
#define configPRIO_BITS                   4

#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY       15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY  5

#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << ( 8 - configPRIO_BITS ) )

/* =========================
 * ASSERT
 * ========================= */
#define configASSERT( x )                                      \
    if( ( x ) == 0 )                                           \
    {                                                           \
        taskDISABLE_INTERRUPTS();                              \
        for( ;; );                                               \
    }

/* =========================
 * HANDLER INSTALLATION
 * ========================= */
#define configCHECK_HANDLER_INSTALLATION 1

#endif
