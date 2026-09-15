#ifndef CLAMP_H
#define CLAMP_H

namespace helpers
{
	template <typename T>
	T clamp(T v, T min, T max)
	{
		if (v <= min) return min;
		if (v >= max) return max;

		return v;
	}
}

#endif