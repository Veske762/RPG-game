#include "stdafx.h"
#include "Abilities.h"
#include <string>
#include "Random.h"
#include "Range.h"
#include "Weapon.h"
#include <vector>
#include <iostream>
#include "Monster.h"
using namespace std;
Ability::Ability(std::string name, int lowdmg, int highdmg, int aoes, int stuns, int bleeds, int poisons,int type,int cd,int cdmax)
{

	 mName = name;
	 mDamageRange.mLow = lowdmg;
	 mDamageRange.mHigh = highdmg;
	 aoe = aoes;
	 stun = stuns;
	 bleed = bleeds;
     poison = poisons;
	 types = type;
	 coolDown = cd;
	 coolDownMax = cdmax;
}


void Ability::HighDmgStrike(std::vector<Ability> &ability,Monster &monster,Weapon mWeapon,int mAccuracy,int abselect)
{
	cout << "You use " << ability[abselect].mName << " on " << monster.getName() << endl;
	if (Random(0, 20) < mAccuracy)
	{
		cout << endl;
		int damage = Random(mWeapon.mDamageRange)*2.1;
		int totalDamage = damage - monster.getArmor();
		if (totalDamage <= 0)
		{
			cout << "Your attack failed to penetrate "
				<< "the armor." << endl;
		}
		else
		{
			cout << "You attack for " << totalDamage
				<< " damage!" << endl;

			monster.takeDamage(totalDamage);
		}
	}
	else
	{
		cout << "You miss!" << endl;
	}

}

void Ability::Stuns(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, int selection, std::vector<Monster> &monst, int abselect)
{
	monst[selection].monsterStatus = 1;
	cout << "You use " << ability[abselect].mName << " on " << monster.getName() << endl;
	if (Random(0, 20) < mAccuracy)
	{
		cout << endl;
		int damage = Random(ability[abselect].mDamageRange);
		int totalDamage = damage - monster.getArmor();
		if (totalDamage <= 0)
		{
			cout << "Your attack failed to penetrate "
				<< "the armor." << endl;
			monst[selection].monsterStatus = 0;
		}
		else
		{
			cout << "You attack for " << totalDamage
				<< " damage!" << endl;

			monster.takeDamage(totalDamage);
		}
	}
	else
	{
		cout << "You miss!" << endl;
	}

}


void Ability::Aoe(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy,std::vector<Monster> &monst, int abselect)
{
	cout << "You use " << ability[abselect].mName << endl;

		for (int i = 0; i < monst.size(); i++)
		{
			int total = Random(mWeapon.mDamageRange)*2.4;
			cout << monst[i].mName << "Hit by aoe for " << total << " damage \n";
			monst[i].takeDamage(total);
		}
	



}
void Ability::Bleed(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, int selection, std::vector<Monster> &monst, int abselect)
{
	cout << "You use " << ability[abselect].mName << endl;
	cout << "Target is bleeding \n";
	monst[selection].monsterStatus = 2;
	
}