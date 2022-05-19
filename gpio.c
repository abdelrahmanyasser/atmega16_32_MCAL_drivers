/******************************************************************************
*
* Module: GPIO Driver
*
* File Name: gpio.c
*
* Description: general purpose input/output registers configurations for
* atmega16/32
*
* Author: Abdelrahman Yasser
*
*******************************************************************************/

#include "gpio.h"

void
GPIO_setupPinDirection (uint8 port_num, uint8 pin_num,
  GPIO_PinDirectionType direction)
  {

    /*
    * Check if the input port number is greater than NUM_OF_PORTS value.
    * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
    * In this case the input is not valid port/pin number
    */
    if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT)
    {
      /* Escape the function and return for invalid inputs */
      return;
    }

    /* Select the corresponding DDRx register for the required PORT */
    switch(port_num)
    {
      case PORTA_ID:
      if(direction == PIN_INPUT)
      {
        CLEAR_BIT(DDRA, pin_num);
      }
      else
      {
        SET_BIT(DDRA, pin_num);
      }
      break;

      case PORTB_ID:
      if(direction == PIN_INPUT)
      {
        CLEAR_BIT(DDRB, pin_num);
      }
      else
      {
        SET_BIT(DDRB, pin_num);
      }
      break;

      case PORTC_ID:
      if(direction == PIN_INPUT)
      {
        CLEAR_BIT(DDRC, pin_num);
      }
      else
      {
        SET_BIT(DDRC, pin_num);
      }
      break;

      case PORTD_ID:
      if(direction == PIN_INPUT)
      {
        CLEAR_BIT(DDRD, pin_num);
      }
      else{
        SET_BIT(DDRD, pin_num);
      }
      break;
    }

    return;
  }

void
GPIO_setupPortDirection (uint8 port_num, GPIO_PinDirectionType direction)
{

  /*
  * Check if the input port number is greater than NUM_OF_PORTS value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * In this case the input is not valid port/pin number
  */
  if (port_num >= NUM_OF_PORTS)
  {
    /* Escape the function and return for invalid inputs */
    return;
  }

  /* Select the corresponding DDRx register for the required PORT */
  switch(port_num)
  {
    case PORTA_ID:
    DDRA = direction;
    break;

    case PORTB_ID:
    DDRB = direction;
    break;

    case PORTC_ID:
    DDRC = direction;
    break;

    case PORTD_ID:
    DDRD = direction;
    break;
  }

  return;
}

uint8
GPIO_readPin(uint8 port_num, uint8 pin_num)
{

  uint8 value = 0;

  /*
  * Check if the input port number is greater than NUM_OF_PORTS value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * In this case the input is not valid port/pin number
  */
  if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT)
  {
    /* Escape the function and return for invalid inputs */
    return 0;
  }

  switch(port_num)
  {
    case PORTA_ID:
    /* Mask the bit to output */
    value = BIT_MASK(PINA, pin_num);
    break;

    case PORTB_ID:
    /* Mask the bit to output */
    value = BIT_MASK(PINB, pin_num);
    break;

    case PORTC_ID:
    /* Mask the bit to output */
    value = BIT_MASK(PINC, pin_num);
    break;

    case PORTD_ID:
    /* Mask the bit to output */
    value = BIT_MASK(PIND, pin_num);
    break;
  }

  return value;
}

uint8
GPIO_readPort(uint8 port_num)
{

  uint8 value = 0;

  /*
  * Check if the input port number is greater than NUM_OF_PORTS value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * Return in case the input is not valid port/pin number
  */
  if (port_num >= NUM_OF_PORTS ) {
    return 0;
  }

  switch(port_num)
  {
    case PORTA_ID:
    value = PINA;
    break;

    case PORTB_ID:
    value = PINB;
    break;

    case PORTC_ID:
    value = PINC;
    break;

    case PORTD_ID:
    value = PIND;
    break;
  }

  return value;
}

void
GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{

  /*
  * Check if the input port number is greater than NUM_OF_PORTS value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * In this case the input is not valid port/pin number
  */
  if (port_num >= NUM_OF_PORTS || pin_num >= NUM_OF_PINS_PER_PORT) {
    /* Escape the function and return for invalid inputs */
    return;
  }

  switch(port_num){
    case PORTA_ID:
    if(value == LOGIC_HIGH)
    {
      SET_BIT(PORTA, pin_num);
    }
    else
    {
      CLEAR_BIT(PORTA, pin_num);
    }
    break;

    case PORTB_ID:
    if(value == LOGIC_HIGH)
    {
      SET_BIT(PORTB, pin_num);
    }
    else
    {
      CLEAR_BIT(PORTB, pin_num);
    }
    break;

    case PORTC_ID:
    if(value == LOGIC_HIGH)
    {
      SET_BIT(PORTC, pin_num);
    }
    else
    {
      CLEAR_BIT(PORTC, pin_num);
    }
    break;

    case PORTD_ID:
    if(value == LOGIC_HIGH)
    {
      SET_BIT(PORTD, pin_num);
    }
    else
    {
      CLEAR_BIT(PORTD, pin_num);
    }
    break;
  }

  return;
}

void
GPIO_writePort(uint8 port_num, uint8 value)
{
  /*
  * Check if the input port number is greater than NUM_OF_PORTS value.
  * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
  * In this case the input is not valid port/pin number
  */
  if (port_num >= NUM_OF_PORTS) {
    /* Escape the function and return for invalid inputs */
    return;
  }

  switch(port_num)
  {
    case PORTA_ID:
    PORTA = value;
    break;

    case PORTB_ID:
    PORTB = value;
    break;

    case PORTC_ID:
    PORTC = value;
    break;

    case PORTD_ID:
    PORTD = value;
    break;
  }

  return;
}
