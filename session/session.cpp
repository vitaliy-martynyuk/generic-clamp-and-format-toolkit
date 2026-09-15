#include "session.h"
#include "../io/io.h"
#include "../validate/validate.h"
#include <cstdint>

namespace session
{
	namespace
	{
		using std::uint8_t;

		uint8_t sCounter{ 0 };
	}

	char setFunctionCode()
	{
		while (true) {
			const char code{ io::getFunctionCode() };
			if (io::helpers::recoverInputStream() || !validate::isUserInputValid(code)) {
				io::printFunctionCodeError();
				continue;
			}

			++sCounter;
			return code;
		}
	}

	uint8_t getSessionCounter()
	{
		return sCounter;
	}

	void endSessionLimitExeeded()
	{
		io::printSessionLimitExeededError();
	}
}