#pragma once

#include <ostream>

enum class ValueKind
{
	Integer,
};

struct Value
{
	ValueKind kind;
	union
	{
		int int_value;
	};
	Value(int value);
};

std::ostream &operator<<(std::ostream &out, const Value &v);
