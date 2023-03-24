/******************************************
* Module: DIO(GPIO)
*
* File Name: DIO.h
*
* Description: header file for AVR DIO Driver
*
* Author: Hesham Shehata
*
******************************************/

#ifndef DIO_H_
#define DIO_H_

#include "../../utilities/std_types.h"
//#include "../../utilities/MCU_register.h"
#include "../../utilities/common_macros.h"

/********************************************************************
*                                Definitions
********************************************************************/
#define NUM_OF_PORT 4
#define NUM_OF_PIN_PER_PORT 8 

#define PORTA_ID   0
#define PORTB_ID   1
#define PORTC_ID   2
#define PORTD_ID   3   

#define PIN0_ID    0
#define PIN1_ID    1
#define PIN2_ID    2
#define PIN3_ID    3
#define PIN4_ID    4
#define PIN5_ID    5
#define PIN6_ID    6
#define PIN7_ID    7

#define LOGIC_HIGH   (1u)
#define LOGIC_LOW    (0u)
        

/********************************************************************
*                              Types Decleration
********************************************************************/
typedef enum
{
	INPUT_PIN,
	INPUT_PIN_PULLUP,//case to activate internal pull up register for pin
	OUTPUT_PIN
}GPIO_PinDirectionTypes;

typedef enum
{
	INPUT_PORT =0,
	INPUT_PORT_PULLUP =0,//case to activate internal pull up register for port
	OUTPUT_PORT = 0xFF
}GPIO_PortDirectionTypes;

/*********************************************************
*               Prototypes
*********************************************************/

///function for pin
/*
* Description:
* setup direction of specific pin in port input/input&pull up/output
* if input port number and pin number are not correct ,function will not handle request
*/
void DIO_setupPinDirection(uint8_t PORT_X ,uint8_t PIN_NUM,GPIO_PinDirectionTypes DIRECTION );

/*
* Description:
* write value logic high or low in specific pin
* if input port number and pin number are not correct ,function will not handle request
* check if output pin then will write ,if input pin will not do anything
*/
void DIO_writePin(uint8_t PORT_X ,uint8_t PIN_NUM,uint8_t value );

/*
* Description:
* read and return value for specific pin, it should be logic high or low
* if input port number and pin number are not correct ,function will return logic low
*/
uint8_t DIO_readPin(uint8_t PORT_X ,uint8_t PIN_NUM);

/*
* Description:
* toggle value for specific pin
* if input port number and pin number are not correct ,function will not handle request
* check if output pin then will toggle ,if input pin will not do anything
*/
void DIO_togglePin(uint8_t PORT_X ,uint8_t PIN_NUM);

///function for port
/*
* Description:
* setup direction for specific port all pins input/output
* If the direction value is PORT_INPUT all pins in this port should be input pins
* If the direction value is INPUT_PIN_PULLUP all pins in this port should be input pins & pulled up
* If the direction value is PORT_OUTPUT all pins in this port should be output pins
* if input port number is not correct ,function will not handle request
*/
void DIO_setupPortDirection(uint8_t PORT_X , GPIO_PortDirectionTypes DIRECTION);

/*
* Description:
* write value for specific port
* if any pin in this port is output pin value will written
* if any pin in this port is input pin will not do any thing
* if input port number is not correct ,function will not handle request
*/
void DIO_writePort(uint8_t PORT_X, uint8_t value);

/*
* Description:
* read and return value for specific port
* if input port number is not correct ,function will return logic low
*/
uint8_t DIO_readPort(uint8_t PORT_X);

#endif /* DIO_H_ */
