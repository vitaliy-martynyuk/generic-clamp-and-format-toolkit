#ifndef SESSION_H
#define SESSION_H

#include <cstdint>

namespace session
{
	char setFunctionCode();
	std::uint8_t getSessionCounter();
	void endSessionLimitExeeded();
}

#endif