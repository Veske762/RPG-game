#pragma once
#ifndef ABILITIES_H
#define ABILITIES_H
#include <string>
#include "Range.h"
#include <vector>
#include "Monster.h"
using namespace std;
struct Ability
{
public:
	Ability(std::string name,int lowdmg,int highdmg,int aoes,int stuns,int bleeds,int poisons,int type,int cd,int cdmax);
	Ability() {};

	std::string mName;
	Range mDamageRange;
	int mLow;
	int mHigh;
	int aoe;
	int stun;
	int bleed;
	int poison;
	int types;
	int coolDown;
	int coolDownMax;


	void HighDmgStrike(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy,int abselect);
	void Stuns(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, int selection, std::vector<Monster> &monst,int abselect);
	void Aoe(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, std::vector<Monster> &monst,int abselect);
	void Bleed(std::vector<Ability> &ability, Monster &monster, Weapon mWeapon, int mAccuracy, int selection, std::vector<Monster> &monst,int abselect);

};

#endif