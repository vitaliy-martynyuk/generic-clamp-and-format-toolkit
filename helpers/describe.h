#ifndef DESCRIBE_H
#define DESCRIBE_H

#include <string_view>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace helpers
{
	inline void describe(std::string_view label, int value)
	{
		std::cout << label << ": " << value << '\n';
	}

	inline void describe(std::string_view label, double value)
	{
		std::ostringstream oss{};
		oss << std::fixed << std::setprecision(4) << label << ": " << value << '\n';
		std::cout << oss.str();
	}

	inline void describe(std::string_view label, float value)
	{
		std::ostringstream oss{};
		oss << std::fixed << std::setprecision(2) << label << ": " << value << '\n';
		std::cout << oss.str();
	}

	inline void describe(std::string_view label, bool value)
	{
		std::cout << label << ": " << (value ? "yes" : "no") << '\n';
	}

	template <typename T>
	void describe(std::string_view, T) = delete;
}

#endif