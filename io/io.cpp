#include "io.h"
#include "../consts/consts.h"
#include <iostream>
#include <limits>

namespace io
{
	namespace
	{
		using std::cin;
		using std::cout;
		using std::numeric_limits;
		using std::streamsize;
	}

	char getFunctionCode()
	{
		cout << "Enter function code ('"
			<< constants::clampCode << "' - clamp, '"
			<< constants::inRangeCode << "' - inRange, '"
			<< constants::describeCode << "' - describe, '"
			<< constants::typeNameCode << "' - typeName) or '"
			<< constants::quitCode << "' to quit: ";
		char input{};
		cin >> input;

		return input;
	}

	void printFunctionCodeError()
	{
		cout << "Invalid code! (must be '"
			<< constants::clampCode << "', '"
			<< constants::inRangeCode << "', '"
			<< constants::describeCode << "', or '"
			<< constants::typeNameCode << "')\n";
	}

	void printSessionLimitExceededError()
	{
		cout << "\nSession limit exceeded! Quitting...\n";
	}

	namespace helpers
	{
		bool recoverInputStream()
		{
			const bool hasUnextractedInput{ !cin.eof() && cin.peek() != '\n' };
			if (!cin || hasUnextractedInput) {
				if (cin.eof()) {
					std::exit(1);
				}

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				return true;
			}

			return false;
		}
	}
}