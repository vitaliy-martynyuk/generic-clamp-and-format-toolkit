#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"
#include "../consts/consts.h"
#include <cstdint>
#include <iostream>

namespace session
{
	namespace
	{
		using std::uint8_t;
		using std::cout;

		uint8_t sCounter{ 0 };
		uint8_t flags{ 0b0000 };
		const uint8_t clampMask{ 0b1000 };
		const uint8_t describeMask{ 0b0100 };
		const uint8_t inRangeMask{ 0b0010 };
		const uint8_t typeNameMask{ 0b0001 };
	}

	char setFunctionCode()
	{
		while (true) {
			const char code{ io::getFunctionCode() };
			if (io::helpers::recoverInputStream() || !validate::isUserInputValid(code)) {
				io::printFunctionCodeError();
				continue;
			}

			switch (code) {
			case constants::clampCode:
				flags |= clampMask;
				break;
			case constants::describeCode:
				flags |= describeMask;
				break;
			case constants::inRangeCode:
				flags |= inRangeMask;
				break;
			case constants::typeNameCode:
				flags |= typeNameMask;
				break;
			default:
				return code;
			}

			++sCounter;
			return code;
		}
	}

	uint8_t getSessionCounter()
	{
		return sCounter;
	}

	bool wasClampUsed()
	{
		return static_cast<bool>(flags & clampMask);
	}

	bool wasDescribeUsed()
	{
		return static_cast<bool>(flags & describeMask);
	}

	bool wasInRangeUsed()
	{
		return static_cast<bool>(flags & inRangeMask);
	}

	bool wasTypeNameUsed()
	{
		return static_cast<bool>(flags & typeNameMask);
	}

	void endSession()
	{
		cout << "\n-----------------------------------\n";
		cout << "Total functions used: " << static_cast<int>(sCounter) << '\n';
		cout << "clamp used?: " << (wasClampUsed() ? "yes" : "no") << '\n';
		cout << "describe used?: " << (wasDescribeUsed() ? "yes" : "no") << '\n';
		cout << "inRange used?: " << (wasInRangeUsed() ? "yes" : "no") << '\n';
		cout << "typeName used?: " << (wasTypeNameUsed() ? "yes" : "no") << '\n';
	}

	void endSessionLimitExceeded()
	{
		io::printSessionLimitExceededError();
		endSession();
	}
}