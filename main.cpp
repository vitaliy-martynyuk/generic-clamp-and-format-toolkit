#include "helpers/helpers.h"
#include <iostream>

int main()
{
	using helpers::clamp;
	using helpers::describe;

	describe("age", clamp(30, 1, 100));
	describe("price", 19.5);
	describe("isActive", true);
	describe("isActive", false);
	describe("temperature", 98.6f);
	describe("count", 0);

	return 0;
}