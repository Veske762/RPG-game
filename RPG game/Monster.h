
// Monster.h

#ifndef MONSTER_H
#define MONSTER_H

#include "Weapon.h"
#include <string>
#include <vector>


class Player;

class Monster
{
public:
	
	Monster(const std::string& name, int hp, int acc, int xpReward, int armor, const std::string& weaponName, int lowDamage, int highDamage,int goldReward,int monsterlvl, int itemseed,int status);

	
	
	int  monsterLvl();
	
	
	bool isDead()const;

	int monsterStats(int l);

	Monster();

	int  getXPReward();

	
	std::string getName();

	
	int    getArmor();
    int getGoldReward();
	
	void attack(Player& player, std::vector<Monster> &monster);

	
	
	void takeDamage(int damage);

	
	void displayHitPoints();


	std::string mName;			
	int         mHitPoints;		
	int         mAccuracy;		
	int         mExpReward;		
	int         mArmor;			
	Weapon      mWeapon;  
	int         mGoldReward;
	int monsterLevel;
	int monsteritemSeed;
	int monsterStatus;
};

#endif //MONSTER_H