#include <stdint.h>

extern int main(void);

extern uint32_t _estack;

/* Các symbol do linker cung cấp */
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;


/* FreeRTOS interrupt handlers */
extern void vPortSVCHandler(void);
extern void xPortPendSVHandler(void);
extern void xPortSysTickHandler(void);


/* Reset handler */
void Reset_Handler(void);
void Default_Handler(void);


/* =========================
   Exception handlers
   ========================= */

void NMI_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void HardFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void MemManage_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void BusFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

void UsageFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));


/* =========================
   Peripheral handlers
   ========================= */

void WWDG_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void PVD_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TAMPER_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void RTC_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void FLASH_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void RCC_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel5_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel6_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void DMA1_Channel7_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void ADC1_2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USB_HP_CAN1_TX_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USB_LP_CAN1_RX0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void CAN1_RX1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void CAN1_SCE_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI9_5_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM1_BRK_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM1_UP_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM1_TRG_COM_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM1_CC_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void TIM4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void I2C1_EV_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void I2C1_ER_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void I2C2_EV_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void I2C2_ER_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void SPI1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void SPI2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USART1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USART2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USART3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void EXTI15_10_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void RTCAlarm_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

void USBWakeUp_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));


/* =========================
   Vector table
   ========================= */

__attribute__((section(".isr_vector"), used))
const void *vector_table[] =
{
    (void *)&_estack,

    Reset_Handler,

    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,

    0,
    0,
    0,
    0,

    /* SVC */
    vPortSVCHandler,

    /* Debug monitor */
    Default_Handler,

    0,

    /* PendSV */
    xPortPendSVHandler,

    /* SysTick */
    xPortSysTickHandler,

    WWDG_IRQHandler,
    PVD_IRQHandler,
    TAMPER_IRQHandler,
    RTC_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,

    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,

    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    DMA1_Channel5_IRQHandler,
    DMA1_Channel6_IRQHandler,
    DMA1_Channel7_IRQHandler,

    ADC1_2_IRQHandler,

    USB_HP_CAN1_TX_IRQHandler,
    USB_LP_CAN1_RX0_IRQHandler,

    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,

    EXTI9_5_IRQHandler,

    TIM1_BRK_IRQHandler,
    TIM1_UP_IRQHandler,
    TIM1_TRG_COM_IRQHandler,
    TIM1_CC_IRQHandler,

    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,

    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,

    SPI1_IRQHandler,
    SPI2_IRQHandler,

    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,

    EXTI15_10_IRQHandler,
    RTCAlarm_IRQHandler,
    USBWakeUp_IRQHandler
};


/* =========================
   Reset Handler
   ========================= */

void Reset_Handler(void)
{
    uint32_t *src;
    uint32_t *dst;

    /* -------------------------
       Copy .data from Flash
       to RAM
       ------------------------- */

    src = &_sidata;
    dst = &_sdata;

    while (dst < &_edata)
    {
        *dst++ = *src++;
    }


    /* -------------------------
       Clear .bss
       ------------------------- */

    dst = &_sbss;

    while (dst < &_ebss)
    {
        *dst++ = 0;
    }


    /* -------------------------
       Start main()
       ------------------------- */

    main();

    while (1)
    {
    }
}


/* =========================
   Default Handler
   ========================= */

void Default_Handler(void)
{
    while (1)
    {
    }
}
