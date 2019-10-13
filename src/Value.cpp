#include "Value.h"

Value::Value(int value)
	: int_value(value),
	kind(ValueKind::Integer)
{}

std::ostream &operator<<(std::ostream &out, const Value &v)
{
	switch (v.kind)
	{
		case ValueKind::Integer: out << v.int_value; break;
	}
	return out;
}
