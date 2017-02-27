/*
This contains th definitions for th decorator example class.
This class example is a class to contain all of the armor and accessories 
an RPG character is wearing.  The decorator pattern is used to return all
of the buffsa the character gains from their armor in an array.

*/

#ifndef DECORATOR_HEADER
#define DECORATOR_HEADER

#include <vector>

using namespace std;

/* Basic building block of a character, this enum probably would reside somewhere else more related to player stats etc */
enum CharacterStatEnum{CHAR_STR, CHAR_DEF, CHAR_SPD};

/* Base class to extend to create different types of buffs */
class CharacterBuffBase{
public:
	CharacterBuffBase(string _description);
	virtual ~CharacterBuffBase();
	/*Quick hack to print the description for debugging*/
	void printDescription();
protected:
	string description;
};

/* A Buff which increases (or decreases) a characters stat */
class CharacterBuffStat : public CharacterBuffBase{
public:
	CharacterBuffStat(string _description, CharacterStatEnum _statToBuff, int _buffAmount);
	virtual ~CharacterBuffStat();
protected:
	CharacterStatEnum statToBuff;
	int buffAmount;
};

/*********************************** Decorator ***********************************/

/* The base component for the decorator pattern.  Add equipment to the character by wrapping the base */
class CharacterEquipBase{
public:
	CharacterEquipBase();
	CharacterEquipBase(string _description);
	virtual ~CharacterEquipBase();

protected:
	string description;
	vector<CharacterBuffBase> equipmentBuffs;
};

/* This is essentially the bottom of the call stack.  Decorators will wrap this class in concentric circle style */
class CharacterEquip : public CharacterEquipBase{
public:
	CharacterEquip(string _description);
	virtual ~CharacterEquip();
	/* Returns class vector 'equipmentBuffs' */
	virtual vector<CharacterBuffBase> getEquipBuffs(vector<CharacterBuffBase> _equipmentBuffs);
};

class EquipDecorator : public CharacterEquipBase{
public:
	EquipDecorator(string _description, CharacterEquipBase _wrappedCharacterEquip, 
		vector<CharacterBuffBase> _equipmentBuffs);
	virtual ~EquipDecorator();
	/* The decorator calls the wrapped objects method and adds it to its own */
	virtual vector<CharacterBuffBase> getEquipBuffs(vector<CharacterBuffBase> _equipmentBuffs);
protected:
	CharacterEquipBase wrappedCharacterEquip;
	vector <CharacterBuffBase> equipmentBuffs;
};


#endif