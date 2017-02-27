/*
 * main.cpp
 *
 *  Created on: May 21, 2016
 *      Author: Robert
 *
 *  c++ fundemantal I/O and commands.  This is not a c primer, and is meant
 *  as a crib sheet for the c++ basics that are added to extend c
 */

//cpp includes
#include <stdlib.h>
#include <Stdio.h>
#include <iostream>
#include <string>

//project specific includes
#include "../h/data.h"
#include "../h/file_IO.h"
#include "../h/functions.h"

/*This directive allows the console to open when debugging from within VS*/
#define NO_STDIO_REDIRECT 

const int MONTHS = 12; //constants in c++

class AClass
{
public:
	int data;
	AClass(int data1)
	{
		this->data = data1;
	}
};

/**
 * Note: For my Windows eclipse environment, the PATH is set to use MinGW compiler
 *
 * Adding headers to build path:
 * Project properties>C/C++ build >Settings>Tool Settings>GCC C++ compiler>includes
 * in include paths add C:\MinGW\include, and any of my include folders
 *
 * (The joys of IDE's!!!)
 */
int main()
{
	using namespace std; //a directive

	/*Basic I/O in C++*/
	printf("console output the c way\n");
	std::cout << "console output the cpp way" << " don't forget this trick: there are " <<MONTHS<<" months in a year\n";
	std::cerr <<"printing to std error\n";
	cout<<"if using the namespace 'std', you can ommit that on the cout command\n";
	cout<<"you can do a neline this way" <<endl; //endl is a "manipulator" - it also flushes the output

	/*thanks god cpp has a string class*/
	string cppString1,cppString2;
	cppString1 = "this works like a java string";
	cppString2 = " with the ability to append and conatenate";
	cout << (cppString1+cppString2) << endl;


	/*memory allocation*/
	char *aString = new char[50];// char[50 * sizeof(char)]; //allocate 50 bytes to aString
	//aString = "saving a new set of chars as a string";
	char copyString[38] = "saving a new set of chars as a string";
	//strcpy_s(aString, copyString);
	//cout<<aString<<endl;
	delete[] aString; //deallocate the memory

	/*cpp has a bool type as well*/
	bool aBoolean = true;
	cout<<"does c++ now have a boolean type? "<<aBoolean<<endl; //notice "true" is just the integer 1


	/*conditional operator*/
	//expr1 ? expr2 :expr3
	2>1 ? cout<<"the 'shortcut' if else statement\n" : cout<< "this won't print";

	fileIO();

	/*creating, passing and returning a struct by reference*/
	myData someData;
	myData & dataRef = someData;
	someData.aFloat=1.5;
	someData.anInt=10;

	printData(dataRef);
	someData=doubleData(dataRef);
	printData(dataRef);

	AClass* temp = new AClass(5);
	delete temp;

	AClass local = AClass(10);

	cout << local.data;
	return 0;
}



