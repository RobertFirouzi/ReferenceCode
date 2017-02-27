/*
 * functions.h
 *
 *  Created on: May 21, 2016
 *      Author: Robert
 */

#ifndef HEADERS_FUNCTIONS_H_
#define HEADERS_FUNCTIONS_H_

#include<iostream>
using namespace std;

#include "data.h"

/*prints the data passed in as a reference - the const keyword prevents accientally changing the data*/
void printData(const myData & data);

/*doubles the data returning it by reference*/
myData & doubleData(myData & data);

/**
 * inline functions are copied directly into program memory where called
 * impoves performance/speed but at a cost of memory space, since each call
 * inserts a copy of the function's code
 */
inline double math_square(double x)
{
	return x*x;
}



#endif /* HEADERS_FUNCTIONS_H_ */
