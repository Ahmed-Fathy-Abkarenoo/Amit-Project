/*
 * ADC.c
 *
 * Created: 11/14/2020 12:03:20 PM
 *  Author: Ahmed
 */ 
/*MCAL ADC Driver*/

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "ADC.h"

void ADC_vTnit(void)
{
	/*Adjust prescaler*/
	//ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	/*SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);*/
	
	/*Adjust vref*/
	//SET_BIT(ADMUX,REFS0);
	//CLR_BIT(ADMUX,REFS1);
	
	/*Enable ADC*/
	//SET_BIT(ADCSRA,ADEN);
	
	/*The ADC is enabled by setting the ADC Enable bit, ADEN in ADCSRA*/
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
	
	/*interrupt on*/
	ADCSRA |= (1<<ADIE);
	
	//ADMUX |= (1<<ADLAR);
}

//unsigned short ADC_u16Read(unsigned char channel)
//{
	//unsigned temp;
	/*choose channel*/
	//ADMUX |= channel;
	
	/*Start Conversion*/
	//SET_BIT(ADCSRA,ADSC);
	
	/*Check if conversion finish*/
	//while(IS_BIT_SET(ADCSRA,ADIF) ==0)
	//{
		/*wait*/
	//}
	
	/*return conversion value*/
	//temp = (unsigned short) (ADCL);
	//temp |= (unsigned short) (ADCH<<8);
	//return temp;
//}

void ADC_vStartConversion(void)
{
	ADCSRA |= (1<<ADSC);
}