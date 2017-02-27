/*
 * strategy.h
 *
 *  Created on: May 31, 2016
 *      Author: Robert
 *
 *  Our main class, the behavior of a Fighter can be modified by
 *  changing the ActionInterface's at run-time.  This allows
 *  more flexibility in defining Fighter's without having to re-write
 *  or over-ride code.
 */

#ifndef STRATEGY_HEADERS_FIGHTER_H_
#define STRATEGY_HEADERS_FIGHTER_H_

//cpp includes
#include <iostream>
#include <string.h>

//project includes
#include "attacks.h"

using namespace std; //note you should not use a namespace in a header file!

enum GenderEnum
{
	FEMALE,
	MALE
};

class Fighter
{
private:
	//no private fields
protected:
	string name;
	GenderEnum gender;
	int age;
	int weight;
	int height_inches;
	string hometown;
	AttackInterface *primaryAttack;
	AttackInterface *secondaryAttack;

public:
	/**
	 * Constructor which takes the descriptive params of a fighter, and their two primary attacks
	 */
	Fighter(string arg_name, GenderEnum arg_gender, int arg_age, int arg_weight, int arg_height, string arg_hometown,
			AttackInterface *arg_primary, AttackInterface *arg_secondary);
	/**
	 * destructor
	 */
	virtual ~Fighter();

	/**
	 * Invokes this fighters main attack
	 */
	virtual void usePrimaryAttack();

	/**
	 *Invoked this fighters secondary attack
	 */
	virtual void useSecondaryAttack();
	/**
	 * define the two main attacks for this fighter
	 */
	virtual void setAttacks(AttackInterface *arg_primary, AttackInterface *arg_secondary);

	string getName();
	GenderEnum getGender();
	int getAge();
	int getWeight();
	int getHeight();
	string getHometown();
};



#endif /* STRATEGY_HEADERS_FIGHTER_H_ */
