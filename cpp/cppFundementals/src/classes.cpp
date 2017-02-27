/*
 * classes.cpp
 *
 *  Created on: May 23, 2016
 *      Author: Robert
 */

#include <iostream>
#include "../h/data.h"

/*
 * Not provided as example, but also available in cpp:
 * Operator Overloading
 * Friend Functions
 * conversion functions (provide an Object a standard way to convert to int or double etc)
 * Template Classes  (type<T>)
 *
 *
 */
class MyClass
{
	/*friend class MyFriend;  <- this would grant the class MyFriend acesss to the private methods of MyClass 
	(e.g. a TV class w/ a Remote class as friend)*/
private: //note scope is set to private by default
	int data1;
	float data2;
	char data3;
protected:
	int data4;
public:
	double data5;

	/*constructor*/
	MyClass(int dat1, float dat2 = 5.5, char dat3 = 'c') //default value will be used if nothing passed in
	{
		this->data1 =dat1;
		this->data2 =dat2;
		this->data3 =dat3;
		this->data4 =5;
		this->data5 =12.25;
	};

	/*This constructor is == to the above */
	MyClass(int dat1, float dat2) : data1(dat1), data2(dat2), data3(5.5),data4('c'),data5(12.25){}

	/*A Copy constructor - a default is made if not defined, which performs a shallow clone */
	MyClass(const MyClass &)
	{
		data1 =this->data1;
		data2 =this->data2;
		data3 =this->data3;
		data4 =5;
		data5 =12.25;
	};

	/*The Destructor - if to be used as a base class important to be virtual!*/
	virtual ~MyClass()
	{
		std::cout<<"Called the Destructor."<<std::endl;
	}

	/*Template function, can use any type, lower precedence than a specialized template function*/
	template <typename MyType1, typename MyType2 >
	void swapTwo(MyType1 & arg1, MyType1 & arg2, MyType2 & arg3, MyType2 & arg4)
	{
		MyType1 temp1 = arg1;
		arg1=arg2;
		arg2=temp1;

		MyType2 temp2 = arg3;
		arg3=arg4;
		arg4=temp2;
	}

	//explicit specialization, if you call this template function with the specified type, run this code instead
	//not implemented quite right - not to worried about it atm (if I need it i'll look it up)
	//template <> void swapTwo<myData>(myData & arg1, myData & arg2, myData & arg3, myData & arg4)
	//{
		//do whatever
	//};

	/*This swapTwo takes precedence over both templates if the arguments match*/
	void swapTwo(int & arg1, int & arg2, int & arg3, int & arg4)
	{
		//do whatever
	};

	/*calling a C function example*/
	//extern "C" void foo(int);

private:
	/*method prototype*/
	void foo(int n);

public:
	int foo2();

	virtual int virtualFoo()
	{
		std::cout<<"When a function is virtual, it is binded dynamically at run-time"<<std::endl;
		return 0;
	};

	virtual void pureVirtual() = 0; //this is a pure virtual function, if this is defined in a class the class is an Abstract class

};

/*method definitions, these could exist in a seperate file*/
void MyClass::foo(int n)
{
	std::cout<<n;
}

int MyClass::foo2()
{
	return 0;
}


/***********Inheritance*******************/


class MyChildClass : MyClass
{

	//will inherit the protected and public members, but cannot directly access the private members of the Base Class ("MyClass")
private:
	int data6;
protected:
	int data7;
public:
	int data8;

	MyChildClass(int data1, float data2, char data3, int data6, int data7, int data8);

	/*note the const keyword means the object is not modified*/
	virtual int virtualFoo() const
	{
		std::cout<<"This is useful to implement polymorphism"<<std::endl;
		return 0;
	};
};


/*The constructor of the child calls the constructor of the parent*/
MyChildClass::MyChildClass(int data1, float data2, char data3, int dat6, int dat7, int dat8) : MyClass::MyClass(data1,data2,data3)
{
	data6=dat6;
	data7=dat7;
	data8=dat8;

};

