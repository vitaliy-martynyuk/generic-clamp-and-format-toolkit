#ifndef CLAMP_H
#define CLAMP_H

#include <string_view>
#include <iostream>
#include <iomanip>

namespace helpers
{
	using std::string_view;
	using std::cout;

	template <typename T>
	T clamp(T v, T min, T max)
	{
		if (v <= min) return min;
		if (v >= max) return max;

		return v;
	}

	inline void describe(string_view label, int value)
	{
		cout << label << ": " << value << '\n';
	}

	inline void describe(string_view label, double value)
	{
		cout << std::setprecision(5) << label << ": " << value << '\n';
	}

	inline void describe(string_view label, float value)
	{
		cout << std::setprecision(5) << label << ": " << value << 'f' << '\n';
	}

	inline void describe(string_view label, bool value)
	{
		cout << std::boolalpha << label << ": " << value << '\n';
	}

	template <typename T>
	void describe(string_view, T) = delete;
}

#endif