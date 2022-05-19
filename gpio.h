/******************************************************************************
*
* Module: GPIO Driver
*
* File Name: gpio.h
*
* Description: general purpose input/output registers configurations for
* atmega16/32
*
* Author: Abdelrahman Yasser
*
*******************************************************************************/
#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"
#include "common_macros.h"
#include <avr/io.h> /* For register names */

#define NUM_OF_PORTS              (4u)
#define NUM_OF_PINS_PER_PORT      (8u)

/* Port definitions */
#define PORTA_ID    (0u)
#define PORTB_ID    (1u)
#define PORTC_ID    (2u)
#define PORTD_ID    (3u)

/* Pins per port definitions */
#define PIN0_ID     (0u)
#define PIN1_ID     (1u)
#define PIN2_ID     (2u)
#define PIN3_ID     (3u)
#define PIN4_ID     (4u)
#define PIN5_ID     (5u)
#define PIN6_ID     (6u)
#define PIN7_ID     (7u)

typedef enum{
  PIN_INPUT, PIN_OUTPUT
} GPIO_PinDirectionType;

typedef enum{
  PORT_INPUT  = 0x00,
  PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num,
  GPIO_PinDirectionType direction);
void GPIO_setupPortDirection(uint8 port_num, GPIO_PinDirectionType direction);
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);
uint8 GPIO_readPort(uint8 port_num);
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
void GPIO_writePort(uint8 port_num, uint8 value);




#endif /* GPIO_H_ */
