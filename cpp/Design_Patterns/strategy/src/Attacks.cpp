/*
 * Attacks.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Robert
 *
 *  contains the function definitions for the attacks
 */

#include <iostream>
#include "../h/attacks.h"

AttackInterface::AttackInterface(){};
AttackInterface::~AttackInterface(){};
void AttackInterface::run(){std::cout<<"Generic attack!\n";};

AttackKick::AttackKick(){};
AttackKick::~AttackKick(){};
void AttackKick::run(){std::cout<<"Throws a kick!\n";};

AttackPunch::AttackPunch(){};
AttackPunch::~AttackPunch(){};
void AttackPunch::run(){std::cout<<"Throws a punch!\n";};

AttackKnee::AttackKnee(){};
AttackKnee::~AttackKnee(){};
void AttackKnee::run(){std::cout<<"Throws a knee!\n";};




