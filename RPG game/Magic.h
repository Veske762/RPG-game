#pragma once
#include "Range.h"
#include <string>
#ifndef MAGIC_H
#define MAGIC_H
struct Spell
{
	std::string mName;
	Range mDamageRange;
	int mMagicPointsRequired;
};
#endif