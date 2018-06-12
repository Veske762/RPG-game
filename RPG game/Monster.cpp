#include "Monster.h"
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "Random.h"
#include "Player.h"
#include "Weapon.h"
#include "Abilities.h"
using namespace std;


Monster::Monster(const std::string& name, int hp, int acc,
	int xpReward, int armor, const std::string& weaponName,
	int lowDamage, int highDamage,int goldReward,int monsterlvl,int itemseed,int status)
{
	mName = name;
	mHitPoints = hp +(0,3* monsterlvl);
	mAccuracy = acc;
	mExpReward = xpReward+(20*monsterlvl);
	mArmor = armor;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mLow = lowDamage +(1.5*monsterlvl);
	mWeapon.mDamageRange.mHigh = highDamage + (2 * monsterlvl);
	mGoldReward = goldReward+(3*monsterlvl);
	monsterLevel = monsterlvl;
	monsteritemSeed = itemseed;
	monsterStatus = status;
}

int Monster::monsterStats(int l)
{


	
	for (int i = 0; i <monsterLevel; i++)
	{
		l += 1;


	}

	return l;
}

Monster::Monster()
{
}

int Monster::monsterLvl()
{
	return monsterLevel;
}

bool Monster::isDead()
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

void Monster::takeDamage(int damage)
{
	mHitPoints -= damage;
}
std::string Monster::getName()
{
	
		return mName;
}
int Monster::getGoldReward()
{
	return mGoldReward;
}
int Monster::getArmor()
{
	return mArmor;
}

int counter =6;

void Monster::attack(Player& player, vector<Monster> &monster)
{
	extern int monsterID;
	extern int stun;
	extern int selection;
	extern int aoe;
	int check = 0;
	extern vector<Ability> classAb;

	

	if (monster[monsterID].monsterStatus == 0 || monster[monsterID].monsterStatus == 2)
	{
		if (monster[monsterID].monsterStatus == 2)
		{
			int damage = Random(classAb[3].mDamageRange);
			cout << monster[monsterID].mName << " Bleeds for " << damage << " damage\n";
			takeDamage(damage);
		}

		cout << "A " << mName << " attacks you "
			<< "with a " << mWeapon.mName << endl;
		if (Random(0, 20) < mAccuracy)
		{
			int damage = Random(mWeapon.mDamageRange);
			int totalDamage = damage - player.getArmor();
			if (totalDamage <= 0)
			{
				cout << "The monster's attack failed to "
					<< "penetrate your armor." << endl;
			}
			else
			{
				cout << "You are hit for " << totalDamage
					<< " damage!" << endl;
				player.takeDamage(totalDamage);
			}
			
			
		}

		else
		{
			cout << "The " << mName << " missed!" << endl;
		}
		cout << endl;


	}
	else if (monster[monsterID].monsterStatus == 1)
	{

		while (counter != 0)
		{

			if (counter == 0)
			{
				counter = 6;
			}



			cout << monster[monsterID].mName << " STUNNED for " << counter << " turn/s\n";
			if (counter == 1)
			{

				monster[selection].monsterStatus = 0;


				break;

			}

			counter--;
			break;
		}

	}
	

	
}void Monster::displayHitPoints()
{

	cout <<"Lvl " << monsterLevel<<" "<< mName << " Hp = " << mHitPoints<< endl;
}

