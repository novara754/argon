#include "Value.h"

Value::Value(int value)
	: int_value(value),
	kind(ValueKind::Integer)
{}

Value::Value(bool value)
	: bool_value(value),
	kind(ValueKind::Boolean)
{}

Value::Value(Node *function_body)
	: function_body(function_body),
	kind(ValueKind::Function)
{}

std::ostream &operator<<(std::ostream &out, const ValueKind &kind)
{
#define KIND_TO_STR(kind, name) case kind: kind_str = #name; break
	std::string kind_str;
	switch (kind)
	{
		KIND_TO_STR(ValueKind::Integer, Integer);
		KIND_TO_STR(ValueKind::Boolean, Boolean);
		KIND_TO_STR(ValueKind::Function, Function);
	}
	return out << kind_str;
#undef KIND_TO_STR
}

std::ostream &operator<<(std::ostream &out, const Value &v)
{
	switch (v.kind)
	{
		case ValueKind::Integer: out << v.int_value; break;
		case ValueKind::Boolean: out << (v.bool_value ? "true" : "false"); break;
		case ValueKind::Function: out << "#fun"; break;
	}
	return out;
}
