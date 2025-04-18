#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void delay(uint16_t time);
void init_RCC(void);
void GPIO_config(void);

uint32_t LED[10] = {0x01F80200, 0x003003C8, 0x02D80120, 0x02780180, 0x033000C8, 
								0x03680090, 0x03E80010, 0x003803C0, 0x03F80000, 0x03780080};

int main(void)
{
	init_RCC();
	GPIO_config();
	while(1)
	{
		
	}
}

void delay(uint16_t time)
{
	for (uint16_t i = 0; i < time; i++)
	{
		for (uint16_t j = 0 ; j < 0x2AFF; j++);
	}
}

void init_RCC()
{
	RCC->APB2ENR |= 0x0C;
}

void GPIO_config()
{
	//Config portB
	GPIOB->CRL &= ~(0xFFFFF000);  //reset chân 3,4,5,6,7
	GPIOB->CRL |= 0x33333000;     //configure chân 3,4,5,6,7 là mode output push-pull, speed 50MHz
	GPIOB->CRH &= ~(0x00FF);      // reset chân 8,9
	GPIOB->CRH |= 0x0033;					//configure chân 8,9 là mode output push-pull, speed 50MHz
	//config portA
	GPIOA->CRL &= ~(0x00FF);      //reset chân 0,1
	GPIOA->CRL |= 0x0033;					//configure chân 0,1 là mode output push-pull, speed 50MHz
}


