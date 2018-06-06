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

using namespace std;


void gameintro()
{
	cout << "==DESCRIPTION==\n";
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

	system("Title Alpha ver 3.4");
#if 0
	system("COLOR 2f");
#endif
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 800, 860, TRUE); // 800 width, 100 height








	srand((unsigned int)time(0));

	Shop shopz;
	shopz.ShopInventory();


	Map gameMap;


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
		fflush(stdin);
		mainPlayer.createClass();
		break;
	case 2:
	{

		player.Load(player, map);
		break;
	}
	default:
		cout << "Wrong input\n";
		break;
	}

	
		
	
	system("CLS");
	bool done = true;

	
	gameMap.printPlayerPos();
	
	
	
	while (done ) {
		
		
		gameMap.worldMap(mainPlayer,gameMap);

	
		
		
	
		break;
	}
	
	return 0;
}

