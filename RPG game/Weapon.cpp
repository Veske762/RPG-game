#include "Range.h"
#include <string>
#include <iostream>
#include "stdafx.h"
#include "Weapon.h"
#include "Player.h"
using namespace std;

Weapon::Weapon(std::string name, int low, int high, int price, int equipedW, int armor, int hp, int magics, int armorEquiped, int lreq)
{
	mName = name;
	mDamageRange.mLow = low;
	mDamageRange.mHigh = high;
	mPrice = price;
	mEquipped = equipedW;
	mArm = armor;
	mHp = hp;
	mMagics = magics;
	mArmorEquiped = armorEquiped;
	levelReq = lreq;
}
