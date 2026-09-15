#ifndef TYPE_NAME_H
#define TYPE_NAME_H

#include <string_view>

namespace helpers
{
	template <typename T>
	std::string_view typeName(T)
	{
		return "unsupported";
	}

	template <>
	std::string_view typeName<int>(int)
	{
		return "int";
	}

	template <>
	std::string_view typeName<float>(float)
	{
		return "float";
	}

	template <>
	std::string_view typeName<bool>(bool)
	{
		return "bool";
	}

	template <>
	std::string_view typeName<double>(double)
	{
		return "double";
	}
}

#endif // !TYPE_NAME_H
