#include "clamp.h"

namespace helpers
{
	int clamp(int v, int min, int max)
	{
		if (v <= min) return min;
		if (v >= max) return max;

		return v;
	}

	double clamp(double v, double min, double max)
	{
		if (v <= min) return min;
		if (v >= max) return max;

		return v;
	}

	float clamp(float v, float min, float max)
	{
		if (v <= min) return min;
		if (v >= max) return max;

		return v;
	}
}