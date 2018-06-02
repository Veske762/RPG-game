#pragma once
#ifndef SHOP_H
#define SHOP_H

#include "Player.h"
#include "Armor.h"


class Shop 
{
public:
	

	Shop();

	void EnterShop(Player &player, std::vector<Weapon> &shopinventory);

	void CityShopInventory();

	void DisplayShopInventory(Player &player, std::vector<Weapon>& shopinventory);

	void ShopInventory();
	
	
	
	void PlayerInventory();


};

#endif