#include "stdafx.h"
#include <iostream>

#include <string>
#include "Armor.h"
#include <vector>
#include "Shop.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include <algorithm>
using namespace std;

vector<Weapon> PlayerI;//player inventory
vector<Weapon> val; //castle shop
vector<Weapon> val2;//harbor shop weapons
vector<Weapon> val3;//harbor shop armor


void Shop::CityShopInventory()
{



}


void Shop::ShopInventory()
{  
	
	Weapon Axe = { "Double Edged Axe", 11, 20, 500, 0, 0, 0, 0, 3, 2 };
	Weapon Sword("Short Sword", 12, 19, 400, 0, 0, 0, 0, 3, 2);
	Weapon flail("Flail", 8, 15, 250, 0, 0, 0, 0, 3, 0);
	Weapon Steelarmor("Steel Armor set", 0, 0, 700, 3, 5, 25, 5, 0, 0);
	Weapon Plate("Plate Armor set", 0, 0, 550, 3, 3, 15, 7, 0, 0);




	val.push_back(Axe);
	val.push_back(Sword);
	val.push_back(flail);
	val.push_back(Steelarmor);
	val.push_back(Plate);


	//std::random_shuffle(val.begin(), val.end());


	//harbor weapon shop
	Weapon wep1("Striker", 20, 35, 3000, 0, 0, 0, 0, 3, 2);
	Weapon wep2("Hellreaver", 24, 39, 4000, 0, 0, 0, 0, 3, 2);
	Weapon wep3("Butcher's blade", 9, 30, 6000, 0, 0, 0, 0, 3, 2);
	Weapon wep4("Storm Breaker", 30, 50, 9000, 0, 0, 0, 0, 3, 2);

	val2.push_back(wep1);
	val2.push_back(wep2);
	val2.push_back(wep3);
	val2.push_back(wep4);
	//harbor armor shop
	Weapon ar1("Obsidian Armor", 0, 0, 1000, 3, 6, 25, 5, 0, 0);
	Weapon ar2("Chestplate of Relentless Might", 0, 0, 1500, 3, 7, 25, 5, 0, 0);
	Weapon ar3("Tunic of Eternal Fire", 0, 0, 1700, 3, 8, 25, 5, 0, 0);
	Weapon ar4("Frost Wool Robes", 0, 0, 600, 3, 5, 25, 5, 0, 0);

	val3.push_back(ar1);
	val3.push_back(ar2);
	val3.push_back(ar3);
	val3.push_back(ar4);

	


}



void Shop::DisplayShopInventory(Player &player,vector<Weapon>& shopinventory)
{
	
	
	for (int i = 0; i < shopinventory.size(); i++)
	{
		std::cout << i + 1 << ')' << shopinventory[i].mName << " " << shopinventory[i].mPrice << " Gold\n";
	}
	
	
	player.Purchase(shopinventory, PlayerI);
	EnterShop(player,shopinventory);
}

void Shop::EnterShop(Player &player, vector<Weapon> &shopinventory)
{
	cout << "///////SHOP/////////\n";
	int choice = 1;
	cout << "1)Buy  2)Sell 3)Exit\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		//shop inventory
		DisplayShopInventory(player,shopinventory);
		
		break;
	case 2:
		//Player inventory
		PlayerInventory();
		{
			Player s;
			s.Sell(player, PlayerI,shopinventory);
		}
		
		break;
	case 3:


		break;
	default:
		cout << "Wrong input\n";
   }
}




Shop::Shop()
{
	
   
	

}








void Shop::PlayerInventory()
{
	cout << "=========INVENTORY=========\n";
	cout << endl;
	
	if (PlayerI.size() == 0 )
	{
		cout << "Inventory is empty\n";
		cout << endl;
	}
	else
	{

		for (int i = 0; i < PlayerI.size();i++)
		{
			if (PlayerI[i].mArm > 0)
			{
				if (PlayerI[i].mArmorEquiped == 1)
				{
					cout << i + 1 << ")" << PlayerI[i].mName << "| +" << PlayerI[i].mArm << " Armor" <<" | +"<< PlayerI[i].mHp << " Health | +" << PlayerI[i].mMagics << " Magics | Value " << PlayerI[i].mPrice << " Gold ";
					cout << " : Currently equipped\n\n";
				}
				else
					cout << i + 1 << ")" << PlayerI[i].mName << "| +" << PlayerI[i].mArm << " Armor" << " | +" << PlayerI[i].mHp << " Health | +" << PlayerI[i].mMagics << " Magics | Value " << PlayerI[i].mPrice << " Gold "<<endl<<endl;

			}
			else
			{
				if (PlayerI[i].mEquipped == 1)
				{

					cout << i + 1 << ")" << PlayerI[i].mName << " | " << PlayerI[i].mPrice << " Gold " << "| Damage " << PlayerI[i].mDamageRange.mLow << " - " << PlayerI[i].mDamageRange.mHigh;
					cout << " : Currently equipped\n\n";
				}
				else
					cout << i + 1 << ")" << PlayerI[i].mName << " | " << PlayerI[i].mPrice << " Gold " << "| Damage " << PlayerI[i].mDamageRange.mLow << " - " << PlayerI[i].mDamageRange.mHigh << endl << endl;
			}
		}
		
		cout << endl;
		
	}
	

	cout << "=====END OF INVENTORY====\n";

}


