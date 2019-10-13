#pragma once

#include <ostream>

enum class ValueKind
{
	Integer,
	Boolean,
};

struct Value
{
	ValueKind kind;
	union
	{
		int int_value;
		bool bool_value;
	};
	Value(int value);
	Value(bool value);
};

std::ostream &operator<<(std::ostream &out, const ValueKind &k);
std::ostream &operator<<(std::ostream &out, const Value &v);
