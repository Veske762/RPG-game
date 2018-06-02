#pragma once

#include "Armor.h"
#include "Weapon.h"
#include "Player.h"
#include <vector>
#include <iostream>


class Quests 
{
public:

	//prologue quest


	Quests();
	//Castle quests
		void Quest1(Player& player, Map &map);

		void Quest2(Player& player, Map &map);
	
		void Quest3(Player& player, Map &map);
		//end castle quests

		void LootChest(Player &player,Map &mapz);

		//Harbor questline 
		void Hquest1(Player player, Map mapz);

		void Hquest2(Player player, Map mapz);

		void Hquest3(Player player, Map mapz);

	int mGoldR;
	int mExpR;
	~Quests();
};

