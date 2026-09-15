#include "helpers/helpers.h"
#include "session/session.h"
#include "consts/consts.h"
#include <iostream>
#include <cassert>

int main()
{
	while (session::getSessionCounter() < constants::sessionLimit) {
		const char code{ session::setFunctionCode() };
		switch (code) {
		case constants::quitCode:
			std::cout << "Quitting...\n";
			return EXIT_SUCCESS;
		case constants::clampCode:
			std::cout << "Using clamp...\n";
			break;
		case constants::describeCode:
			std::cout << "Using describe...\n";
			break;
		case constants::inRangeCode:
			std::cout << "Using inRange...\n";
			break;
		case constants::typeNameCode:
			std::cout << "Using inRange...\n";
			break;
		default:
			assert(false && "Invalid code!");
		}
	}

	session::endSessionLimitExeeded();

	return EXIT_SUCCESS;
}