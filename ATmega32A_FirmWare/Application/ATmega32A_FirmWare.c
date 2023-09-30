/*
 * ATmega32A_FirmWare.c
 *
 * Created: 8/4/2019 9:17:00 PM
 *  Author: Ahmed
 */ 


#include <ATmega32A_GPIO.h>
#include <Atmega32A_Interrupt.h>
#include <ATmega32A_Timer0.h>



volatile uint32_t Led_Counter = 0;
volatile uint32_t BUzzer_Counter=0;

void LED_BlinkTask(void)
{
	Led_Counter++;
	BUzzer_Counter++;
	if (Led_Counter >=244 )
	{
		GPIOC->Port.Bits.B2 = ! GPIOC->Port.Bits.B2;
		Led_Counter=0;
	}
	
	if (BUzzer_Counter >= 488)
	{
		GPIOC->Port.Bits.B5 = ! GPIOC->Port.Bits.B5;
		BUzzer_Counter=0;
	}
}
int main(void)
{
	GPIO_DirectionSet(GPIOC,PIN2,OUTPUT);
	GPIO_DirectionSet(GPIOC,PIN5,OUTPUT);
	Timer0_Init(
				Timer0_FCPU_DIV256,
				T0_NormalMode,
				Timer_outDisabled,
				Timer0_OVF_IntEnable);
	Timer0_ISR_OVF = LED_BlinkTask;
	GLOBAL_INETERRUPT_ENABLE();
	while(1)
    {		

				
    }
}

