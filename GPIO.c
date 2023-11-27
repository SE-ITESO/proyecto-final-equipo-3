/*@File 	GPIO.c
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of setting up the
 *			configuration and functions for the use of GPIO's
*/

#include "GPIO.h"

irq_flags_t g_irq_flags_gpio;
volatile static void (*GPIO_callback1)(port_t port,uint32_t flags) = 0;
volatile static void (*GPIO_callback2)(port_t port,uint32_t flags) = 0;

void GPIO_turn_port_clock_on (port_t port){
	switch (port){
		case A:
			SIM_5 |= SIM5_PORTA_MASK;
			break;
		case B:
			SIM_5 |= SIM5_PORTB_MASK;
			break;
		case C:
			SIM_5 |= SIM5_PORTC_MASK;
			break;
		case D:
			SIM_5 |= SIM5_PORTD_MASK;
			break;
		case E:
			SIM_5 |= SIM5_PORTE_MASK;
			break;
		}
}

void GPIO_turn_port_clock_off (port_t port){
		switch (port){
			case A:
				SIM_5 &=~ SIM5_PORTA_MASK;
				break;
			case B:
				SIM_5 &=~ SIM5_PORTB_MASK;
				break;
			case C:
				SIM_5 &=~ SIM5_PORTC_MASK;
				break;
			case D:
				SIM_5 &=~ SIM5_PORTD_MASK;
				break;
			case E:
				SIM_5 &=~ SIM5_PORTE_MASK;
				break;
			}
}

void GPIO_set_pcr (port_t port,pin_t pin,uint32_t value){
	volatile uint32_t * address;
	switch (port){
		case A:
			address = PCR_PTA_BASE + pin;
			*address = value;
			break;
		case B:
			address = PCR_PTB_BASE + pin;
			*address = value;
			break;
		case C:
			address = PCR_PTC_BASE + pin;
			*address = value;
			break;
		case D:
			address = PCR_PTD_BASE + pin;
			*address = value;
			break;
		case E:
			address = PCR_PTE_BASE + pin;
			*address = value;
			break;
		}
}

void GPIO_PDOR (port_t port,uint32_t PDO){
	switch (port){
	case A:
		GPIO_A->PDOR = PDO;
		break;
	case B:
		GPIO_B->PDOR = PDO;
		break;
	case C:
		GPIO_C->PDOR = PDO;
		break;
	case D:
		GPIO_D->PDOR = PDO;
		break;
	case E:
		GPIO_E->PDOR = PDO;
		break;
	}
}

void GPIO_PSOR (port_t port,uint32_t PTSO){
	switch (port){
	case A:
		GPIO_A->PSOR = PTSO;
		break;
	case B:
		GPIO_B->PSOR = PTSO;
		break;
	case C:
		GPIO_C->PSOR = PTSO;
		break;
	case D:
		GPIO_D->PSOR = PTSO;
		break;
	case E:
		GPIO_E->PSOR = PTSO;
		break;
	}
}

void GPIO_PCOR (port_t port,uint32_t PTCO){
	switch (port){
	case A:
		GPIO_A->PCOR = PTCO;
		break;
	case B:
		GPIO_B->PCOR = PTCO;
		break;
	case C:
		GPIO_C->PCOR = PTCO;
		break;
	case D:
		GPIO_D->PCOR = PTCO;
		break;
	case E:
		GPIO_E->PCOR = PTCO;
		break;
	}
}

void GPIO_PTOR (port_t port,uint32_t PTTO){
	switch (port){
	case A:
		GPIO_A->PTOR = PTTO;
		break;
	case B:
		GPIO_B->PTOR = PTTO;
		break;
	case C:
		GPIO_C->PTOR = PTTO;
		break;
	case D:
		GPIO_D->PTOR = PTTO;
		break;
	case E:
		GPIO_E->PTOR = PTTO;
		break;
	}
}

uint32_t GPIO_PDIR (port_t port){
	uint32_t output = 0;
	switch (port){
	case A:
		output = GPIO_A->PDIR;
		break;
	case B:
		output = GPIO_B->PDIR;
		break;
	case C:
		output = GPIO_C->PDIR;
		break;
	case D:
		output = GPIO_D->PDIR;
		break;
	case E:
		output = GPIO_E->PDIR;
		break;
	}
	return output;
}

void GPIO_PDDR_W (port_t port,uint32_t PDD){
	switch (port){
	case A:
		GPIO_A->PDDR = PDD;
		break;
	case B:
		GPIO_B->PDDR = PDD;
		break;
	case C:
		GPIO_C->PDDR = PDD;
		break;
	case D:
		GPIO_D->PDDR = PDD;
		break;
	case E:
		GPIO_E->PDDR = PDD;
		break;
	}
}

uint32_t GPIO_PDDR_R (port_t port){
	uint32_t output = 0;
	switch (port){
	case A:
		output = GPIO_A->PDDR;
		break;
	case B:
		output = GPIO_B->PDDR;
		break;
	case C:
		output = GPIO_C->PDDR;
		break;
	case D:
		output = GPIO_D->PDDR;
		break;
	case E:
		output = GPIO_E->PDDR;
		break;
	}
	return output;
}

uint8_t GPIO_get_pin_direction (port_t port, pin_t pin){
	uint32_t port_value = GPIO_PDDR_R(port);
	uint32_t bit_2_get = 0x1 << pin;
	uint32_t pin_value = bit_2_get & port_value;
	if (0 == pin_value)
		return 0;
	else
		return 1;
}

uint8_t GPIO_get_pin_value (port_t port, pin_t pin){
	uint32_t port_value = GPIO_PDIR(port);
	uint32_t bit_2_get = 0x1 << pin;
	uint32_t pin_value = bit_2_get & port_value;
	if (0 == pin_value)
		return 0;
	else
		return 1;
}

void GPIO_toggle_pin_value (port_t port, pin_t pin){
	uint32_t bit_2_get = 0x1 << pin;
	GPIO_PTOR(port,bit_2_get);
}

void GPIO_set_pin_value_on (port_t port,pin_t pin){
	uint32_t bit_2_get = 0x1 << pin;
	GPIO_PSOR(port,bit_2_get);
}

void GPIO_set_pin_value_off (port_t port,pin_t pin){
	uint32_t bit_2_get = 0x1 << pin;
	GPIO_PCOR(port,bit_2_get);
}

static void GPIO_clear_port_interrupt_flags(port_t port,uint32_t value){
	volatile uint32_t * address;
		switch (port){
			case A:
				address = PCR_PTA_BASE + ISFR_OFFSET_FROM_PCR;
				*address = value;
				break;
			case B:
				address = PCR_PTB_BASE + ISFR_OFFSET_FROM_PCR;
				*address = value;
				break;
			case C:
				address = PCR_PTC_BASE + ISFR_OFFSET_FROM_PCR;
				*address = value;
				break;
			case D:
				address = PCR_PTD_BASE + ISFR_OFFSET_FROM_PCR;
				*address = value;
				break;
			case E:
				address = PCR_PTE_BASE + ISFR_OFFSET_FROM_PCR;
				*address = value;
				break;
			}
}

static uint32_t GPIO_GetPortInterruptFlag(port_t port){
	uint32_t output;
	switch (port){
		case A:
			output = ISR_PTA;
			break;
		case B:
			output = ISR_PTB;
			break;
		case C:
			output = ISR_PTC;
			break;
		case D:
			output = ISR_PTD;
			break;
		case E:
			output = ISR_PTE;
			break;
	}
	return output;
}


void PORTB_IRQHandler (){
	uint32_t irq_status = 0;
	irq_status = GPIO_GetPortInterruptFlag(B);
	if(GPIO_callback1){
		GPIO_callback1(B,irq_status);
	}
	GPIO_clear_port_interrupt_flags(B, FULL_CLEAR);
}

void PORTC_IRQHandler(){
	uint32_t irq_status = 0;
	irq_status = GPIO_GetPortInterruptFlag(C);
	if(GPIO_callback2){
		GPIO_callback2(C,irq_status);
	}
	GPIO_clear_port_interrupt_flags(C, FULL_CLEAR);
}


void GPIO_Enable_IRQ(){
	//ENCENDER INTERRUPCIONES PARA TODOS LOS PINES NECESARIOS
	volatile uint32_t * temp_address;
	//PI-DOWN
	temp_address = PCR_PTB_BASE + pin19;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P1-LEFT
	temp_address = PCR_PTB_BASE + pin18;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P1-RIGHT
	temp_address = PCR_PTB_BASE + pin9;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P1-ROTATE
	temp_address = PCR_PTB_BASE + pin23;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P1-HOLD
	temp_address = PCR_PTB_BASE + pin2;
	* temp_address |= PCR_INTERRUPT_VALUE;

	//P2-DOWN
	temp_address = PCR_PTC_BASE + pin1;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P2-LEFT
	temp_address = PCR_PTC_BASE + pin8;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P2-RIGHT
	temp_address = PCR_PTC_BASE + pin9;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P2-ROTATE
	temp_address = PCR_PTC_BASE + pin0;
	* temp_address |= PCR_INTERRUPT_VALUE;
	//P2-HOLD
	temp_address = PCR_PTC_BASE + pin10;
	* temp_address |= PCR_INTERRUPT_VALUE;
}

void GPIO_Disable_IRQ(){
	//ENCENDER INTERRUPCIONES PARA TODOS LOS PINES NECESARIOS
	volatile uint32_t * temp_address;
	//PI-DOWN
	temp_address = PCR_PTB_BASE + pin19;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P1-LEFT
	temp_address = PCR_PTB_BASE + pin18;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P1-RIGHT
	temp_address = PCR_PTB_BASE + pin9;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P1-ROTATE
	temp_address = PCR_PTB_BASE + pin23;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P1-HOLD
	temp_address = PCR_PTB_BASE + pin2;
	* temp_address &= ~PCR_INTERRUPT_VALUE;

	//P2-DOWN
	temp_address = PCR_PTC_BASE + pin1;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P2-LEFT
	temp_address = PCR_PTC_BASE + pin8;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P2-RIGHT
	temp_address = PCR_PTC_BASE + pin9;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P2-ROTATE
	temp_address = PCR_PTC_BASE + pin0;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
	//P2-HOLD
	temp_address = PCR_PTC_BASE + pin10;
	* temp_address &= ~PCR_INTERRUPT_VALUE;
}


uint8_t GPIO_GetIRQflag(port_t port){
	switch(port){
		case A:
			return g_irq_flags_gpio.irq_flags_A;
		case B:
			return g_irq_flags_gpio.irq_flags_B;
		case C:
			return g_irq_flags_gpio.irq_flags_C;
		case D:
			return g_irq_flags_gpio.irq_flags_D;
		default:
			return g_irq_flags_gpio.irq_flags_E;
	}
}

void GPIO_ClearIRQflag(port_t port){
	switch(port){
	case A:
		g_irq_flags_gpio.irq_flags_A = 0;
		break;
	case B:
		g_irq_flags_gpio.irq_flags_B = 0;
		break;
	case C:
		g_irq_flags_gpio.irq_flags_C = 0;
		break;
	case D:
		g_irq_flags_gpio.irq_flags_D = 0;
		break;
	case E:
		g_irq_flags_gpio.irq_flags_E = 0;
		break;
	}
}

void GPIO_ClearAllIRQFlags(){
	 GPIO_ClearIRQflag(A);
	 GPIO_ClearIRQflag(B);
	 GPIO_ClearIRQflag(C);
	 GPIO_ClearIRQflag(D);
}

void GPIO_callback_init(void (*handler1)(port_t port,uint32_t flags),void (*handler2)(port_t port,uint32_t flags)){
	GPIO_callback1 = handler1;
	GPIO_callback2 = handler2;
}

void GPIO_init(){
	GPIO_turn_port_clock_on (B); //Encender clock
	GPIO_turn_port_clock_on (C); //Encender clock
	GPIO_turn_port_clock_on (D); //Encender clock

	//PINES PLAYER
	GPIO_set_pcr(B, pin19,PCR_INPUT_CONFIG);	//DOWN
	GPIO_set_pcr(B, pin18,PCR_INPUT_CONFIG);	//LEFT
	GPIO_set_pcr(B, pin9,PCR_INPUT_CONFIG);		//RIGHT
	GPIO_set_pcr(B, pin23,PCR_INPUT_CONFIG);	//ROTATE
	GPIO_set_pcr(B, pin10,PCR_INPUT_CONFIG);	//HOLD

	GPIO_set_pcr(C, pin1,PCR_INPUT_CONFIG);		//DOWN
	GPIO_set_pcr(C, pin8,PCR_INPUT_CONFIG);		//LEFT
	GPIO_set_pcr(C, pin9,PCR_INPUT_CONFIG);		//RIGHT
	GPIO_set_pcr(C, pin0,PCR_INPUT_CONFIG);		//ROTATE
	GPIO_set_pcr(C, pin10,PCR_INPUT_CONFIG);	//HOLD

	//I2C
	GPIO_set_pcr(B, pin2,PCR_I2C_CONFIG);	//CLK
	GPIO_set_pcr(B, pin3,PCR_I2C_CONFIG);	//SDA

	//LCD AND MEMORY
	GPIO_set_pcr(D, pin0,PCR_FOR_SPI);	//CS0
	GPIO_set_pcr(D, pin1,PCR_FOR_SPI);	//SCK
	GPIO_set_pcr(D, pin2,PCR_FOR_SPI);	//DATA
	GPIO_set_pcr(C, pin3,PCR_FOR_SPI);	//CS1

	GPIO_set_pcr(C, pin5,PCR_OUTPUT_CONFIG);	//DC
	GPIO_set_pcr(C, pin7,PCR_OUTPUT_CONFIG);	//RST

	//Direction
	GPIO_PDDR_W (B,PDDR_PTB);
	GPIO_PDDR_W (C,PDDR_PTC);
	GPIO_PDDR_W (D,PDDR_PTD);


}
