#include "Value.h"

Value::Value(int value)
	: int_value(value),
	kind(ValueKind::Integer)
{}

Value::Value(bool value)
	: bool_value(value),
	kind(ValueKind::Boolean)
{}

std::ostream &operator<<(std::ostream &out, const ValueKind &kind)
{
#define KIND_TO_STR(kind) case ValueKind::##kind: kind_str = #kind; break
	std::string kind_str;
	switch (kind)
	{
		KIND_TO_STR(Integer);
		KIND_TO_STR(Boolean);
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
	}
	return out;
}
