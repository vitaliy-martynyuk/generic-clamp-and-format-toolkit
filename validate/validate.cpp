#include "validate.h"
#include "../consts/consts.h"

namespace validate
{
	bool isFunctionCodeValid(char c)
	{
		switch (c) {
		case constants::clampCode:
		case constants::describeCode:
		case constants::inRangeCode:
		case constants::typeNameCode:
			return true;
		default:
			return false;
		}
	}

	bool isUserInputValid(char c)
	{
		return isFunctionCodeValid(c) || (c == constants::quitCode);
	}
}