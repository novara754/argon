#pragma once

#include <ostream>
class Node;

enum class ValueKind
{
	Integer,
	Boolean,
	Function,
};

struct Value
{
	ValueKind kind;
	union
	{
		int int_value;
		bool bool_value;
		Node *function_body;
	};
	Value() = default;
	Value(int value);
	Value(bool value);
	Value(Node *function_body);
};

std::ostream &operator<<(std::ostream &out, const ValueKind &k);
std::ostream &operator<<(std::ostream &out, const Value &v);
