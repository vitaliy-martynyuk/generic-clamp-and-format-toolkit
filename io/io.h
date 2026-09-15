#ifndef IO_H
#define IO_H

namespace io
{
	char getFunctionCode();

	void printFunctionCodeError();
	void printSessionLimitExceededError();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif