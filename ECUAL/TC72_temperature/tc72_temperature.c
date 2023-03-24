 /******************************************************************************
 *
 * Module: TC72 temperature
 *
 * File Name: TC72_temperature.c
 *
 * Description: source file for the TC72 temperature sensor using SPI prepheral
 *
 * Author: 	Hesham Shehata
 *
 *******************************************************************************/
#include "../TC72_temperature/tc72_temperature.h"
#include "../LCD/LCD.h"

void TC72_init(TC72_mode mode_parameter)
{
	TC72_enabeSelect(); /*enable selection bit*/

	mode_parameter = mode_parameter |(1<<2); /*because bit 2 should be only 1 🤷‍♂️🔥*/

	TC72_writeRrgister(CONTROL_WRITE_ADDRESS, mode_parameter);/*call function responsible for write data to set mode wanted*/
	TC72_disableSelect();/*disable selection bit*/
}


void TC72_writeRrgister(uint8_t address,uint8_t data )
{

	SPI_sendByte(address);/*send address  wanted to access*/

	SPI_sendByte(data); /*put data in this address*/
}

sint16_t TC72_readRegister(uint8_t address )
{
	sint16_t data ;
	TC72_enabeSelect();

	SPI_sendReceiveByte(address);/*send address  wanted to access*/
	/*and if send address 0x03 and continue sending dummy data to receive data from TC72  will give data in address 0x03 then address 0x02 and repeat this
	 until stop sending dummy data*/
	data = 0 ;
	data = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);/*here will receive data of MSB of temperature  */
	data = (data << 8); /*here will shift MSB of temperature to add LSB temperature  to same variable to process on it */
	data += SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);/*here will receive data of LSB of temperature  */
	TC72_disableSelect();
	return data;

}

void TC72_enabeSelect(void)
{
	DIO_writePin(SPI_PORT_NUM,SPI_PIN_SS,LOGIC_HIGH);
}

void TC72_disableSelect(void)
{
	DIO_writePin(SPI_PORT_NUM,SPI_PIN_SS,LOGIC_LOW);
}


void TC72_temperatureRead(float *temperatureValue)
{
	*temperatureValue =0;  /*to remove old value and update it with new read in next steps*/
	sint16_t tempTemperatureValue = 0 ;
	tempTemperatureValue =TC72_readRegister(MSB_TEMPERATURE_READ_ADDRESS);
	tempTemperatureValue = (tempTemperatureValue >> 6) ;/*as temperature data has 16 bit and first 6 don't change and not important*/
	unsigned char tempValueToCheckfloat =0;/*variable that contain float value of temperature to make on it operation*/
	tempValueToCheckfloat = tempTemperatureValue & 3; /*0b0000011*/
	switch (tempValueToCheckfloat)
	{
	case 1 :
		*temperatureValue = 0.25;
		break;
	case 2:
		*temperatureValue = 0.5;
		break;
	case 3:
		*temperatureValue = 0.75;
		break;
	}
	tempTemperatureValue =(tempTemperatureValue >> 2);/*to remove bits responsible for fraction and store only integer value */
	*temperatureValue = *temperatureValue + tempTemperatureValue;
}

void TC72_displayTemperature (float temperature)
{
	LCD_moveCursor(0,0);
	LCD_intToString(temperature);
	temperature =  temperature - ( (int ) temperature);/*update temperature value only with fraction value */

	if( temperature && ((float) temperature >= (float) 0.25 ) )
	{
		LCD_displayCharacter('.');
		if((float) temperature <= (float) 0.2 )
		{
			LCD_displayStringRowColumn(" ",0,2);
		}
		else if((float) temperature < (float) 0.5 )
		{
			LCD_intToString(25);
		}
		else if((float)temperature < (float) 0.75 )
		{
			LCD_intToString(5);
		}
		else if((float)temperature < (float) 1)
		{
			LCD_intToString(75);
		}

	}
}





