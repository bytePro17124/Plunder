#include "gear.h"

Gear::Gear() = default;

Gear::Gear(const int &q, const std::string &i) {
	quantity = q;
	item_name = i;
}

Gear::Gear(const std::string &i) {
	quantity = 1;
	item_name = i;
}

std::string Gear::retrieveItemString() {
	std::string tmp;
	tmp = "";
	tmp += std::to_string(quantity);
	tmp += " ";
	tmp += item_name;
	return tmp;
}
