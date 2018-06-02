#pragma once
// Weapon.h
#ifndef WEAPON_H
#define WEAPON_H
#include "Range.h"
#include <string>

struct Weapon 
{
public:

	Weapon(std::string name, int low, int high, int price, int equipedW, int armor, int hp, int magics, int armorEquiped,int lReq);
	Weapon() {};
	
	std::string mName;
	Range mDamageRange;
	
	int mPrice;
	int mEquipped;
	int mArm;
	int mHp;
	int mMagics;
	int mArmorEquiped;
	int levelReq;
};




#endif //WEAPON_H