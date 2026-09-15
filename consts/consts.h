#ifndef CONSTS_H
#define CONSTS_H

#include <cstdint>

namespace constants
{
	constexpr char clampCode{ 'c' };
	constexpr char describeCode{ 'd' };
	constexpr char inRangeCode{ 'r' };
	constexpr char typeNameCode{ 't' };
	constexpr char quitCode{ 'q' };
	constexpr std::uint8_t sessionLimit{ 2 };
}

#endif