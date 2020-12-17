/*
 * ADC.h
 *
 * Created: 11/14/2020 12:03:08 PM
 *  Author: Ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_


#define SET_BIT(REGISTER,BIT_NUM) (REGISTER = REGISTER | (1<<BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)   (REG = REG &(~(1<<BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM)   (REG = REG ^ (1<<BIT_NUM))
#define IS_BIT_SET(REG,BIT_NUM) ((REG &(1<<BIT_NUM))>>BIT_NUM)

void ADC_vTnit(void);

//unsigned short ADC_u16Read(unsigned char channel);

void ADC_vStartConversion(void);

#endif /* ADC_H_ */