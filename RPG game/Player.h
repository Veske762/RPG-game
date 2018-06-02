#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include "Map.h"
#include <vector>
#include "Random.h"
#include "Monster.h"
#include <string>
#include "Weapon.h"
#include "Magic.h"
#include "Range.h"
#include <fstream>

class Player 
{
public:
	
	Player();

	void Items();
	
	
	bool isDead();

	

	int  getArmor();
	
	void reward(int xp, int gold);
	
	void takeDamage(int damage);

	
	
	void createClass();

	
	bool attack(Monster& monster);

	
	
	void levelUp();

	
	void rest();

	void Unequip(std::vector<Weapon> &playerinventory);

	void viewStats();

	void castSpell();
	
	void victory(int xp,int gold);
	
	void Equip(std::vector<Weapon> &playerinventory);

	void gameover();

	void Sell(Player &player, std::vector<Weapon> &playerinventory, std::vector<Weapon>&shopinventory);
	
	void displayHitPoints();

	void Purchase(std::vector<Weapon>& shop, std::vector<Weapon>& playerinventory);
	
	int Combat(Player& player,Map &map);

	unsigned int getUserInput(unsigned int low, unsigned int high);
	
	void unequipStats(std::vector <Weapon> &playerinventory, int itemslot);
	
	void equipStat(std::vector<Weapon> &playerinventory, int itemslot);

	void SellF(Player &player, std::vector<Weapon>&playerinventory, unsigned int itemslot,std::vector<Weapon> &shopinventory);

	void PurchaseF(std::vector<Weapon>& shop, std::vector<Weapon>& playerinventory, int itemslot);

	void itemDrop();

	void itemPickup(std::vector<Weapon> &pinventory,int randomNumber);

	// Data members.
	std::string mName;				
	std::string mClassName;			
	int         mAccuracy;			
	unsigned int mHitPoints;
	unsigned int mMaxHitPoints;
	int         mExpPoints;			
	int         mNextLevelExp;		
	int         mGold;
	int         mLevel;				
	unsigned int    mArmor;				
	Weapon      mWeapon;	
	Weapon      mArmorz;
    Spell       mSpellname;
	std::string       mRace;
	unsigned int mMagicPoints;
	unsigned int mMaxNumOfMagicPts;
	unsigned int mSpellReq;
	
	
	
}; 

#endif //PLAYER_H