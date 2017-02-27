/*
 Source file for decorator pattern.
*/

# include "../h/decorator.h"
#include <string>
#include<iostream>
using namespace std;
/***** CharacterBuffBase *****/
CharacterBuffBase::CharacterBuffBase(string _description) : description(_description){};
CharacterBuffBase::~CharacterBuffBase(){};
void CharacterBuffBase::printDescription()
{cout << description;}

/***** CharacterBuffStat *****/
CharacterBuffStat::CharacterBuffStat(string _description, CharacterStatEnum _statToBuff, int _buffAmount) : 
	CharacterBuffBase::CharacterBuffBase(_description){statToBuff = _statToBuff; buffAmount = _buffAmount;};
CharacterBuffStat::~CharacterBuffStat(){};

/***** CharacterEquipBase *****/
CharacterEquipBase::CharacterEquipBase() {};
CharacterEquipBase::CharacterEquipBase(string _description) : description(_description){};
CharacterEquipBase::~CharacterEquipBase(){};

/***** CharacterEquip *****/
CharacterEquip::CharacterEquip(string _description) : CharacterEquipBase::CharacterEquipBase(_description) {};
CharacterEquip::~CharacterEquip() {};
vector<CharacterBuffBase> CharacterEquip::getEquipBuffs(vector<CharacterBuffBase> _equipmentBuffs)
{
	equipmentBuffs.insert(equipmentBuffs.end(), _equipmentBuffs.begin(), _equipmentBuffs.end()); //appends the vector
	return equipmentBuffs;
};


/***** EquipDecorator *****/
EquipDecorator::EquipDecorator(string _description, CharacterEquipBase _wrappedCharacterEquip, 
	vector<CharacterBuffBase> _equipmentBuffs) : CharacterEquipBase::CharacterEquipBase(_description){
	wrappedCharacterEquip = _wrappedCharacterEquip;
	equipmentBuffs = _equipmentBuffs;
};
EquipDecorator::~EquipDecorator() {};

vector<CharacterBuffBase> EquipDecorator::getEquipBuffs(vector<CharacterBuffBase> _equipmentBuffs)
{
	equipmentBuffs.insert(equipmentBuffs.end(), _equipmentBuffs.begin(), _equipmentBuffs.end()); //appends the vector

	return wrappedCharacterEquip.getEquipBuffs(equipmentBuffs); //call the wrapped function to append more buffs
}