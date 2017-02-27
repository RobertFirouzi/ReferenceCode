/*
 * functions.cpp
 *
 *  Created on: May 21, 2016
 *      Author: Robert
 */


#include "../h/functions.h"


void printData(const myData & data)
{
	cout<<"Printing data by reference: "<<data.aFloat<<" "<<data.anInt<<endl;
}


myData & doubleData(myData & data)
{
	data.aFloat=data.aFloat*2;
	data.anInt=data.anInt*2;
	return data;
}
