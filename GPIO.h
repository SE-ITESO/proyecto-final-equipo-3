/*@File 	GPIO.h
 *
 *@Authors 	Pedro Fregoso
 *			Andres Nuñez
 *
 *@Brief	This file is capable of defining the functions Macros and data types
 *			for the use of GPIO's
*/


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>


//Data types and config
typedef struct
{
	uint32_t PDOR;
	uint32_t PSOR;
	uint32_t PCOR;
	uint32_t PTOR;
	uint32_t PDIR;
	uint32_t PDDR;
}GPIO_t;


typedef enum{
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
	pin8,
	pin9,
	pin10,
	pin11,
	pin12,
	pin13,
	pin14,
	pin15,
	pin16,
	pin17,
	pin18,
	pin19,
	pin20,
	pin21,
	pin22,
	pin23,
	pin24,
	pin25,
	pin26,
	pin27,
	pin28,
	pin29,
	pin30,
	pin31
}pin_t;

typedef enum{
	A,
	B,
	C,
	D,
	E
}port_t;

//Direcciones base de soporte
#define SIM_5 (*((volatile uint32_t *) 0x40048038))

#define PCR_PTA_BASE (((volatile uint32_t *) 0x40049000))
#define PCR_PTB_BASE (((volatile uint32_t *) 0x4004A000))
#define PCR_PTC_BASE (((volatile uint32_t *) 0x4004B000))
#define PCR_PTD_BASE (((volatile uint32_t *) 0x4004C000))
#define PCR_PTE_BASE (((volatile uint32_t *) 0x4004D000))

#define ISR_PTA (*((volatile uint32_t *) 0x400490A0))
#define ISR_PTB (*((volatile uint32_t *) 0x4004A0A0))
#define ISR_PTC (*((volatile uint32_t *) 0x4004B0A0))
#define ISR_PTD (*((volatile uint32_t *) 0x4004C0A0))
#define ISR_PTE (*((volatile uint32_t *) 0x4004D0A0))

#define GPIO_A_BASE (((volatile uint32_t *) 0X400FF000))
#define GPIO_B_BASE (((volatile uint32_t *) 0x400FF040))
#define GPIO_C_BASE (((volatile uint32_t *) 0X400FF080))
#define GPIO_D_BASE (((volatile uint32_t *) 0x400FF0C0))
#define GPIO_E_BASE (((volatile uint32_t *) 0x400FF100))

//BASES DE SOPORTE
#define GPIO_A ((GPIO_t*) GPIO_A_BASE)
#define GPIO_B ((GPIO_t*) GPIO_B_BASE)
#define GPIO_C ((GPIO_t*) GPIO_C_BASE)
#define GPIO_D ((GPIO_t*) GPIO_D_BASE)
#define GPIO_E ((GPIO_t*) GPIO_E_BASE)

//SIM5 MASKS
typedef enum {
	SIM5_PORTA_MASK  = 0x200,
	SIM5_PORTB_MASK	 = 0x400,
	SIM5_PORTC_MASK  = 0x800,
	SIM5_PORTD_MASK  = 0x1000,
	SIM5_PORTE_MASK  = 0x2000,
}sim5_ports_mask_t;

//Configuracion pcr
#define PCR_INPUT_CONFIG 0x00153
#define PCR_INPUT_W_INTERRUPTION_CONFIG 0xA0153
#define PCR_OUTPUT_CONFIG 0x00140
#define PCR_FOR_SPI 0x240
#define PCR_I2C_CONFIG 0x0223
#define ISFR_OFFSET_FROM_PCR 0x28

#define IRQ_MENU 0x2
#define IRQ_MANUAL 0x10
#define IRQ_SEQUENCE 0x20

#define IRQ_KICK 0x80000
#define IRQ_SNARE 0x40000
#define IRQ_BONGO 0x2
#define IRQ_HITHAT 0x100
#define IRQ_GUIRO 0x800000
#define IRQ_RIMSHOT 0x200
#define IRQ_TAMBOR 0x200
#define IRQ_CYNBAL 0x1
#define IRQ_COWBELL 0x10000



//Configuracion PDDR
typedef enum {
	PDDR_PTA  = 0x000000,
	PDDR_PTB  = 0x000000,
	PDDR_PTC  = 0x0000A0,
	PDDR_PTD  = 0x000000,
	PDDR_PTE  = 0x000000,
}pddr_ports_t;

typedef struct{
	uint8_t irq_flags_A;
	uint8_t irq_flags_B;
	uint8_t irq_flags_C;
	uint8_t irq_flags_D;
	uint8_t irq_flags_E;
}irq_flags_t;

#define PCR_INTERRUPT_VALUE 0xA0000

#define FULL_CLEAR 0xFFFFFFFF

//Funciones de soporte
void GPIO_PDOR (port_t port,uint32_t PDO);
void GPIO_PSOR (port_t port,uint32_t PTSO);
void GPIO_PCOR (port_t port,uint32_t PTCO);
void GPIO_PTOR (port_t port,uint32_t PTTO);
uint32_t GPIO_PDIR (port_t port);
void GPIO_PDDR_W (port_t port,uint32_t PDD);
uint32_t GPIO_PDDR_R (port_t port);

//Funciones al usuario
void GPIO_turn_port_timer_on (port_t port);
void GPIO_turn_port_timer_off (port_t port);
void GPIO_set_pcr (port_t port,pin_t pin,uint32_t value);
uint8_t GPIO_get_pin_direction (port_t port, pin_t pin);
uint8_t GPIO_get_pin_value (port_t port, pin_t pin);
void GPIO_toggle_pin_value (port_t port, pin_t pin);
void GPIO_set_pin_value_on (port_t port,pin_t pin);
void GPIO_set_pin_value_off (port_t port,pin_t pin);

//Interrupciones

void GPIO_ClearAllIRQFlags();

void PORTB_IRQHandler();
void PORTC_IRQHandler();

void GPIO_Enable_IRQ();
void GPIO_Disable_IRQ();

uint8_t GPIO_GetIRQflag(port_t port);
void GPIO_ClearIRQflag(port_t port);
void GPIO_callback_init(void (*handler1)(port_t port,uint32_t flags),void (*handler2)(port_t port,uint32_t flags));

//Funcion init
void GPIO_init();

#endif /* GPIO_H_ */
