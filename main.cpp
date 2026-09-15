#include "helpers/helpers.h"
#include <iostream>

int main()
{
	using helpers::clamp;

	std::cout << clamp(5, 1, 10) << '\n';
	std::cout << clamp(-3, 1, 10) << '\n';
	std::cout << clamp(15, 1, 10) << '\n';
	std::cout << clamp(3.7, 0.0, 5.0) << '\n';
	std::cout << clamp(-1.2, 0.0, 5.0) << '\n';
	std::cout << clamp(9.9f, 0.0f, 1.0f) << '\n';
	std::cout << clamp(1, 1, 10) << '\n';
	std::cout << clamp(10, 1, 10) << '\n';
	std::cout << clamp<double>(5, 1, 10.0) << '\n';

	return 0;
}