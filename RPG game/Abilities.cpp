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


/*switch (select)
	{
	case 1:
		cout << "You attack an " << monster.getName()
			<< " with a " << mWeapon.mName << endl;

		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mDamageRange);

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
		cout << endl;
		break;
	case 2:
		cout << "You use " << classAb[0].mName << " on " << monster.getName()<<endl;
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
			
		
		break;


	case 3:
		//Bash stun cd 4 moves
			
			monst[selection].monsterStatus = 1;
		cout << "You use " << classAb[1].mName << " on " << monster.getName() << endl;
		if (Random(0, 20) < mAccuracy)
		{
			cout << endl;
			int damage = Random(classAb[1].mDamageRange);
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
	
		break;
	case 4:
		cout << "You use " << classAb[2].mName << endl;
		aoe = 1;
		
			if (aoe == 1)
			{
				for (int i = 0; i < monst.size(); i++)
				{


					int total = Random(mWeapon.mDamageRange)*1.4;
					cout << monst[i].mName << "Hit by aoe for " << total << " damage \n";
					monst[i].takeDamage(total);
					cout << "SIZE" <<monst.size();
				}
					aoe = 0;
			}
		
		break;
	case 5:

		monst[selection].monsterStatus = 2;
		cout << "You use " << classAb[3].mName << " vs " << monster.getName() << endl;
		//add function for bleed

		break;
	case 6:
	{
		int roll = Random(1, 3);
		if (monsterBoss1 == 1)
		{
			cout << "You cant escape the boss fight\n";
		}
		else
		{
			if (roll == 1)
			{
				cout << "You run away!" << endl;
				return true;
			}
			else
			{
				cout << "You could not escape!" << endl;
				break;
			}
		}

	}
	default:
		cout << "Wrong input\n";
		break;
	}
*/

void Ability::HighDmgStrike(std::vector<Ability> &ability,Monster &monster,Weapon mWeapon,int mAccuracy)
{
	cout << "You use " << ability[0].mName << " on " << monster.getName() << endl;
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
void Ability::Stuns(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy,int selection,std::vector<Monster> &monst)
{
	monst[selection].monsterStatus = 1;
	cout << "You use " << ability[1].mName << " on " << monster.getName() << endl;
	if (Random(0, 20) < mAccuracy)
	{
		cout << endl;
		int damage = Random(ability[1].mDamageRange);
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
void Ability::Aoe(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy,std::vector<Monster> &monst)
{
	cout << "You use " << ability[2].mName << endl;

		for (int i = 0; i < monst.size(); i++)
		{


			int total = Random(mWeapon.mDamageRange)*2.4;
			cout << monst[i].mName << "Hit by aoe for " << total << " damage \n";
			monst[i].takeDamage(total);
			cout << "SIZE" << monst.size();
		}
	



}
void Ability::Bleed(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, int selection, std::vector<Monster> &monst)
{
	cout << "You use " << ability[3].mName << endl;
	cout << "Target is bleeding \n";
	monst[selection].monsterStatus = 2;
	


}