#include "stdafx.h"
#include "Map.h"
#include <iostream>
#include "Random.h"
#include <iostream>
#include "Shop.h"
#include "Player.h"
#include <algorithm>
#include "Monster.h"
#include <Windows.h>
#include <cstdlib>
#include "Quests.h"
#include "ConsoleColor.h"




using namespace std;
extern vector<Weapon> val;
extern vector<Weapon> val2;
extern vector<Weapon> val3;
int startingQuest = 0;
int mQuest1 = 0;
int mQuest2 = 1;
int mQuest3 = 0;
int mHQuest1 = 0;
int mHQuest2 = 0;
int monsterFlag = 0;
int monsterBoss1 = 0;
int doorLock = 0;
int lootChestFlag = 0;
int Location = 0;

void Map::Teleport(int &a,int &b)
{
	
	mPlayerXPos = a;
	mPlayerYPos = b;
}

Map::Map()
{
	 mPlayerXPos = 35;
	 mPlayerYPos = 69;
}

int Map::getPlayerXPos()
{
	return mPlayerXPos;
}

int Map::getPlayerYPos()
{
	return mPlayerYPos;
}





void Map::printPlayerPos()
{
	cout << "Player Position = (" << mPlayerXPos << ", "
		<< mPlayerYPos << ")" << endl << endl;
}



void Map::worldMap(Player &player, Map mapz)
{
	Location = 1;
	monsterFlag = 1;
	int mapCounter = 0;
	//make pairs with i pos and type
	char (*a)[81];
	a = new char[81][81]{
		"***************************************************************************",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccc~~~ccccccccccccccccc*",
		"*~~~~ccccccccccc~~~~~~~~~~cccccccccccccccccccccccccc~~~~~~~~cccccccccc~~~~*",
		"*~~~~~~~~~~~~~~~~~~~~~~~~~~~~cccccccccccccccc~~~~~~~~~~~~~~~~~~~ccc~~~~~~~*",
		"*c~~~~~~~~~~~~~~~ccccccc~~~~~~~~~~~ccccccc~~~~~~~~~~ccccccccc~~~~~~~~~cccc*",
		"*ccccc~~~~~~ccccccccccccccc~~~~~~~~~~~~~~~~~~~cccccccccccccccccc~~~~cccccc*",
		"*cccccccccccccccccccccccccccccccc~~~~~~~cccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*****ccccc*",
		"*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc**c**ccccc*",
		"~~cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~*******ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~ccccc*ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~c*ccccccccccBcccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~~cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~~~~~~***********************************************************",
	};
	
	
	bool game = true;
	while (game) {

		int mapCounter = 0;
		
		cout <<"Use arrow keys for movement\n" << endl;
		cout << mPlayerXPos << "," << mPlayerYPos << endl;
		for (int i = 0; i < 42; i++)
		{
			
			for (int j = 0; j < 75; j++)
			{


				if (mapCounter == 75)
				{
					cout << "" << endl;
					mapCounter = 0;
				}

				if (a[i][j] == '*')
				{
					cout << "*";
				}
				else if (a[i][j] == '~')
				{
					cout <<'~';
				}
				else if (a[i][j] == 'B')
				{
					if (startingQuest == 4)
					{
						cout << 'B';
					}
					else
						cout << ' ';
				}

				else if (a[i][j] == 'c')
				{
					
					 if (a[i == mPlayerXPos][j == mPlayerYPos] == 'c')
					{						
						cout << 'p';	 
					}
					else if ((a[i == 34][j == 53]== 'c'))
					{
						cout << 'd';
					}
					else if ((a[i == 23][j == 70] == 'c'))
					{
						cout << 'd';
					}			
					else cout << ' ';

				}



				mapCounter++;
			}

		}
		
		if (mHQuest1 == 1)
		{

			if (mPlayerYPos == 37)
			{
				monsterFlag = 19;
				player.Combat(player, mapz);
				monsterFlag = 1;
			}			
		}		
		else if (mPlayerXPos == 36 && mPlayerYPos == 12)
		{

			mPlayerXPos = 10;
			mPlayerYPos = 59;
			delete[] a;
			Harbor(player, mapz);
			break;
			system("CLS");
	    }	 
		if (mPlayerXPos == 29 && mPlayerYPos == 66)
		{
			mPlayerXPos = 18;
			mPlayerYPos = 28;
			delete[] a;
			if (mHQuest1 == 3)
			{
				cout << "Caravan arived safely\n";
				cout << "Return to harbor for your reward \n";
				system("PAUSE");
				mHQuest1 = 4;
			}
			CastleMap(player, mapz);
		
			break;
			system("CLS");
		}
		else if (mPlayerXPos == 34 && mPlayerYPos == 53)
		{
			mPlayerXPos = 10;
			mPlayerYPos = 2;
			delete[] a;
			Dungeon1(player, mapz);
			system("CLS");
		}
		else if (mPlayerXPos == 23 && mPlayerYPos == 70)
		{
			mPlayerXPos = 10;
			mPlayerYPos = 2;
			delete[] a;
			Dungeon2(player, mapz);
			system("CLS");
			break;
		}
		Movement(player, mapz, a);
		
		if (GetAsyncKeyState(81))
		{
			cout << "Are you sure press 1 to continue playing 2 to quit\n";
			int a = 0;
			cin >> a;
			switch (a)
			{
			case 1:
				game = false;
				
			case 2:

				break;
			default :
				cout << "Wrong input\n";
				break;
			}
		}
		
		
		
		system("CLS");
	}

}

	void Map::Dungeon1(Player &player, Map &mapz)
	{
		Location = 2;
		lootChestFlag = 0;
		monsterFlag = 2;
		int mapCounter = 0;
		char(*c)[81];
		c = new char[81][81]
		{
			"****************************************",
			"*cccccccccccccccccccccccccccccccccccccc*",
			"*ccccccccccccc*************ccccccccc*cc*",
			"*ccc****cccccccccccccccccccccccccccc*cc*",
			"*ccc*cc*cccccccccc*****ccccccccccccc*cc*",
			"*ccc*cc*cccccccccc*****ccccccccccccc*cc*",
			"*ccc*cc*cccccccccccccccccccccccccccc*cc*",
			"*ccc*cc*cccccccccccccccccccccccccccc*cc*",
			"*ccc*cc******************************cc*",
			"*ccc*cccccccccccccccccccccccccccccccccc*",
			"**cc************************************",

		};
		int posx = 0;
		int posy = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 41; j++)
			{
				c[posx = Random(1, 11)][posy = Random(1, 41)];
					
			}
		}
		while (true)
		{
			if (mPlayerXPos == 11 && mPlayerYPos == 2 || mPlayerXPos == 11 && mPlayerYPos == 3)
			{

				mPlayerXPos = 35;
				mPlayerYPos = 53;
				delete[] c;
				worldMap(player, mapz);
				break;
			}
			cout << "Use arrow keys for movement\n";
			cout << mPlayerXPos << "," << mPlayerYPos << endl;
			for (int i = 0; i < 11; i++)
			{

				for (int j = 0; j < 41; j++)
				{

					if (mapCounter == 41)
					{
						cout << "" << endl;
						mapCounter = 0;
					}

					if (c[i][j] == '*')
					{
						cout << "*";
					}
					else if (c[i==3][j==38] == 'c')
					{

							cout << '?';
				
					}
					else if (c[i == posx][j == posy]=='c')
					{
						cout << 'C';
					}
					else if (c[i][j] == 'c')
					{

						if (c[i == mPlayerXPos][j == mPlayerYPos] == 'c')
						{
							cout << 'p';



						}
						else if ((c[i == 11][j == 2] == 'c'))
						{
							cout << 's';
						}
						else cout << ' ';
					}
					mapCounter++;
				}

			}
			if (mPlayerXPos == posx && mPlayerYPos == posy)
			{
				Quests chest;
				chest.LootChest(player, mapz);
				
			}
			else if (mPlayerXPos == 3 && mPlayerYPos == 38)
				{
					if (mQuest3 == 2)
					{
						cout << endl << "There is nothing there you already looted the artifact\n";
					}
					else if (mQuest3==1)
					{
						cout << endl << "You looted the artifact" << endl;
						mQuest3 = 2;
					}
				}
			
			Movement(player, mapz, c);

		}
		system("CLS");
	}

	
	void Map::Dungeon2(Player &player, Map mapz)
	{
		Location = 3;
		monsterFlag = 2;
		int mapCounter = 0;
		char(*d)[81];
		d = new char[81][81]
		{
			"****************************************",
			"*ccccc*cccccccccccccccccccccccccccccccc*",
			"*ccccc*ccccccccccccccccccccccccccccc****",
			"*ccccc*ccc*ccc*ccc*ccc*ccc*ccc*ccccc*cc*",
			"*ccccc*cccccccccccccccccccccccccccc**cc*",
			"*ccccc?ccccccccccccccccccccccccccccK*cc*",
			"*ccccc*cccccccccccccccccccccccccccc**cc*",
			"*ccccc*ccc*ccc*ccc*ccc*ccc*ccc*ccccc*cc*",
			"*ccccc*ccccccccccccccccccccccccccccc****",
			"*ccccc*cccccccccccccccccccccccccccccccc*",
			"**cc************************************",

		};

		while (true)
		{

			if (mPlayerXPos == 11 && mPlayerYPos == 2 || mPlayerXPos == 11 && mPlayerYPos == 3)
			{

				mPlayerXPos = 24;
				mPlayerYPos = 70;
				delete[] d;
				worldMap(player, mapz);
				break;
			}
			cout << "Use arrow keys for movement\n";
			cout << mPlayerXPos << "," << mPlayerYPos << endl;
			for (int i = 0; i < 11; i++)
			{

				for (int j = 0; j < 41; j++)
				{

					if (mapCounter == 41)
					{
						cout << "" << endl;
						mapCounter = 0;
					}

					if (d[i][j] == '*')
					{
						cout << "*";
					}
					else if (d[i][j] == '~')
					{
						cout << '~';
					}
					else if (d[i][j] == 'K')
					{
						cout << 'K';
					}
				
					if (d[i][j] == '?')
					{
							cout << '?';
						
					}
					else if (d[i][j] == 'c')
					{

						if (d[i == mPlayerXPos][j == mPlayerYPos] == 'c')
						{
							cout << 'p';



						}
						else if ((d[i == 11][j == 2] == 'c'))
						{
							cout << 's';
						}
						else cout << ' ';

					}



					mapCounter++;
				}

			}
			
			if (doorLock == 0)
			{
				if (mPlayerXPos == 5 && mPlayerYPos == 6)
				{
					cout <<endl <<"Door is locked... it has a platform in middle\n";
					mPlayerXPos = 5;
					mPlayerYPos = 5;

				}
			}
			else if (doorLock == 1)
				{
					if (mPlayerXPos == 5 && mPlayerYPos == 6)
					{
						cout <<endl <<"You put the artifact in the middle of the door...";
						Sleep(700);
						cout << "Door has been unlocked\n";
					}
				}
		
			
			if ( monsterBoss1 == 0)
			{
				if (mPlayerXPos == 5 && mPlayerYPos == 34)
				{
					monsterBoss1 = 1;
					monsterFlag = 20;
					player.Combat(player, mapz);
					monsterFlag = 2;
					monsterBoss1 = -1;
				}
			}
			Movement(player, mapz, d);

		}
		system("CLS");
	}
	
void Map::Movement(Player &player, Map &mapz, char mapf[81][81])
{
	cout << endl;
	cout << "Press I to view inventory | C to view stats | R to rest | S to save game";
	cout << endl;
	int roll = Random(0,255);
	system("pause>nul");
	if (GetAsyncKeyState(38))
	{
		if (roll >= 1 && roll <= 15)
		{
			player.Combat(player, mapz);
			system("CLS");
		}
		else if (mapf[mPlayerXPos - 1][mPlayerYPos] == '*'||mapf[mPlayerXPos - 1][mPlayerYPos] == '~')
		{
			mPlayerXPos;
		}
		else
			mPlayerXPos--;

	}
	else if (GetAsyncKeyState(40))
	{
		if (roll >= 1 && roll <= 15)
		{
			player.Combat(player, mapz);
			system("CLS");
		}
		else if (mapf[mPlayerXPos + 1][mPlayerYPos] == '*' || mapf[mPlayerXPos + 1][mPlayerYPos] == '~')
		{
			mPlayerXPos;
		}
		else
			mPlayerXPos++;

	}
	else if (GetAsyncKeyState(37))
	{
		if (roll >= 1 && roll <= 15)
		{
			player.Combat(player, mapz);
			system("CLS");
		}
		else if (mapf[mPlayerXPos][mPlayerYPos - 1] == '*' || mapf[mPlayerXPos][mPlayerYPos - 1] == '~')
		{
			
			mPlayerXPos;
		}
		else
			mPlayerYPos--;

	}
	else if (GetAsyncKeyState(39))
	{
		if (roll >= 1 && roll <= 15)
		{
			player.Combat(player, mapz);
			system("CLS");
		}
		else if (mapf[mPlayerXPos][mPlayerYPos + 1] == '*' || mapf[mPlayerXPos][mPlayerYPos + 1] == '~')
		{
			mPlayerXPos;
		}
		else
			mPlayerYPos++;
	}
	else if (GetAsyncKeyState(83))
	{
		player.Save(player,mapz);
		cout << "Game saved\n";
		
	}
	else if (GetAsyncKeyState(73))
	{
		extern vector<Weapon> PlayerI;
		Shop w;
		w.PlayerInventory();
		cout << "1)Equip items 2)Unequip items 3)Exit Inventory\n";
		int choice2 = 0;


		cin >> choice2;
		switch (choice2)
		{
		case 1:
			if (PlayerI.size() == 0)
			{
				cout << "No items in inventory\n";
				system("PAUSE");
				break;
			}
			else
				player.Equip(PlayerI);
			system("PAUSE");
			break;

		case 2:
			if (PlayerI.size() == 0)
			{
				cout << "No items in inventory\n";
				system("PAUSE");
				break;
			}
			else
				player.Unequip(PlayerI);
			system("PAUSE");
			break;

		}

	}
	else if (GetAsyncKeyState(82))
	{

		player.rest();

	}
	else if (GetAsyncKeyState(67))
	{
		player.viewStats();
		system("PAUSE");
	}
	
	system("CLS");
}



void Map::Harbor(Player &player, Map mapz)
{
	Location = 4;
	int mapCounter = 0;
	monsterFlag = 15;
	char(*b)[81];
	b = new char[81][81]
	{
		"************************************************************",
		"*cccccccccccccccc*cccccc*cccccccc*ccccccccccccccccccccccccc*",
		"~~~~~cccccccccccc*cccccc*cccccccc*ccccccccccccccccccccccccc*",
		"~~~~~~ccccccccccc***cc******cc***************cc*************",
		"~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~~~~~~~~ccccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~*********ccccccccccccccccccccccccccccccccccccccccccccc*",
		"~~~~~*cccccccccccccccccccccc******cc******cccccccccccccccccc",
		"~~~~~*cccccccccccccccccccc**cccccccccccccc**cccccccccccccccc",
		"~~~~~*************ccccccc**ccccc******cccccc**cccccccccccccc",
		"~~~~~~~~~~~~~~~~~~cccccccc**cccccccccccccc**ccccccccccccccc*",
		"~~~~~~~~~~~~~~~~~~~~cccccccc**************ccccccccccccccccc*",
		"~~~~~******************ccccccccccccccccccccccccccc****cc****",
		"~~~~~*cccccccccccccccccccccccccccccccccccccccccccc*cccccccc*",
		"~~~~~*cccccccccccccccccccccccccccccccccccccccccccc*cccccccc*",
		"~~~~~***********************cccccccccccccccccccccc*cccccccc*",
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~********************************",



	};
	while (true) {		
		cout << "Use arrow keys for movement\n";
		cout << mPlayerXPos << "," << mPlayerYPos << endl;
		for (int i = 0; i < 20; i++)
		{

			for (int j = 0; j < 60; j++)
			{

				if (mapCounter == 60)
				{
					cout << "" << endl;
					mapCounter = 0;
				}

				if (b[i][j] == '*')
				{
					cout << "*";
				}
				else if (b[i][j] == '~')
				{
					cout << '~';
				}

				else if (b[i][j] == 'c')
				{
					if (b[i == mPlayerXPos][j == mPlayerYPos] == 'c')
					{
						cout << 'p';
					}
					else if (b[i == 1][j == 45] == 'c')
					{
						cout << 's';
					}
					else if (b[i == 1][j == 20] == 'c')
					{
						cout << 's';
					}
					else if (b[i == 1][j == 29] == 'c')
					{
						cout << 'n';
					}
					else if (b[i == 17][j == 54] == 'c')
					{
						cout << 'n';
					}
					else if (b[i == 9][j == 6] == 'c')
					{
						cout << 'n';
					}
					else
						cout << ' ';
				}
				

				mapCounter++;
			}

		}
		if (mPlayerXPos == 1 && mPlayerYPos == 45)
		{
			Shop shop;
			shop.EnterShop(player, val3);
		}
		else if (mPlayerXPos == 1 && mPlayerYPos == 29)
		{
			Quests quest;
			quest.Hquest1(player, mapz);
		}
		else if (mHQuest2 == 1)//first quest ends
		{
		 if (mPlayerXPos == 17 && mPlayerYPos == 54)
		 {
			Quests quest2;
			quest2.Hquest2(player, mapz);
	 	 }
		}
		else if (mPlayerXPos == 1 && mPlayerYPos == 20)
		{
			Shop shop;
			shop.EnterShop(player,val2);
		}
		if (mPlayerXPos == 9 && mPlayerYPos == 60 || mPlayerXPos == 10 && mPlayerYPos == 60 || mPlayerXPos == 11 && mPlayerYPos == 60)
		{
			mPlayerXPos = 36;
			mPlayerYPos = 13;
			delete[] b;
			worldMap(player, mapz);

			break;
			system("CLS");
		}
		Movement(player, mapz, b);
		system("CLS");
	}

}

void Map::CastleMap(Player &player, Map mapz)
{
	Location = 5;
	monsterFlag = 15;//set monster flag to nothing

	int mapCounter = 0;

	char(*b)[81];
	b = new char[81][81]
	{
		"************************************************************",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccc***************ccccccccccccccccc******************cccc*",
		"*cccc*ccccccccccccc*ccccccccccccccccc*cccccccccccccccc*cccc*",
		"*cccc*ccccccccccccc********cccc*******cccccccccccccccc*cccc*",
		"*cccc*cccccccccccccccccccccccccccccccccccccccccccccccc*cccc*",
		"*cccc*cccccccccccccccccccccccccccccccccccccccccccccccc*cccc*",
		"*cccc*cccccccccccccccccccccc*ccccccccccccccccccccccccc*cccc*",
		"******ccccccccccccccccccccc***cccccccccccccccccccccccc******",
		"*cccc*cccccccccccccccccccccc*ccccccccccccccccccccccccc*cccc*",
		"*cccc*ccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccc*cccccccccccccccccccccccccccccccccccccccccccccccc*cccc*",
		"**c***cccccccccccccccccccccccccccccccccccccccccccccccc******",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"*cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc*",
		"**************************ccccc*****************************",



	};
	while (true) {
		
		if (mPlayerXPos == 19 && mPlayerYPos == 26 || mPlayerXPos == 19 && mPlayerYPos == 27 || mPlayerXPos == 19 && mPlayerYPos == 28 || mPlayerXPos == 19 && mPlayerYPos == 29 || mPlayerXPos == 19 && mPlayerYPos == 29 || mPlayerXPos == 19 && mPlayerYPos == 30)
		{
			
			mPlayerXPos = 30;
			mPlayerYPos = 66;
			delete[] b;
			worldMap(player, mapz);
			
		}
		cout << "Use arrow keys for movement\n";
		cout << mPlayerXPos << "," << mPlayerYPos << endl;
		for (int i = 0; i < 20; i++)
		{

			for (int j = 0; j < 60; j++)
			{

				if (mapCounter == 60)
				{
					cout << "" << endl;
					mapCounter = 0;
				}

				if (b[i][j] == '*')
				{
					cout << "*";
				}
				
				else if (b[i][j] == 'c')
				{

					if (b[i == mPlayerXPos][j == mPlayerYPos] == 'c')
					{
						cout << 'p';



					}
					else if ((b[i == 11][j == 2] == 'c'))
					{
						cout << 's';
					}
					else if (b[i == 12][j == 58] == 'c')
					{
						cout << 'n';
					}
					else if (b[i == 12][j == 44] == 'c')
					{
						cout << 'n';
					}
					else
						cout << " ";


				}


				mapCounter++;
			}

		}
		
			Quests w;
		
		if (mPlayerXPos == 12 && mPlayerYPos == 44)
		{
			
			if (startingQuest == 0)
			{
				
				w.Quest1(player, mapz);
			}
		}
			if (mPlayerXPos == 12 && mPlayerYPos == 58)
			{
				if (startingQuest == 0)
				{
					cout << "You dont look strong enough for my task,go try your self at the arena and come back to me with the title of Gladiator\n";
				}
				
				if (startingQuest == 2)
				{
					
					w.Quest2(player, mapz);
				}
				if (startingQuest == 3)
				{
					
					w.Quest3(player, mapz);
				}

			}
			else if (mPlayerXPos == 1 && mPlayerYPos == 28)
			{
				Quests quest;
				quest.Hquest1(player, mapz);
			}
		if (getPlayerXPos() == 11 && getPlayerYPos() == 2)
		{
			Shop f;
			f.EnterShop(player, val);
		}

		Movement(player, mapz, b);
		
	}
	
}

	
