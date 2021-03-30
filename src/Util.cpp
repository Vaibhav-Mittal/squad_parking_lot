#include "Util.h"
#include <sstream>

int Util::strToInt(const std::string &str)
{
	std::stringstream ss(str); // parking slot number
	int slot_number = 0;
	ss >> slot_number;
	return slot_number;
}
