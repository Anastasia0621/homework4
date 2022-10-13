#include "stm32f10x.h"

// APB2???????
#define RCC_APB2ENR	*((unsigned volatile int*)0x40021018)
// GPIOA?????
#define GPIOA_CRL	*((unsigned volatile int*)0x40010800)
#define	GPIOA_ODR	*((unsigned volatile int*)0x4001080C)
// GPIOB?????
#define GPIOB_CRH	*((unsigned volatile int*)0x40010C04)
#define	GPIOB_ODR	*((unsigned volatile int*)0x40010C0C)
// GPIOC?????
#define GPIOC_CRH	*((unsigned volatile int*)0x40011004)
#define	GPIOC_ODR	*((unsigned volatile int*)0x4001100C)
	
void SystemInit(){}

void delay(u32 time){
	u32 i = 0;
	while(time--){
		i = 2000;
		while(i--){
		}
	}
}

int main(void){
	
	RCC_APB2ENR |= (1<<2);	// GPIOA ????
	RCC_APB2ENR |= (1<<3);	// GPIOB ????
	RCC_APB2ENR |= (1<<4);	// GPIOC ????
	
	GPIOA_CRL &= 0xFF0FFFFF;	// ???? PA5 ????
	// F ??????????????????,???? CRL ???1?2?……?8,CRH ???9?10?……?16
	GPIOA_CRL |= 0x00300000;	// PB5 ????(???????), ??
	//GPIOA_ODR &= ~(1<<5);		
	GPIOA_ODR |= 1<<5;				// ??????????
	
	GPIOB_CRH &= 0xFFFFFF0F;
	GPIOB_CRH |= 0x00000020;	// ??
	//GPIOA_ODR &= ~(1<<9);
	GPIOB_ODR |= 1<<9;
	
	
	GPIOC_CRH &= 0xF0FFFFFF;
	GPIOC_CRH |= 0x02000000;	// ??
	//GPIOC_ODR &= ~(1<<14);
	GPIOC_ODR |= 1<<14;
	
	while(1){
		GPIOA_ODR &= ~(1<<5);	//PB5???,????0,??????
		delay(1000);
		GPIOA_ODR |= 1<<5;		// ?????
		
		// ????????????????
		
		GPIOB_ODR &= ~(1<<9);
		delay(1000);
		GPIOB_ODR |= 1<<9;
		
		GPIOC_ODR &= ~(1<<14);
		delay(1000);
		GPIOC_ODR |= 1<<14;
	}
	
}