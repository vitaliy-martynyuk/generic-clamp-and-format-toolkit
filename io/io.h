#ifndef IO_H
#define IO_H

namespace io
{
	char getFunctionCode();

	void printFunctionCodeError();
	void printSessionLimitExeededError();

	namespace helpers
	{
		bool recoverInputStream();
	}
}

#endif