/*
 * std_types.h
 *
 * Created: 11/10/2020 9:28:46 PM
 *  Author: Ahmed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define SET_BIT(REGISTER,BIT_NUM) (REGISTER = REGISTER | (1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)   (REG = REG &(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM)   (REG = REG ^ (1<<BIT_NUM))
#define IS_BIT_SET(REG,BIT_NUM) ((REG &(1<<BIT_NUM))>>BIT_NUM)

typedef unsigned char uint8;
typedef signed char sint8;

typedef unsigned short uint16;
typedef signed short sint16;

typedef unsigned long uint32;
typedef signed long sint32;


#endif /* STD_TYPES_H_ */