#pragma once

#include <string>

class Gear {
public:
	Gear();

	Gear(const int &, const std::string &);

	explicit Gear(const std::string &);

	std::string retrieveItemString();

protected:
	int quantity = 0;
	std::string item_name = "voidspace - no item";
private:

};
