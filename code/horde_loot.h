#pragma once

#include "gear.h"
#include <vector>

/// This class relies on the artObjects.dat and gems.dat files
class Gear;

class Horde_Loot {

public:

	friend class SceneManager;

private:

	std::vector<Gear> full_gear_list;

	void GenerateHoardTreasureCR_0_4();
	void GenerateHoardTreasureCR_5_10();
	void GenerateHoardTreasureCR_11_16();
	void GenerateHoardTreasureCR_17();

	Gear TableA();
	Gear TableB();
	Gear TableC();
	Gear TableD();
	Gear TableE();
	Gear TableF();
	Gear TableG();
	Gear TableH();
	Gear TableI();

	std::string GenerateScroll(const int&) const;
	std::string GenerateGemstone(const int&, const int&) const;
	std::string GenerateArt(const int&, const int&) const;
};
