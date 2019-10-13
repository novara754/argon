#include "Value.h"

Value::Value(int value)
	: int_value(value),
	kind(ValueKind::Integer)
{}

Value::Value(bool value)
	: bool_value(value),
	kind(ValueKind::Boolean)
{}

std::ostream &operator<<(std::ostream &out, const Value &v)
{
	switch (v.kind)
	{
		case ValueKind::Integer: out << v.int_value; break;
		case ValueKind::Boolean: out << (v.bool_value ? "true" : "false"); break;
	}
	return out;
}
