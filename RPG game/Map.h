#pragma once

#ifndef MAP_H
#define MAP_H
#include <vector>

#include "Monster.h"
#include <string>
#include <map>

class Map
{
public:
	
	Map();

	void Harbor(Player &player, Map mapz);

	void Dungeon2(Player &player, Map mapz);

	void worldMap(Player &player, Map mapz);

	void Movement(Player &player, Map &mapz,  char mapf[81][81]);

	void Dungeon1(Player &player, Map &mapz);
	
	void Teleport(int &a,int &b);
	
	
	int  getPlayerXPos();

	
	int  getPlayerYPos();

	



	void CastleMap(Player &player, Map map);
	
	void printPlayerPos();

private:
	
	int mPlayerXPos;		
	int mPlayerYPos;		
};

#endif //MAP_H