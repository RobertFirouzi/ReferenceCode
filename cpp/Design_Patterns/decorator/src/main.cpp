/*
Main file for decorator design pattern
*/

#include<iostream>
#include <string>
#include "../h/decorator.h"

using namespace std;

/*This directive allows the console to open when debugging from within VS*/
#define NO_STDIO_REDIRECT 

int main()
{
/*
	vector<int> intVector = { 1,2,3 };
	intVector.size();
	for (int i = 0; i < 3; i++)
	{
		cout << intVector[i];
	}
*/

	CharacterBuffStat strBuff = CharacterBuffStat("adds 3 to strength", CHAR_STR, 3);
	CharacterBuffStat defBuff = CharacterBuffStat("adds 1 to defense", CHAR_DEF, 1);
	CharacterBuffStat spdBuff = CharacterBuffStat("adds 20 to speed", CHAR_SPD, 20);

	vector<CharacterBuffBase> vectorStr = { strBuff };
	vector<CharacterBuffBase> vectorDef = { defBuff };
	vector<CharacterBuffBase> vectorSpd = { spdBuff };

	CharacterEquip robsEquipment = CharacterEquip("Rob's set of armor");

	EquipDecorator shortSword = EquipDecorator("A basic sword", &robsEquipment, vectorStr);
	EquipDecorator metalHelmet = EquipDecorator("A metal helmet", &shortSword, vectorDef);
	EquipDecorator leatherBoots = EquipDecorator("Some sturdy boots", &metalHelmet, vectorSpd);

	vector<CharacterBuffBase> robsBuffs = leatherBoots.getEquipBuffs(robsBuffs);

	cout << "Robbs Buffs:\n";
	for (int i = 0; i < robsBuffs.size(); i++)
	{
		cout << "Buff " << i << ": ";
		robsBuffs[i].printDescription();
		cout << "\n";
	}

	cout << "End of decorator main file";
	return 0;
}