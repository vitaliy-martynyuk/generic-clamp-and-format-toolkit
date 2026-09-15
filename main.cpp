#include "helpers/helpers.h"
#include <iostream>

int main()
{
	using helpers::clamp;
	using helpers::describe;
	using helpers::inRange;
	using helpers::typeName;

	describe("age", clamp(30, 1, 100));
	describe("price", 19.5);
	describe("isActive", true);
	describe("isActive", false);
	describe("temperature", 98.6f);
	describe("count", 0);
	std::cout << inRange(5, 1, 10) << '\n';
	std::cout << inRange(5, 1, 10, false) << '\n';
	std::cout << typeName(1) << '\n';
	std::cout << typeName(1.1) << '\n';
	std::cout << typeName(1.1f) << '\n';
	std::cout << typeName(true) << '\n';
	std::cout << typeName('c') << '\n';
	std::cout << typeName(1u) << '\n';

	return 0;
}