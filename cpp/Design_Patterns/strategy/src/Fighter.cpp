/*
 * Strategy.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Robert
 *
 *  Strategy:
 *	Define a family of algorithms, encapsulate each one, and make them interchangeable.
 *	This allows the algorithm to vary independently from clients that use it.
 *
 */

#include "../h/fighter.h"

//Fighter class definitions
Fighter::Fighter(string arg_name, GenderEnum arg_gender, int arg_age, int arg_weight, int arg_height, string arg_hometown,
			AttackInterface *arg_primary, AttackInterface *arg_secondary):
		name(arg_name), gender(arg_gender), age(arg_age), weight(arg_weight),height_inches(arg_height),hometown(arg_hometown),
		primaryAttack(arg_primary), secondaryAttack(arg_secondary)
{};

Fighter::~Fighter(){};
void Fighter::usePrimaryAttack()
{
	this->primaryAttack->run();
};

void Fighter::useSecondaryAttack()
{
	this->secondaryAttack->run();
};

void Fighter::setAttacks(AttackInterface *arg_primary, AttackInterface *arg_secondary)
{
	this->primaryAttack=arg_primary;
	this->secondaryAttack=arg_secondary;
}

string Fighter::getName(){return name;};
GenderEnum Fighter::getGender(){return gender;};
int Fighter::getAge(){return age;};
int Fighter::getWeight(){return weight;};
int Fighter::getHeight(){return height_inches;};
string Fighter::getHometown(){return hometown;};
