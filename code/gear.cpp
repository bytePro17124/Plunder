#include "gear.h"
#include "random_gen.h"

using namespace std;

Gear::Gear() {}

Gear::Gear(const int& q, const string& i){
	quantity = q;
	item_name = i;
}

Gear::Gear(const string& i) {
	quantity = 1;
	item_name = i;
}

string Gear::retrieveItemString() {
	string tmp = "";
	tmp += toString(quantity);
	tmp += " ";
	tmp += item_name;
	return tmp;
}
