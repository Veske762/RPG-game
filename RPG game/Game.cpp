
#include "stdafx.h"
#include "Random.h"
#include "Map.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
#include "Shop.h"
#include <windows.h>
#include <limits>
#include "Abilities.h"

using namespace std;


void gameintro()
{
	cout << "===DESCRIPTION===\n";
	cout << "p - player\n";
	cout << "n - npc/quest giver\n";
	cout << "s - shop\n";
	cout << "d - dungeon\n";
	cout << "? - point of interest\n";
	cout << "C - Loot chest\n";
	cout << "To talk to npc again walk out and then in npc spot\n";
	cout << "Head to the castle (29,66).\n";
}

int main()
{

	gameintro();

	system("Title Game");
#if 0
	system("COLOR 2f");
#endif
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 860, TRUE);

	srand((unsigned int)time(0));

	Shop shopz;
	shopz.ShopInventory();

	
	Map gameMap;

	extern vector<Ability> classAb;
	Player mainPlayer;
	
	
	
	mainPlayer.itemDrop();

	cout << "1)New game 2)Load game";
	int choice = 0;
	Player player;
	Map map;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cin.ignore(256, '\n');

		mainPlayer.createClass();
		break;
	case 2:
	{

		player.Load(player, map);
		break;
	}
	case 3:
	{
	
	}
	case 4:
	{


	
		
	}
		break;
	default:
		cout << "Wrong input\n";
		break;
	}
	
	mainPlayer.Abilityvec();
	system("CLS");
	bool done = true;

	
	gameMap.printPlayerPos();
	
	
	
	while (done ) {
		
		
		gameMap.worldMap(mainPlayer,gameMap);

	
		
		
	
		break;
	}
	
	return 0;
}

