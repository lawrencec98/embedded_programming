#include "tm4c_cmsis.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void GPIOPortA_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortB_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortD_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortE_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SSI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWMFault_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void QEI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Watchdog_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Comp0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Comp1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Comp2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SysCtrl_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FlashCtrl_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortF_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortH_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SSI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void QEI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Hibernate_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAST_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAError_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2S0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void EBI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortJ_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortL_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SSI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SSI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PECI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LPC0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortN_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void QEI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void Fan0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortR_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortS_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Fault_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const int __VECTOR_TABLE[];
       const int __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (int)(&__INITIAL_SP),  			   /*     Initial Stack Pointer */
  (int)Reset_Handler,                       /*     Reset Handler */
  (int)NMI_Handler,                         /* -14 NMI Handler */
  (int)HardFault_Handler,                   /* -13 Hard Fault Handler */
  (int)MemManage_Handler,                   /* -12 MPU Fault Handler */
  (int)BusFault_Handler,                    /* -11 Bus Fault Handler */
  (int)UsageFault_Handler,                  /* -10 Usage Fault Handler */
  (int)SecureFault_Handler,                 /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  (int)SVC_Handler,                         /*  -5 SVCall Handler */
  (int)DebugMon_Handler,                    /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  (int)PendSV_Handler,                      /*  -2 PendSV Handler */
  (int)SysTick_Handler,                     /*  -1 SysTick Handler */
  (int)GPIOPortA_IRQHandler,
(int)GPIOPortB_IRQHandler,
(int)GPIOPortC_IRQHandler,
(int)GPIOPortD_IRQHandler,
(int)GPIOPortE_IRQHandler,
(int)UART0_IRQHandler,
(int)UART1_IRQHandler,
(int)SSI0_IRQHandler,
(int)I2C0_IRQHandler,
(int)PWMFault_IRQHandler,
(int)PWMGen0_IRQHandler,
(int)PWMGen1_IRQHandler,
(int)PWMGen2_IRQHandler,
(int)QEI0_IRQHandler,
(int)ADCSeq0_IRQHandler,
(int)ADCSeq1_IRQHandler,
(int)ADCSeq2_IRQHandler,
(int)ADCSeq3_IRQHandler,
(int)Watchdog_IRQHandler,
(int)Timer0A_IRQHandler,
(int)Timer0B_IRQHandler,
(int)Timer1A_IRQHandler,
(int)Timer1B_IRQHandler,
(int)Timer2A_IRQHandler,
(int)Timer2B_IRQHandler,
(int)Comp0_IRQHandler,
(int)Comp1_IRQHandler,
(int)Comp2_IRQHandler,
(int)SysCtrl_IRQHandler,
(int)FlashCtrl_IRQHandler,
(int)GPIOPortF_IRQHandler,
(int)GPIOPortG_IRQHandler,
(int)GPIOPortH_IRQHandler,
(int)UART2_IRQHandler,
(int)SSI1_IRQHandler,
(int)Timer3A_IRQHandler,
(int)Timer3B_IRQHandler,
(int)I2C1_IRQHandler,
(int)QEI1_IRQHandler,
(int)CAN0_IRQHandler,
(int)CAN1_IRQHandler,
(int)CAN2_IRQHandler,
(int)Hibernate_IRQHandler,
(int)USB0_IRQHandler,
(int)PWMGen3_IRQHandler,
(int)uDMAST_IRQHandler,
(int)uDMAError_IRQHandler,
(int)ADC1Seq0_IRQHandler,
(int)ADC1Seq1_IRQHandler,
(int)ADC1Seq2_IRQHandler,
(int)ADC1Seq3_IRQHandler,
(int)I2S0_IRQHandler,
(int)EBI0_IRQHandler,
(int)GPIOPortJ_IRQHandler,
(int)GPIOPortK_IRQHandler,
(int)GPIOPortL_IRQHandler,
(int)SSI2_IRQHandler,
(int)SSI3_IRQHandler,
(int)UART3_IRQHandler,
(int)UART4_IRQHandler,
(int)UART5_IRQHandler,
(int)UART6_IRQHandler,
(int)UART7_IRQHandler,
(int)I2C2_IRQHandler,
(int)I2C3_IRQHandler,
(int)Timer4A_IRQHandler,
(int)Timer4B_IRQHandler,
(int)Timer5A_IRQHandler,
(int)Timer5B_IRQHandler,
(int)WideTimer0A_IRQHandler,
(int)WideTimer0B_IRQHandler,
(int)WideTimer1A_IRQHandler,
(int)WideTimer1B_IRQHandler,
(int)WideTimer2A_IRQHandler,
(int)WideTimer2B_IRQHandler,
(int)WideTimer3A_IRQHandler,
(int)WideTimer3B_IRQHandler,
(int)WideTimer4A_IRQHandler,
(int)WideTimer4B_IRQHandler,
(int)WideTimer5A_IRQHandler,
(int)WideTimer5B_IRQHandler,
(int)FPU_IRQHandler,
(int)PECI0_IRQHandler,
(int)LPC0_IRQHandler,
(int)I2C4_IRQHandler,
(int)I2C5_IRQHandler,
(int)GPIOPortM_IRQHandler,
(int)GPIOPortN_IRQHandler,
(int)QEI2_IRQHandler,
(int)Fan0_IRQHandler,
(int)GPIOPortP0_IRQHandler,
(int)GPIOPortP1_IRQHandler,
(int)GPIOPortP2_IRQHandler,
(int)GPIOPortP3_IRQHandler,
(int)GPIOPortP4_IRQHandler,
(int)GPIOPortP5_IRQHandler,
(int)GPIOPortP6_IRQHandler,
(int)GPIOPortP7_IRQHandler,
(int)GPIOPortQ0_IRQHandler,
(int)GPIOPortQ1_IRQHandler,
(int)GPIOPortQ2_IRQHandler,
(int)GPIOPortQ3_IRQHandler,
(int)GPIOPortQ4_IRQHandler,
(int)GPIOPortQ5_IRQHandler,
(int)GPIOPortQ6_IRQHandler,
(int)GPIOPortQ7_IRQHandler,
(int)GPIOPortR_IRQHandler,
(int)GPIOPortS_IRQHandler,
(int)PWM1Gen0_IRQHandler,
(int)PWM1Gen1_IRQHandler,
(int)PWM1Gen2_IRQHandler,
(int)PWM1Gen3_IRQHandler,
(int)PWM1Fault_IRQHandler

};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
} 

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/

void Default_Handler(void)
{
	#define LED_RED   (1U << 1)
	GPIOF_AHB->DATA_Bits[LED_RED] ^= LED_RED;
}

/*
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
*/