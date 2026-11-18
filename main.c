#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_prv.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_prv.h"
#include "MCAL/GPIO/GPIO_int.h"

int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, GPIOAEN);

	GPIOx_PinConfig_t LED =
	{
			.Port = GPIO_PORTA,
			.Pin = GPIO_PIN0,
			.Mode = GPIO_MODE_OUTPUT,
			.OutputType = GPIO_OT_PUSHPULL,
			.Speed = GPIO_SPEED_HIGH,
	};

	MGPIO_vPinInit(&LED);
	MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
	while(1)
	{

	}
	return 0;
}
