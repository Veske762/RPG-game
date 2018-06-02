#include "stdafx.h"
#include "Inventory.h"
#include <vector>
#include <iostream>
#include "Shop.h"
using namespace std;

Inventory::Inventory()
{
}

void Inventory::ShopInventory()
{
	vector<Weapon> v;
	Weapon Axe;
	Weapon Sword;
	Weapon Flail;
	Weapon DhandSword;

	Axe.mDamageRange.mHigh = 7;
	Axe.mDamageRange.mLow = 2;
	Axe.mName = "Double Edged Axe";
	Axe.mPrice = 50;

	Sword.mDamageRange.mHigh = 7;
	Sword.mDamageRange.mLow = 2;
	Sword.mName = "Short Sword";
	Sword.mPrice = 75;


	Flail.mDamageRange.mHigh = 7;
	Flail.mDamageRange.mLow = 2;
	Flail.mName = "Flail";
	Flail.mPrice = 45;

	DhandSword.mDamageRange.mHigh = 15;
	DhandSword.mDamageRange.mLow = 8;
	DhandSword.mName = "Two handed Sword";
	DhandSword.mPrice = 150;

	Armor SteelArmor;
	Armor Robes;
	Armor Kevlar;

	Robes.armorValue = 3;
	Robes.mName = "Wizard Robes";

	Kevlar.armorValue = 4;
	Kevlar.mName = "Kevlar Armor";

	SteelArmor.armorValue = 6;
	SteelArmor.mName = "Steel Armor";
	vector<Weapon> v;

	v.push_back(Axe);
	v.push_back(Sword);
	v.push_back(Flail);
	v.push_back(DhandSword);
}
