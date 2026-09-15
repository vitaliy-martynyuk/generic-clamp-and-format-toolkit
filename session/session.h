#ifndef SESSION_H
#define SESSION_H

#include <cstdint>

namespace session
{
	char setFunctionCode();
	std::uint8_t getSessionCounter();
	void endSessionLimitExceeded();
	void endSession();
	bool wasClampUsed();
	bool wasDescribeUsed();
	bool wasInRangeUsed();
	bool wasTypeNameUsed();
}

#endif