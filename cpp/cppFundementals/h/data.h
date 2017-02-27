/*
 * data.h
 *
 *  Created on: May 21, 2016
 *      Author: Robert
 */

#ifndef HEADERS_DATA_H_
#define HEADERS_DATA_H_

/*Bit fields*/
struct toggle_reg
{
	unsigned int portB : 8; //specifically use 8 bits
	unsigned int : 8;	//8 bits unused
	unsigned int portC : 8;
	unsigned int : 8;
}; //this could be useful for example for register definitions for a microcontroller

struct myData
{
	int anInt;
	float aFloat;
};

/*UNIONS
 * a unions decleration sytnax is like a struct
 * a union has several variables but can only HOLD one at a time
 */

union dataType
{
	char charType;
	int intType;
	long longType;
	float floatType;
};

void data(void);

#endif /* HEADERS_DATA_H_ */
