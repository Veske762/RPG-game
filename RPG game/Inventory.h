#pragma once

#include "Weapon.h"
#include "Player.h"
class Inventory : public Player
{
public:

	void ShopInventory();

	Inventory();
	Weapon mName;
	int mDamageHigh;
	int mDamageLow;
	Weapon mPrice;
	
};

