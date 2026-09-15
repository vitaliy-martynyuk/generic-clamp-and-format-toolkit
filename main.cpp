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
			session::endSession();
			return EXIT_SUCCESS;
		case constants::clampCode:
			std::cout << "clamp(10, 1, 5) = " << helpers::clamp(10, 1, 5) << '\n';
			break;
		case constants::describeCode:
			std::cout << "describe(\"label\", 16.5f) = ";
			helpers::describe("label", 16.5f);
			break;
		case constants::inRangeCode:
			std::cout << "inRange(10, 1, 10, false) = " << helpers::inRange(10, 1, 10, false) << '\n';
			break;
		case constants::typeNameCode:
			std::cout << "typeName(12.0f) = " << helpers::typeName(12.0f) << '\n';
			break;
		default:
			assert(false && "Invalid code!");
		}
	}

	session::endSessionLimitExceeded();

	return EXIT_SUCCESS;
}