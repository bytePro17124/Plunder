#include "random_gen.h"

int randomNumber(const int &start, const int &end) {
	std::uniform_int_distribution<int> totalroll(start, end);
	return totalroll(mgen);
}
