#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

void delay(uint16_t time);
void init_RCC(void);
void GPIO_config(void);

uint32_t LED[10] = {0x01F80200, 0x003003C8, 0x02D80120, 0x02780180, 0x033000C8, 
								0x03680090, 0x03E80010, 0x003803C0, 0x03F80000, 0x03780080};								//mang hien so tren led tu 0-9 nhung dung thanh ghi BSRR

int main(void)
{
	init_RCC();
	GPIO_config();
	while(1)
	{
		for (uint32_t i = 0; i < 100; i++)
		{
			for (uint32_t j = 0; j < 100; j++)     //tao delay 400ms de hien thi du cho nguoi nhin duoc thông so led hien là bao nhiêu
			{
				//Bât led hang chuc truoc
				GPIOB->BSRR = LED[i/10];
				GPIOA->BSRR = 0x20001;  //A0 la hang chuc
				delay(2);
				//GPIOA->BSRR = 0x30000;
				GPIOA->BRR = 0x03;
				//Led hang don vi
				GPIOB->BSRR = LED[i%10];
				GPIOA->BSRR = 0x10002;   //A1 la hang don vi
				delay(2);
				//GPIOA->BSRR |= 0x30000;
				GPIOA->BRR = 0x03;
			}
		}
//		GPIOA->ODR = 0x02;
//		delay(10);
//		GPIOB->ODR = 0x0200;
//		delay(10);
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
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
}

void GPIO_config()
{
	//Chan PB3 và PB4 default là JTAB debug
	AFIO->MAPR &= ~(0x7 << 24);  // Xóa bits liên quan JTAG
	AFIO->MAPR |= (0x2 << 24);   // Select mode "JTAG-DISABLE, SWD-ENABLE"
	//Config portB
	GPIOB->CRL &= ~(0xFFFFF000);  //reset chân 3,4,5,6,7
	GPIOB->CRL |= 0x33333000;     //configure chân 3,4,5,6,7 là mode output push-pull, speed 50MHz
	GPIOB->CRH &= ~(0x00FF);      // reset chân 8,9
	GPIOB->CRH |= 0x0033;					//configure chân 8,9 là mode output push-pull, speed 50MHz
	//config portA
	GPIOA->CRL &= ~(0x00FF);      //reset chân 0,1
	GPIOA->CRL |= 0x0033;					//configure chân 0,1 là mode output push-pull, speed 50MHz
}
