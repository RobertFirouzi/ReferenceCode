#include "../h/fighter.h"
#include "../h/attacks.h"
#include<iostream>
#include <string>
using namespace std;

/*This directive allows the console to open when debugging from within VS*/
#define NO_STDIO_REDIRECT 

/*main for strategy*/
int main()
{
	Fighter *jim, *jane, *jill;
	Fighter *fighters[3];

	//the "algorithms"
	AttackInterface *kickAction = new AttackKick();
	AttackInterface *punchAction = new AttackPunch();
	AttackInterface *kneeAction = new AttackKnee();

	//these contain the encapsulated "algorithms, the AttackInterfaces
	jim = new Fighter(string("Jim"), MALE, 26, 150, 68, string("Minneapolis"),
		punchAction, punchAction);

	jane = new Fighter(string("Jane"), FEMALE, 22, 115, 52, string("Saint Paul"),
		kickAction, kneeAction);

	jill = new Fighter(string("Jill"), FEMALE, 22, 115, 52, string("Saint Paul"),
		punchAction, kneeAction);

	fighters[0] = jim;
	fighters[1] = jane;
	fighters[2] = jill;

	int i;
	for (i = 0; i<3; i++)
	{
		cout << fighters[i]->getName() << " throws primary attack." << endl;
		cout << fighters[i]->getName() << " ";
		fighters[i]->usePrimaryAttack();
		cout << fighters[i]->getName() << " throws secondary attack." << endl;
		cout << fighters[i]->getName() << " ";
		fighters[i]->useSecondaryAttack();
		cout << endl;
	}

	//changing the behavior of the class dynamically
	cout << fighters[0]->getName() << " changes his fight style.\n" << endl;
	fighters[0]->setAttacks(punchAction, kickAction);

	cout << fighters[0]->getName() << " throws primary attack." << endl;
	cout << fighters[0]->getName() << " ";
	fighters[0]->usePrimaryAttack();
	cout << fighters[0]->getName() << " throws secondary attack." << endl;
	cout << fighters[0]->getName() << " ";
	fighters[0]->useSecondaryAttack();
	cout << endl;

	delete(kickAction);
	delete(punchAction);
	delete(kneeAction);
	delete(jim);
	delete(jane);
	delete(jill);

	return 0;
}
