#include "stdafx.h"
#include "Quests.h"
#include "Map.h"
#include <Windows.h>
#include "Player.h"
using namespace std;



extern int startingQuest;
Quests::Quests()
{
	mExpR = 0;
	 rank = 0;
	mGoldR = 0;
}
std::vector<Weapon> Quest;
void Items()
{
	
	
}

extern int monsterFlag;
extern int mQuest1;
void Quests::Quest1(Player& player, Map &map)
{
	
	if (rank >= 3)
	{
		startingQuest = 3;
	}
	cout << endl<< "====WELCOME TO THE ARENA====";
	cout << endl << endl;
	cout << "Would you like to join the arena as a combatant or bet on a fight ?\n";
	if (rank < 5) {
		cout << "Current title Combatant\n";

	}
	else if (rank > 4 && rank < 11)
	{
		cout << endl << "Current title Duelist"<<endl;
	}
	else if (rank > 10 && rank < 13)
	{
		cout <<endl <<"Current title Gladiator\n"<<endl;
		//starting skele king q
	}
	//ranks maybe proove yourself in the arena then come to me;
	//if 15 kills rank = "????" unlock skele king
	
	cout << "1)join combat 2) bet 3) exit\n";
	int choice = 0;
	cin >> choice;
	switch (choice)
	{
	case 1:
		//set special monsterflag
		monsterFlag = 5;
		player.Combat(player, map);
		monsterFlag = 15;
		rank++;
		cout << endl<< "Current killsnumber" << rank <<"/10"<< endl;
		Quest1(player,map);
		//win counter
		break;
	case 2:
		//bet system function fighter name level weapon vs Random(1,20) and random(1,20) who ever's larger wins; 100% gold +;
		player.ArenaBet(player);
		Quest1(player, map);
		break;
	case 3:

		break;
	default :
		cout << "Wrong input\n";
		break;



	}

}
void Quests::Quest2(Player& player, Map &map)
{

	cout << " ";

}

void Quests::Quest3(Player& player, Map &map)
{
	extern int mQuest3;
	//first quest go to down left dungeon and kill Skeleton King (skeleton king drops fat loot);
	extern int doorLock;
	
	if (mQuest3 == 0)
	{
		cout << "Gladiator?I was wrong about you.\n";
		cout << "I need you to kill the Skeleton King, " << endl;
			"his forces have been destroying surrounding villages\n";
		cout << "First go to dungeon(south/west)(34,53) and find the artifact(description),we need it to open Skeleton King's tomb\n";
		
		int choice = 0;
		cout << "1)Accept 2)Decline\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Hope you make it \n";

			mQuest3 = 1;
			break;
		}
		case 2:
			cout << "If you change your mind ill be here\n";
			break;
		}
	}
	else if (mQuest3 == 1)
	{
		cout << "Did you get the artifact?\n";
		cout << "No ?... Hope you get it soon\n";
	}
	else if(mQuest3 == 2)
	{
		
		cout << "You got it ?Finnaly.\n";
		cout << "Here is your reward \n";
		
		mExpR += 200;
		mGoldR += 200;
		
		player.reward(mExpR,mGoldR);
	 
		cout << "+ " << mExpR << "Exp"<<endl;
		cout << "+ " << mGoldR << "Gold" << endl;
		mQuest3 = 3;


		//+xp + gold 
	}
	else if (mQuest3 == 3)
	{
		cout << "We can now unlock Skeleton King's tomb head out to the dungeon(north/east)(20,70)and bring me his crown huge reward awaits you\n";
		 doorLock = 1; 
		 
	}
	else if (mQuest3 == 4)
	{
		cout << "The Skeleton King has finally fallen here is your reward\n";
		mExpR += 1000;
		mGoldR += 500;
		player.reward(mExpR, mGoldR);
		mQuest3 = 5;
	}
	else if (mQuest3 == 5)
	{
		cout << "I heard there is a merchant in need at the harbor (name) to the west (1,29npc pos)\n";
			//kicks in harbor questline when you get there
			//init mquest 4?

	}

	


}
extern int mHQuest1;
extern int mHQuest2;
void Quests::Hquest1(Player player, Map mapz)
{
	
	if (mHQuest1 == 0)
	{
		cout << "Damn bandits attacking my caravans!";
		cout << "Can you help me ?";
		cout << "I need you to follow my caravan and defend it until you reach the castle (East)(29,66)i ll pay you well\n";
		cout << "1)Accept  2)Decline\n";
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Hope you make it \n";
			
			mHQuest1 = 1;
			break;
		}
		case 2:
			cout << "If you change your mind ill be here\n";
			break;
		default:
			cout << "Wrong input\n"; 
				break;
		}
		
   }
	
	
	else if (mHQuest1 == 4)
	{
		cout << "They attacked again ?...You fought them off ?\n";
		cout << "Great news!\n";
		cout << "Here's your reward\n";

		mExpR += 500;
		mGoldR += 500;
		cout << mExpR << " EXP Gained\n";
		cout << mGoldR << "Gold Gained\n";
		player.reward(mExpR, mGoldR);
		mHQuest1 = 5;
	}
	else if (mHQuest1 == 5)
	{
		cout << "I cant have you protect all of my caravans we need to get to the root of this\n";
		cout << "Talk to (coordinates) i heard he has some news on bandit situation\n";
		mHQuest2 = 1;
	}


}

void Quests::Hquest2(Player player, Map mapz)
{

	cout << "I heard you fought of the bandits,you might be strong enought for this task\n";
	Sleep(300);
	cout << "My scouts located the Bandit hideout,ill mark it on your map (B)\n";
	Sleep(300);
	cout << "They also saw their leader Its the (name) \n";
	Sleep(300);
	cout << "No wonder the bandits are so coordinated\n";
	Sleep(300);
	cout << "Good luck!";
	startingQuest = 3;


}
void Quests::Hquest3(Player player, Map mapz)
{


}

extern int lootChestFlag;
void Quests::LootChest(Player &player, Map &mapz)
{
	if (lootChestFlag == 1)
	{
		cout << endl;
		cout << "Chest already looted\n";
	}
	else
	{
		cout << endl;
		cout << "You open the chest\n";
		int reward = Random(1, 100);
		mExpR += Random(1,50);
		mGoldR += reward;

		player.reward(mExpR,reward);

		cout << "+ " << mExpR << "Exp" << endl;
		cout << "+ " << mGoldR << "Gold" << endl;
		lootChestFlag = 1;
		//% for loot drop
		//% for trap dmg/enemy
		//% 
		
	}
}



Quests::~Quests()
{
}
