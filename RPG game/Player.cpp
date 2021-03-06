#include "stdafx.h"
#include "Shop.h"
#include <algorithm>
#include <iostream>
#include "Random.h"
#include <string>
#include "Monster.h"
#include "Magic.h"
#include <vector>
#include "Player.h"
#include <fstream>
#include "Weapon.h"
#include <Windows.h>
#include <cstdlib>
#include "Map.h"
#include "Abilities.h"
#include <sstream>



std::vector<Ability> playerAb;
std::vector<Ability> classAb;
std::vector<Weapon> monsterItemsDrop;
using namespace std;
extern int monsterBoss1;
int selection = 0;
vector<Monster> monster;




void chooseAbility()
{

	/*
	called on level up
	display all abilities
	choose 1
	add to playerAb
	change all classAb to playerAb
	upgrade abilities on next level up strength int itd..
	*/



}




Player::Player()
{
	mName = "Default";
	mRace = "Default";
	mClassName = "Default";
	mGold = 0;
	mAccuracy = 0;
	mHitPoints = 0;
	mMaxHitPoints = 0;
	mExpPoints = 0;
	mNextLevelExp = 0;
	mLevel = 0;
	mArmor = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow = 0;
	mWeapon.mDamageRange.mHigh = 0;
	mMagicPoints = 0;
	mSpellname.mDamageRange.mLow = 0;
	mSpellname.mDamageRange.mHigh = 0;
	mArmorz.mName = "Default Armor name";
	mStrength = 0;
	mIntelligence = 0;
	mSkillPoints = 0;
}


bool Player::isDead()
{
	return mHitPoints <= 0;
}


int Player::getArmor()
{
	return mArmor;
}


void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
	
}



void Player::createClass()
{

	
	cout << "||==========================||" << endl;
	cout << "||CHARACTER CLASS GENERATION||" << endl;
	cout << "||==========================||" << endl;

	// Input character's name.
	cout << "Enter your character's name: ";
	
	getline(cin, mName);
	
	// Character selection.
	cout << "Please select a character class " << endl;
	cout << "1)Fighter 2)Wizard  : ";

	int characterNum = 1;
	cin >> characterNum;
	int race = 0;
	switch (characterNum)
	{
	case 1:  // Fighter

		mClassName = "Fighter";

		cout << "Select race:1)Human,2)Half-orc";
		cin >> race;
		switch (race)
		{
		case 1:
			mRace = "Human";
			mGold = 5555;
			mAccuracy = 18;
			mHitPoints = 5280;
			mMaxHitPoints = 5280;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 2;
			mWeapon.mName = "Long Sword";
			mWeapon.mDamageRange.mLow =35;
			mWeapon.mDamageRange.mHigh = 55;
			mMagicPoints = 10;
			mMaxNumOfMagicPts = 25;
			mSpellname.mName = "Furious Charge";
			mSpellReq = 5;
			mSpellname.mDamageRange.mLow = 40;
			mSpellname.mDamageRange.mHigh = 90;
			mArmorz.mName = "Steel armor";
			mStrength = 25;
			mIntelligence = 5;
			break;
		case 2:
			mRace = "Half-orc";
			mAccuracy = 18;
			mHitPoints =  5280;
			mMaxHitPoints = 5280;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 2;
			mWeapon.mName = "Dagger";
			mWeapon.mDamageRange.mLow = 35;
			mWeapon.mDamageRange.mHigh = 55;
			mMagicPoints = 10;
			mMaxNumOfMagicPts = 10;
			mSpellname.mName = "Furious Charge";
			mSpellReq = 5;
			mSpellname.mDamageRange.mLow = 40;
			mSpellname.mDamageRange.mHigh = 90;
			mArmorz.mName = "Steel armor";
			mStrength = 30;
			mIntelligence = 2;
			break;
		
		}
		break;
	case 2:
		// Wizard
		mClassName = "Wizard";
		cout << "Select race:1)Human,2)Elf";
		cin >> race;
		switch (race)
		{
		case 1:
			mRace = "Human";
			mAccuracy = 18;
			mHitPoints = 5255;
			mMaxHitPoints = 5255;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 1;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mLow = 30;
			mWeapon.mDamageRange.mHigh = 50;
			mMagicPoints = 25;
			mMaxNumOfMagicPts = 25;
			mSpellname.mName = "Fire ball";
			mSpellname.mDamageRange.mLow = 50;
			mSpellname.mDamageRange.mHigh = 70;
			mSpellReq = 5;
			mArmorz.mName = "White Robes";
			mStrength = 5;
			mIntelligence = 25;
			break;
		case 2:
			mRace = "Elf";
			mAccuracy = 18;
			mHitPoints = 5255;
			mMaxHitPoints =5255;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 1;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mLow = 30;
			mWeapon.mDamageRange.mHigh = 50;
			mMagicPoints = 25;
			mMaxNumOfMagicPts = 25;
			mSpellname.mName = "Frost bolt";
			mSpellname.mDamageRange.mLow = 40;
			mSpellname.mDamageRange.mHigh = 70;
			mSpellReq = 5;
			mArmorz.mName = "Black Robes";
			mStrength = 6;
			mIntelligence = 24;
			break;
	


		}
		

	
	}

}
void Player::PointDistributin()
{
	for (int i = 0; i < mSkillPoints;i++)
	{
		cout << "You have " << mSkillPoints << endl;
		if (mSkillPoints == 0)
		{
			cout << "Zero skill points left\n";
			
		}
		else {
			if (mSkillPoints == 0)
			{

				break;
			}
			cout << "Choose:\n";
			cout << "1)Max Health points = " << mMaxHitPoints << endl;
			cout << "2)Accuracy          = " << mAccuracy << endl;
			cout << "3)Strength          = " << mStrength << endl;
			cout << "4)Intelligence      = " << mIntelligence << endl;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:

				mMaxHitPoints += 20;
				break;
			case 2:
				mAccuracy += 1;
				break;
			case 3:
				mStrength += 1;
				break;
			case 4:
				mIntelligence += 1;
				break;
			default:
				cout << "Wrong input\n";
				mSkillPoints++;
				break;
			}
			mSkillPoints--;
			
			system("CLS");
			PointDistributin();

		}
		
	}


}


void Player::Bet()
{



}


void Player::ArenaBet(Player player)
{

	cout << "1)Bet on Blue team\n";
	cout << "2)Bet on Yellow team\n";
	cout << "3)Exit\n";
	int choice = 0;
	int bet = 0;
	int result = 0;
	int betentered = 0;
	int teamB = Random(1, 50);
	int teamY = Random(1, 50);
	cin >> choice;
	
	switch (choice)
	{
	case 1:
		cout << "Enter bet\n";
		cin >> bet;
		if (bet > mGold)
		{
			cout << "Not enough gold\n";
		}
		else
		{
			mGold -= bet;
			betentered = 1;
			if (betentered == 1)
			{

				if (teamB > teamY)
				{
					result = 1;
				}
				else
					result = 2;
				cout << teamB;
				cout << teamY;
				if (choice == 1 && result == 1)
				{
					bet *= 2;
					mGold += bet;
					cout << "You won the bet!";
					cout << " + " << bet << " Gold \n";

				}
				else
					cout << "You lost the bet\n";


			}
			break;
	case 2:
		
		cout << "Enter bet\n";
		cin >> bet;
		if (bet > mGold)
		{
			cout << "Not enough gold\n";
		}
		else
		{
			mGold -= bet;
			betentered = 1;
			if (choice == 2 && result == 2)
			{
				bet *= 2;
				mGold += bet;
				cout << "You won the bet!";
				cout << "+" << bet << " Gold \n";
			}
			else
				cout << "You lost the bet\n";
		}
		break;
	case 3:

		break;
	default:
		cout << "Wrong input\n";
		break;



		}
	}	
			system("PAUSE");
			system("CLS");
			
}
int stun = 0;
int aoe = -1;
int check = -1;
bool Player::attack(Monster& monster,vector<Monster> &monst,int selection)
{
	Ability ab;
	int b = 1;
	int absel = -1;
	
	
	cout << "1)Weapon attack \n";
	
	
	for (int i = 0; i < classAb.size(); i++)
	{
		if (classAb[i].coolDown != 0)
		{
			if (check == 1)
			{
				break;
			}
			else
			{
				classAb[i].coolDown--;
			}

		}
	}
		for (int i = 0; i < classAb.size();i++)
		{
			
				cout << b + 1 << ")" << classAb[i].mName ;
				if (classAb[i].coolDown == 0)
				{
					cout << " : Ability ready	" << endl;
				}
				else
				{
					cout << " : Cooldown " << classAb[i].coolDown <<"/"<<classAb[i].coolDownMax<<endl; //cd vs cd max 
				}
				b++;
		}
		
		
		cin >> absel;
			cout << endl;
			switch (absel)
			{
			case 1:
				check = 0;
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
				if (classAb[0].coolDown != 0)
				{
					check = 1;
					cout << "ABILITY IS ON COOLDOWN!\n";
					attack(monster, monst, selection);

				}
				else
				{
					check = 0;
					
					classAb[0].coolDown = classAb[0].coolDownMax;
					if (classAb[0].types == 0)
					{
						ab.HighDmgStrike(classAb, monster, mWeapon, mAccuracy, 0);
					}
					else if (classAb[0].types == 1)
					{
						ab.Stuns(classAb, monster, mWeapon, mAccuracy, selection, monst, 0);
					}
					else if (classAb[0].types == 2)
					{
						ab.Aoe(classAb, monster, mWeapon, mAccuracy, monst, 0);
					}
				}
				break;
			case 3:
				if (classAb[1].coolDown != 0)
				{
					check = 1;
					cout << classAb[1].mName <<" ABILITY IS ON COOLDOWN!\n";
					attack(monster, monst, selection);
				}
				else
				{
					check = 0;
					
					classAb[1].coolDown = classAb[1].coolDownMax;
					if (classAb[1].types == 0)
					{
						ab.HighDmgStrike(classAb, monster, mWeapon, mAccuracy, 1);
					}
					else if (classAb[1].types == 1)
					{
						ab.Stuns(classAb, monster, mWeapon, mAccuracy, selection, monst, 1);
					}
					else if (classAb[1].types == 2)
					{
						ab.Aoe(classAb, monster, mWeapon, mAccuracy, monst, 1);
					}
				}
				break;
			case 4:
				if (classAb[2].coolDown != 0)
				{
					check = 1;
					cout << classAb[2].mName << " ABILITY IS ON COOLDOWN!\n";
					
					attack(monster, monst, selection);
				}
				else
				{
					check = 0;
					classAb[2].coolDown = classAb[2].coolDownMax;
					
					if (classAb[2].types == 0)
					{
						ab.HighDmgStrike(classAb, monster, mWeapon, mAccuracy, 2);
					}
					else if (classAb[2].types == 1)
					{
						ab.Stuns(classAb, monster, mWeapon, mAccuracy, selection, monst, 2);
					}
					else if (classAb[2].types == 2)
					{
						ab.Aoe(classAb, monster, mWeapon, mAccuracy, monst, 2);
					}

				}
				break;
			case 5:
				if (classAb[3].coolDown != 0)
				{
					check = 1;
					cout << classAb[3].mName << " ABILITY IS ON COOLDOWN!\n";

					attack(monster, monst, selection);
				}
				else
				{
					check = 0;
					classAb[3].coolDown = classAb[3].coolDownMax;
					
					if (classAb[3].types == 0)
					{
						ab.HighDmgStrike(classAb, monster, mWeapon, mAccuracy, 3);
					}
					else if (classAb[3].types == 1)
					{
						ab.Stuns(classAb, monster, mWeapon, mAccuracy, selection, monst,3);
					}
					else if (classAb[3].types == 2)
					{
						ab.Aoe(classAb, monster, mWeapon, mAccuracy, monst, 3);
					}
					else if (classAb[3].types == 3)
					{
						ab.Bleed(classAb, monster, mWeapon, mAccuracy,selection, monst,3);
					}
				}

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
				check = 1;
				cout << "Wrong input\n";
				attack(monster, monst, selection);
				break;

			}
		
			return false;
		
}

void Player::itemDrop()
{

	Weapon Common1("C Double Edged Axe", 5, 11, 150, 0, 0, 0, 0, 3, 2);
	Weapon Common2("C Short Sword", 5, 9, 200, 0, 0, 0, 0, 3, 2);
	Weapon Common3("C Flail", 6, 10, 250, 0, 0, 0, 0, 3, 0);
	Weapon Common4("C Steel Armor set", 0, 0, 500, 3, 5, 25, 5, 0, 0);
	Weapon Common5("C Plate Armor set", 0, 0, 250, 3, 3, 15, 7, 0, 0);

	Weapon Rare1("R Double Edged Axe", 5, 11, 150, 0, 0, 0, 0, 3, 2);
	Weapon Rare2("R Short Sword", 5, 9, 200, 0, 0, 0, 0, 3, 2);
	Weapon Rare3("R Flail", 6, 10, 250, 0, 0, 0, 0, 3, 0);

	Weapon Legendary1("L Short Sword", 5, 9, 200, 0, 0, 0, 0, 3, 2);
	Weapon Legendary2("L Short Sword", 5, 9, 200, 0, 0, 0, 0, 3, 2);
	Weapon Legendary3("L Short Sword", 5, 9, 200, 0, 0, 0, 0, 3, 2);



	monsterItemsDrop.push_back(Common1);
	monsterItemsDrop.push_back(Common2);
	monsterItemsDrop.push_back(Common3);
	monsterItemsDrop.push_back(Common4);
	monsterItemsDrop.push_back(Common5);

	monsterItemsDrop.push_back(Rare1);
	monsterItemsDrop.push_back(Rare2);
	monsterItemsDrop.push_back(Rare3);


	monsterItemsDrop.push_back(Legendary1);
	monsterItemsDrop.push_back(Legendary2);
	monsterItemsDrop.push_back(Legendary3);


}


void Player::itemPickup(vector<Weapon> &pinventory,int randomNumber)
{
	extern vector<Weapon> PlayerI;

	
	int item = 0;
	randomNumber = Random(1, 23);
	int choice = 0;
	if (randomNumber > 0 && randomNumber<= 10)
	{
		
		item = Random(0, 4);
		
		
		cout << " Dropped " << monsterItemsDrop[item].mName<<endl;
		
		cout << "1)Loot 2)leave\n";
		cin >> choice;
		switch (choice)
		{
		case 1:

			pinventory.push_back(monsterItemsDrop[item]);
			break;
		case 2:
			break;
		default :
			cout << "Wrong input\n";
				
		}
	}
	else if (randomNumber > 10 && randomNumber < 20)
	{
		
		item = Random(5, 7);
		cout << " Dropped " << monsterItemsDrop[item].mName<<endl;
		
	
		cout << "1)Loot 2)leave\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			
			pinventory.push_back(monsterItemsDrop[item]);
			break;
		case 2:
			break;
		}
	}
	else if (randomNumber >= 20 && randomNumber <23)
	{
		
		item = Random(8, 10);
		cout << " Dropped " << monsterItemsDrop[item].mName<<endl;
		
		
		cout << "1)Loot 2)leave\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			
			pinventory.push_back(monsterItemsDrop[item]);
			break;
		case 2:
			break;
		}
	}

}



void Player::reward(int xp,int gold)
{
	
	mExpPoints += xp;
	mGold += gold;
	
}




void Player::levelUp()
{
	mSkillPoints = 5;

	if (mExpPoints >= mNextLevelExp)
	{
		cout << "You gained a level!" << endl;
		
		mLevel++;

		// Set experience points required for next level.
		mNextLevelExp = mLevel * mLevel * 1000;

		PointDistributin();
		
	}
}



void Player::equipStat(vector<Weapon> &playerinventory, int itemslot)
{
	extern vector <Weapon> PlayerI;//added this coz i had out of range error
	//levelReq tbd done
	
	
		if (!(itemslot < playerinventory.size()))
		{
			cout << "No item in selected slot\n";
		}
		else {
			if (playerinventory[itemslot].mEquipped == 1 || playerinventory[itemslot].mArmorEquiped == 1)
			{
				cout << "Item already equiped\n";
				Shop f;
				f.PlayerInventory();
			}
			else
			{
				if (playerinventory[itemslot].mDamageRange.mHigh > 0)
				{
					playerinventory[itemslot].mEquipped = 1;
					playerinventory[itemslot].mArmorEquiped = 2;//coz of unequipStats function
					mWeapon.mName = playerinventory[itemslot].mName;
					mWeapon.mDamageRange.mLow = playerinventory[itemslot].mDamageRange.mLow;
					mWeapon.mDamageRange.mHigh = playerinventory[itemslot].mDamageRange.mHigh;
				}
				else if (playerinventory[itemslot].mArmorEquiped == 0)
				{
					for (int i = 0; i < playerinventory.size(); i++) // because armor items adds stats instead of setting them,this searches for item that has mArmorequiped 1 subtracts current equiped item with current stats then equips new chosen item;
					{
						if (playerinventory[i].mArmorEquiped == 1)
						{
							playerinventory[i].mArmorEquiped = 0;
							mArmorz.mName = "Plain clothes";
							mArmor -= playerinventory[i].mArm;
							mMaxHitPoints -= playerinventory[i].mHp;
							mMagicPoints -= playerinventory[i].mMagics;
						}
						
						
					}
					playerinventory[itemslot].mEquipped = 2; //because of unequipStats function 
					playerinventory[itemslot].mArmorEquiped = 1;
					mArmorz.mName = playerinventory[itemslot].mName;
					mArmor += playerinventory[itemslot].mArm;
					mMaxHitPoints += playerinventory[itemslot].mHp;
					mMagicPoints += playerinventory[itemslot].mMagics;

				}
				
				

			}




		}
	
}


void Player::Equip(vector<Weapon> &playerinventory)
{
	extern vector<Weapon> PlayerI;
	for (int i = 0; i < playerinventory.size(); i++)
	{
		playerinventory[i].mEquipped = 0;
	
	}
	cout << "Equip item " << endl;
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
		equipStat(PlayerI, 0);
		break;
	case 2:
		equipStat(PlayerI, 1);
		break;
	case 3:
		equipStat(PlayerI,2);
		break;
	case 4:
		equipStat(PlayerI, 3);
		break;
	case 5:
		equipStat(PlayerI, 4);
		break;
	case 6:
		equipStat(PlayerI, 5);
		break;
	case 7:
		equipStat(PlayerI, 6);
		break;
	case 8:
		equipStat(PlayerI, 7);
		break;
	case 9:
		equipStat(PlayerI, 8);
		break;
	case 10:
		equipStat(PlayerI, 9);
		break;
	}

}


void Player::rest()
{
	
	cout << "Resting..." << endl;
	Sleep(700);
	cout << "You feel rested\n";
	mMagicPoints = mMaxNumOfMagicPts;
	mHitPoints = mMaxHitPoints;

}

void Player::viewStats()
{
#if 0
	int GoldVal = 0;
	ifstream b;
	b.open("Goldz.txt");

	b >> GoldVal;
	mGold = GoldVal;
#endif
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Race            = " << mRace << endl;
	cout << "Name            = " << mName << endl;
	cout << "Class           = " << mClassName << endl;
	cout << "Strength        = " << mStrength << endl;
	cout << "Intelligence    = " << mIntelligence << endl;
	cout << "Accuracy        = " << mAccuracy << endl;
	cout << "Magic points    = " << mMagicPoints << endl;
	cout << "Hitpoints       = " << mHitPoints << endl;
	cout << "MaxHitpoints    = " << mMaxHitPoints << endl;
	cout << "Gold amount     = " << mGold << endl;
	cout << "XP              = " << mExpPoints << endl;
	cout << "XP for Next Lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel << endl;
	cout << "Armor           = " << mArmor << endl;
	cout << "Weapon Name     = " << mWeapon.mName << endl;
	cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" <<
		mWeapon.mDamageRange.mHigh << endl;
	cout << "Equiped armor   = " << mArmorz.mName;
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}




 void Player::castSpell()
{
	mMagicPoints -= mSpellReq;
}


void Player::victory(int xp,int gold)
{
	
	cout << "You won the battle!" << endl;
	cout << "You win " << xp
		<< " experience points!" << endl << endl;
	cout << "You looted " << gold << " Gold ";
	mExpPoints += xp;
    mGold += gold;
	
#if 0
	ofstream fout;
	fout.open("Goldz.txt");
	fout << mGold << endl;
	fout.close();
#endif
}


void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "================================" << endl;
	cout << "GAME OVER!" << endl;
	cout << "================================" << endl;
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
	system("PAUSE");
	
}


void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}

//shop 
void Player::PurchaseF(std::vector<Weapon>& shop, std::vector<Weapon>& playerinventory, int itemslot)
{
	extern vector <Weapon> PlayerI;

	if (itemslot > shop.size())
	{
		cout << "No item in selected slot\n";
	}
	else
	{
		if (mGold == 0 || mGold < shop[itemslot].mPrice)
		{
			cout << "Not enough Gold\n";
		}
		else
		{
			cout << shop[itemslot].mName << " purchased\n";
			mGold -= shop[itemslot].mPrice;
			playerinventory.push_back(shop[itemslot]);
			cout << "you have " << mGold << " gold left \n";

		}
	}
}

// shop , playerinventory
void Player::Purchase(vector<Weapon>& shop, vector<Weapon>& playerinventory)
{
	extern vector<Weapon> PlayerI;//player inventory
	extern vector<Weapon> val;


	int choicef = 0;
	cout << "Which weapon would you like to buy\n";
	cout << mGold;
	cout << "Gold: " << mGold;
	cin >> choicef;
	if (playerinventory.size() >= 10)
	{
		cout << "Not enough space.\n";
	}
	else
	switch (choicef)
	{
	case 1:
		PurchaseF(shop,PlayerI, 0);
		break;
	case 2:
		PurchaseF(shop, PlayerI, 1);
		break;
	case 3:
		PurchaseF(shop, PlayerI, 2);
		break;
	case 4:
		PurchaseF(shop, PlayerI, 3);
		break;
	case 5:
		PurchaseF(shop, PlayerI, 4);
		break;
	case 6:
		PurchaseF(shop, PlayerI, 5);
		break;
	case 7 :
		PurchaseF(shop, PlayerI, 6);
		break;
	case 8:
		PurchaseF(shop, PlayerI, 7);
		break;
	case 9:
		PurchaseF(shop, PlayerI, 8);
		break;
	case 10:
		PurchaseF(shop, PlayerI, 9);
		break;
	default:
		cout << "Wrong input\n";
	}
}

//player,playerinventory,itemslot,shop
void Player::SellF(Player &player, vector<Weapon> &playerinventory, unsigned int itemslot,vector<Weapon> &shopinventory)
{
	Shop x;
	extern vector <Weapon> PlayerI;

	if (!(itemslot < playerinventory.size()))
	{
		cout << "No item in selected slot\n";
	}
	else
	{
		if (playerinventory[itemslot].mEquipped == 1 || playerinventory[itemslot].mArmorEquiped == 1)
		{
			cout << "item is currently equiped you cant sell it\n";
		}
		else
		{
			player.mGold += playerinventory[itemslot].mPrice;
			cout << playerinventory[itemslot].mName << " Sold\n";
			playerinventory.erase(playerinventory.begin()+ itemslot);

			x.EnterShop(player,shopinventory);	
		}
	}
}

void Player::Sell(Player &player, vector<Weapon> &playerinventory,vector<Weapon>&shopinventory)
{
	extern vector<Weapon> PlayerI;

	if (playerinventory.size() != 0)
	{
		
		int choice2 = 1;
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			SellF(player,PlayerI, 0,shopinventory);
			break;
		case 2:
			SellF(player,PlayerI,1,shopinventory);
			break;
		case 3:
			SellF(player, PlayerI,2,shopinventory);
			break;
		case 4:
			SellF(player, PlayerI, 3,shopinventory);
			break;
		case 5:
			SellF(player, PlayerI,4,shopinventory);
			break;
		case 6:
			SellF(player, PlayerI, 5,shopinventory);
			break;
		case 7:
			SellF(player, PlayerI,6,shopinventory);
			break;
		case 8:
			SellF(player, PlayerI, 7,shopinventory);
			break;
		case 9:
			SellF(player, PlayerI,8,shopinventory);
			break;
		case 10:
			SellF(player, PlayerI, 9,shopinventory);
			break;
		default:
			std::cout << "Wrong input\n";
			break;
		}

	}

}

void Player::unequipStats(vector<Weapon> &playerinventory, int itemslot)
{
	extern vector<Weapon> PlayerI;

	if (!(itemslot < playerinventory.size()))
	{
		cout << "No item in selected slot\n";
	}
	else
	{
		if (playerinventory[itemslot].mEquipped == 0 || playerinventory[itemslot].mArmorEquiped == 0)
		{
			cout << "Item is not equiped\n";

		}
		else
		{
			if (playerinventory[itemslot].mEquipped == 1)
			{
				playerinventory[itemslot].mEquipped = 0;
				mWeapon.mName = "Fists";
				mWeapon.mDamageRange.mLow = 2;
				mWeapon.mDamageRange.mHigh = 4;
			}
			else if (playerinventory[itemslot].mArmorEquiped == 1)
			{
				playerinventory[itemslot].mArmorEquiped = 0;
				mArmorz.mName = "Plain clothes";
				mArmor -= playerinventory[itemslot].mArm;
				mMaxHitPoints -= playerinventory[itemslot].mHp;
				mMagicPoints -= playerinventory[itemslot].mMagics;
			}
		}
	}

}


void Player::Unequip(vector<Weapon> &playerinventory)
{
	extern vector<Weapon> PlayerI;
	
			cout << "Which item to unequip\n";
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
					unequipStats(PlayerI, 0);
				break;
			case 2:
					unequipStats(PlayerI, 1);
					break;
			case 3:
					unequipStats(PlayerI, 2);
				break;
			case 4:
					unequipStats(PlayerI, 3);
				break;
			case 5:
					unequipStats(PlayerI, 4);
				break;
			case 6 :
					unequipStats(PlayerI, 5);
				break;
			case 7:
					unequipStats(PlayerI, 6);
				break;
			case 8:
					unequipStats(PlayerI, 7);
				break;
			case 9:
					unequipStats(PlayerI, 8);
				break;
			case 10:
				    unequipStats(PlayerI, 9);
				break;
			}


}
extern int mQuest3;

extern int mHQuest1;

vector<Monster> Player::checkRandomEncounter(vector<Monster> monster)
{
	
	int highLevel =10 ;
	int lowLevel = 1;
	int numMonsters = Random(1, 3);

	extern int monsterFlag;

	//If player encounters a monster then continue otherwise return an empty vector.
	if (monsterFlag == 15)
	{
		
	}
	if (monsterFlag == 5)
	{
		int roll = Random(1, 19);
		if (roll <= 5)

			monster.push_back(Monster("Archer combatant", 15, 15, 200, 1, "Crossbow", 5, 14, 200, Random(5, 13), 1,0));

		if (roll >= 6 && roll <= 10)

			monster.push_back(Monster("Light armor combatant", 25, 15, 200, 1, "Two Handed Sword", 6, 15, 200, Random(5, 13), 1,0));

		else if (roll >= 11 && roll <= 15)

			monster.push_back(Monster("Heavy armor combatant", 30, 15, 200, 5, "Two Handed Sword", 4, 25, 200, Random(5, 13), 1,0));

		else if (roll >= 16 && roll <= 19)
			monster.push_back(Monster("Gladiator", 40, 15, 200, 2, "Two Handed Sword", 1, 30, 200, Random(5, 13), 1,0));
		


	}
		if (monsterFlag == 20)
		{

			monster.push_back(Monster("Skeleton King", 355, 15, 2000, 5, "Two Handed Sword", 5, 14, 200, Random(10,12), 1,0));
			mQuest3 = 4;
		}
		if (monsterFlag == 19)
		{
			monster.push_back(Monster("Bandit Archer", 15, 15, 200, 1, "Crossbow", 5, 14, 200, Random(4, 12), 1,0));
			monster.push_back(Monster("Bandit", 35, 15, 200, 2, "Two Handed Sword", 5, 14, 200, Random(4, 12), 1,0));
			monster.push_back(Monster("Bandit", 35, 15, 200, 2, "Two Handed Sword", 5, 14, 200, Random(4, 12), 1,0));

			monster.push_back(Monster("Bandit", 35, 15, 200, 2, "Two Handed Sword", 5, 14, 200, Random(4, 12), 1,0));

			mHQuest1 = 3;
		}
		else if (numMonsters > 0)

		{


			//Determine which monsters the player will encounter.

			for (int c = 0; c < numMonsters; c++)

			{
				int roll = Random(0, 20);


				if (monsterFlag == 1) {

					if (mLevel >= 3 && mLevel<=5)
					{
						highLevel = 20;
						lowLevel = 5;
					}
					else if (mLevel >= 6 && mLevel <= 8)
					{
						highLevel = 30;
						lowLevel = 10;
					}
					if (roll <= 5)

						monster.push_back(Monster("Scamp", 8, 6, 75, 0, "Dagger", 1, 6, Random(1, 10), Random(lowLevel, highLevel), 1,0));

					if (roll >= 6 && roll <= 10)

						monster.push_back(Monster("Orc", 20, 8, 200, 1, "Short Sword", 2, 8, Random(9, 18), Random(lowLevel, highLevel), 1,0));

					else if (roll >= 11 && roll <= 15)

						monster.push_back(Monster("Goblin", 12, 6, 100, 0, "Dagger", 3, 10, Random(1, 35), Random(lowLevel, highLevel), 1,0));

					else if (roll >= 16 && roll <= 19)

						monster.push_back(Monster("Ogre", 28, 12, 200, 1, "Club", 4, 12, Random(5, 75), Random(lowLevel, highLevel), 1,0));
					else if (roll == 20)

						monster.push_back(Monster("Orc Lord", 35, 15, 500, 1, "Two Handed Sword", 5, 14, 200, Random(lowLevel, highLevel), 1,0));

				}
				else if (monsterFlag == 2)
				{

					if (roll <= 5)

						monster.push_back(Monster("Skeleton Grunt", 8, 6, 75, 0, "Dagger", 1, 6, Random(1, 10), Random(lowLevel, highLevel), 1,0));

					if (roll >= 6 && roll <= 10)

						monster.push_back(Monster("Skeleton Warrior", 20, 8, 200, 1, "Short Sword", 2, 8, Random(9, 18), Random(lowLevel, highLevel), 1,0));

					else if (roll >= 11 && roll <= 15)

						monster.push_back(Monster("Skeleton Archer", 12, 6, 100, 0, "Dagger", 3, 10, Random(1, 35), Random(lowLevel, highLevel), 1,0));

					else if (roll >= 16 && roll <= 19)

						monster.push_back(Monster("Skeleton Brute", 28, 12, 500, 2, "Club", 4, 12, Random(5, 75), Random(lowLevel, highLevel), 1,0));


					else if (roll == 20)

						monster.push_back(Monster("Skeleton Commander", 35, 15, 2000, 5, "Two Handed Sword", 5, 14, 200, Random(lowLevel, highLevel), 1,0));





				}



			}



			for (unsigned int c = 0; c < monster.size(); c++)

			{


				cout << "You encountered an " << monster[c].getName() << "!" << "Level " << monster[c].monsterLevel << endl;

				cout << "Prepare for battle!" << endl << endl;

			}



		}

		return monster;
	
	
}

unsigned int Player::getUserInput(unsigned int low, unsigned int high)

{

	unsigned int input = 0;
	
	while (true) 

	{
		cin >> input;
		
		cin.ignore(); 

		if (input > 0 && input <= high) 
		{

			break; 
		}
		else
		{
			cout << "Invalid input\n";
			
		}

	}

	return input;

}

int monsterID = 0;

int Player::Combat(Player& player,Map &map)
{
	// Check for a random encounter. This will return a vector

	// of monsters.

	vector<Monster> monster = checkRandomEncounter(monster);



	//Test if the player encountered a monster.

	if (!monster.empty())

	{
		int totalXPReward = 0;

		int totalGoldReward = 0;

		
		//Run combat simulation.

		while (true)

		{

			system("CLS");

			//Display combatants hit points.

			displayHitPoints();

			for (unsigned int c = 0; c < monster.size(); c++)//Iterate through vector and display all monsters hp.

				monster[c].displayHitPoints();

			cout << endl;





			//If player encounters multiple monsters, let them choose one to attack.

			//Otherwise, if they encounter one monster they will attack it automatically.

			if (monster.size() > 1)

			{

				//Iterate through vector and display all monsters hp. Player chooses one to attack.

				cout << "Choose a monster to attack:" << endl;

				for (unsigned int c = 0; c < monster.size(); c++)

				{

					cout << c + 1 << ". " << monster[c].getName() << endl;

				}


				selection = getUserInput(0, monster.size());

				switch (selection)
				{
				case 1:
					selection = 0;
					break;
				case 2:
					selection = 1;
					break;
				case 3:
					selection = 2;
					break;
				case 4:
					selection = 3;
					break;
				case 5:
					selection = 4;
					break;
				default:
					cout << "Wrong input\n";
					break;
				}

			}
			else

				selection = 0;

			extern vector <Weapon> val;
			bool runAway = 0;



			runAway = attack(monster[selection], monster, selection);



			extern int counter;

			//If the player killed the monster with its attack.
			

			
			
			for (int i = 0; i < monster.size(); i++)
			{
				
				if (monster[i].isDead())
				{

					if (monster[i].monsterStatus == 1)
					{
						counter = 6;
					}

					extern vector<Weapon> PlayerI;

					monster[i].monsteritemSeed = Random(1, 250);
					if (monster[i].monsteritemSeed <= 34)
					{
						cout << monster[i].mName;
						itemPickup(PlayerI, monster[i].monsteritemSeed);

					}



					totalXPReward += monster[i].getXPReward();//Add monsters xp reward to the total xp reward.

					totalGoldReward += monster[i].getGoldReward();//Add monsters godl reward to the toal gold reward.
					
					

				}
			
			}
			for (auto i = monster.begin(); i != monster.end(); )
			{

				if (i->isDead()) i = monster.erase(i); else ++i;

			}
			//Test if the player runs away.
				
				
					if (runAway)
					{
						counter = 6;
						return 0;
					}
				
				
				
		
			//Test if all monsters are dead.
			
				
			
			if (monster.empty())
			{
				cout << endl;
				for (int i = 0; i < classAb.size(); i++)
				{
					classAb[i].coolDown = 0;//reset cooldowns after all enemies are dead
				}
				victory(totalXPReward, totalGoldReward);

				levelUp();

				system("PAUSE");

				return 0;

			}

			//Monster's attack the player.

			for (unsigned int c = 0; c < monster.size(); c++)
			{
				monsterID = c;
				monster[c].attack(player, monster);
			}
			/*

			If a monster kills the player the game is over

			this function returns 1 to set done to true in the main game loop.

			the main game loop then ends since it only continues while done is false.

			*/
		
			if (player.mHitPoints > 20000 || player.mHitPoints == 0)//???????
			{
				player.gameover();

				exit(0);
			}

			system("PAUSE");

		}

	}

	//Return zero if player didn't encounter monster.

	return 0;

}


unsigned int vecadder = 0;
void Player::Save(Player &player,Map &map)
{
	
	extern vector<Weapon> PlayerI;
	extern int Location;
	extern int mQuest1;
	extern int mQuest2;
	extern int mQuest3;
	extern int mHQuest1;
	extern int mHQuest2;
	extern int Location;

	//save stats,location,position,quests status
	/*		mRace = "Human";
			mAccuracy = 18;
			mHitPoints = 255;
			mMaxHitPoints = 255;
			mExpPoints = 0;
			mNextLevelExp = 1000;
			mLevel = 1;
			mArmor = 1;
			mWeapon.mName = "Staff";
			mWeapon.mDamageRange.mLow = 30;
			mWeapon.mDamageRange.mHigh = 80;
			mMagicPoints = 25;
			mMaxNumOfMagicPts = 25;
			mSpellname.mName = "Fire ball";
			mSpellname.mDamageRange.mLow = 50;
			mSpellname.mDamageRange.mHigh = 70;
			mSpellReq = 5;
			mArmorz.mName = "White Robes";*/

	ofstream fout;
	//Player stats
	
	
	fout.open("Save.txt");
	fout << mRace << endl <<
		mAccuracy << endl <<
		mHitPoints << endl <<
		mMaxHitPoints << endl <<
		mGold << endl <<
		mExpPoints << endl <<
		mNextLevelExp << endl <<
		mLevel << endl <<
		mArmor << endl <<
		mWeapon.mName << endl <<
		mWeapon.mDamageRange.mLow << endl <<
		mWeapon.mDamageRange.mHigh << endl <<
		mMagicPoints << endl <<
		mMaxNumOfMagicPts << endl <<
		mSpellname.mName << endl <<
		mSpellname.mDamageRange.mLow << endl <<
		mSpellname.mDamageRange.mHigh << endl <<
		mSpellReq << endl <<
		mArmorz.mName << endl<<
		Location<<endl;
		
	
	//player location
	  
	/*
	std::string mName;
	Range mDamageRange;
	
	int mPrice;
	int mEquipped;
	int mArm;
	int mHp;
	int mMagics;
	int mArmorEquiped;
	int levelReq;*/
	if (!PlayerI.empty())
	{
		for (int i = 0; i < 2; i++)//
		{
			fout <<
				PlayerI[i].mName << endl <<
				PlayerI[i].mDamageRange.mLow << endl <<
				PlayerI[i].mDamageRange.mHigh << endl <<
				PlayerI[i].mPrice << endl <<
				PlayerI[i].mEquipped << endl <<
				PlayerI[i].mArm << endl <<
				PlayerI[i].mMagics << endl <<
				PlayerI[i].mArmorEquiped << endl <<
				PlayerI[i].levelReq << endl;

		}
	}

	//global
	/*int startingQuest = 0;
int mQuest1 = 0;
int mQuest2 = 1;
int mQuest3 = 0;
int mHQuest1 = 0;
int mHQuest2 = 0;
int monsterFlag = 0;
int monsterBoss1 = 0;
int doorLock = 0;
int lootChestFlag = 0;
int Location = 0;*/
	
	
	fout.close();

}

void Player::Load(Player &player,Map map)
{
	
	extern vector<Weapon> PlayerI;
	//todo check if vec is empty replace 2 with counter from writing to file
	for (int i = 0; i < 2; i++)
	{
		Weapon f;
		PlayerI.push_back(f);
	}

	extern int Location;
	ifstream inFile;
	inFile.open("Save.txt");
	


	inFile >>mRace >>
			mAccuracy >>
			mHitPoints >>
			mMaxHitPoints >>
			mGold >>
			mExpPoints >>
			mNextLevelExp >>
			mLevel >>
			mArmor >>
			mWeapon.mName >>
			mWeapon.mDamageRange.mLow >>
			mWeapon.mDamageRange.mHigh >>
			mMagicPoints >>
			mMaxNumOfMagicPts >>
			mSpellname.mName >>
			mSpellname.mDamageRange.mLow >>
			mSpellname.mDamageRange.mHigh >>
			mSpellReq >>
			mArmorz.mName>>
		    Location; 

		std::istringstream stream;

		std::string line;

		
			for (int i = 0; i < 2; i++)
			{
				inFile
					>> PlayerI[i].mName >>
					PlayerI[i].mDamageRange.mLow >>
					PlayerI[i].mDamageRange.mHigh >>
					PlayerI[i].mPrice >>
					PlayerI[i].mEquipped >>
					PlayerI[i].mArm >>
					PlayerI[i].mMagics >>
					PlayerI[i].mArmorEquiped >>
					PlayerI[i].levelReq;
			}
		
		
	
	if (Location == 1)
	{
		map.worldMap(player, map);
	}
	else if (Location == 2)
	{
		map.Harbor(player, map);
	}
	else if (Location == 5)
	{
		map.CastleMap(player, map);
	}
}


void Player::Abilityvec()
{
	Ability hdmgF("Ravager", 20, 40, 0, 0, 0, 0, 0, 0, 3);
	Ability stunF("Bash", 5, 15, 0, 1, 0, 0, 1, 0, 4);
	Ability aoeF("Blade Storm", 10, 20, 1, 0, 0, 0, 2, 0, 3);
	Ability bleedF("Deep Wounds", 4, 17, 0, 0, 1, 0, 3, 0, 2);

	Ability hdmgW("Frost Bolt", 20, 40, 0, 0, 0, 0, 0, 0, 3);
	Ability stunW("Freeze", 5, 15, 0, 1, 0, 0, 1, 0, 4);
	Ability aoeW("Blizzard", 10, 20, 1, 0, 0, 0, 2, 0, 3);
	Ability bleedW("Curse", 0, Random(1, 15), 0, 0, 1, 0, 3, 0, 2);

	if (mClassName == "Fighter")
	{

		
		classAb.push_back(stunF);
		classAb.push_back(aoeF);
		classAb.push_back(bleedF);
		classAb.push_back(hdmgF);
	}
	
	else if(mClassName == "Wizard")
	{
		classAb.push_back(hdmgW);
		classAb.push_back(stunW);
		classAb.push_back(aoeW);
		classAb.push_back(bleedW);
	}

}








