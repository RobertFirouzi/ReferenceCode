/*
 * attacks.h
 *
 *  Created on: May 31, 2016
 *      Author: Robert
 *
 *  Header file defines the various attack types usable by a fighter
 *  These are the encapsulated "algorithms" that can be added to any supporting classes
 */

#ifndef STRATEGY_HEADERS_ATTACKS_H_
#define STRATEGY_HEADERS_ATTACKS_H_

class AttackInterface{
public:
	AttackInterface();
	virtual ~AttackInterface();
	virtual void run();
};

class AttackKick : public AttackInterface{
public:
	AttackKick();
	virtual ~AttackKick();
	virtual void run();
};

class AttackPunch : public AttackInterface{
public:
	AttackPunch();
	virtual ~AttackPunch();
	virtual void run();
};

class AttackKnee : public AttackInterface{
public:
	AttackKnee();
	virtual ~AttackKnee();
	virtual void run();
};

#endif /* STRATEGY_HEADERS_ATTACKS_H_ */
