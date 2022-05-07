/******************************************************************************
*
* Module: Common macros for 8 bit processors
*
* File Name: common_macros.h
*
* Description: commonly used macros for bit-wise operations
*
* Author: Abdelrahman Yasser
*
*******************************************************************************/

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define REGISTER_SIZE 8

/* Set a certain bit in a register */
#define SET_BIT(REG, BIT) (REG |= (1<<BIT))

/* Clear a certain bit in a register */
#define CLEAR_BIT(REG, BIT) (REG &= ~(1<<BIT))

/* Toggle a certain bit in a register */
#define TOGGLE_BIT(REG, BIT) (REG ^= (1<<BIT))

/* Shift rotate a REGISTER_SIZE bits register to the left */
#define ROL(REG, NUM) (REG = ((REG<<BIT) | (REG>> (REGISTER_SIZE-NUM))))

/* Shift rotate a REGISTER_SIZE bits register to the right */
#define ROR(REG, NUM) (REG = ((REG>>BIT) | (REG<< (REGISTER_SIZE-NUM))))

/* Check for BIT == 1 */
#define BIT_IS_SET(REG, BIT) (REG & (1<<BIT))

/* Check for BIT == 0 */
#define BIT_IS_CLEAR(REG, BIT) (!(REG & (1<<BIT)))

/* Mask a bit to output */
#define BIT_MASK(REG, BIT) ((REG & (1<<BIT)) >> BIT)


#endif /* COMMON_MACROS_H_ */
