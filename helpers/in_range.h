#ifndef IN_RANGE_H
#define IN_RANGE_H

namespace helpers
{
	template <typename T>
	bool inRange(T v, T min, T max, bool inclusive = true)
	{
		if (inclusive) {
			return (v >= min) && (v <= max);
		}

		return (v > min) && (v < max);
	}
}

#endif