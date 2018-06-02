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
	system("Title Alpha ver 3.3");
#if 0
	system("COLOR 2f");
#endif
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top,800,860, TRUE); // 800 width, 100 height

#if 0
	ofstream fout;
	fout.open("Goldz.txt");
	fout << 0 << endl;
	fout.close();
#endif
	extern vector<Weapon> PlayerI;

	

	srand((unsigned int)time(0));

	Shop shopz;
	shopz.ShopInventory();


	Map gameMap;


	Player mainPlayer;

	mainPlayer.itemDrop();

	mainPlayer.createClass();

	system("CLS");
	bool done = true;

	
	gameMap.printPlayerPos();
	
	
	
	while (done ) {
		

		gameMap.worldMap(mainPlayer,gameMap);

	
		
		
	
		break;
	}
	
	return 0;
}
