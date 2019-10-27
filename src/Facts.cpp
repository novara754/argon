#include "Facts.h"

static const TokenKind precedence_order[] = {
	TokenKind::Or,
	TokenKind::And,
	TokenKind::BangEqual,
	TokenKind::EqualEqual,
	TokenKind::GreaterThan,
	TokenKind::GreaterThanEqual,
	TokenKind::LessThan,
	TokenKind::LessThanEqual,
	TokenKind::Minus,
	TokenKind::Plus,
	TokenKind::Slash,
	TokenKind::Star,
};

static const BinaryOperator binary_operators[] = {
	{ TokenKind::Plus, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value + right.int_value; } },
	{ TokenKind::Minus, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value - right.int_value; } },
	{ TokenKind::Star, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value * right.int_value; } },
	{ TokenKind::Slash, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value / right.int_value; } },
	{ TokenKind::LessThan, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value < right.int_value; } },
	{ TokenKind::LessThanEqual, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value <= right.int_value; } },
	{ TokenKind::GreaterThan, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value > right.int_value; } },
	{ TokenKind::GreaterThanEqual, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value >= right.int_value; } },
	{ TokenKind::And, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value && right.bool_value; } },
	{ TokenKind::Or, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value || right.bool_value; } },
	{ TokenKind::EqualEqual, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value == right.int_value; } },
	{ TokenKind::BangEqual, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value != right.int_value; } },
	{ TokenKind::EqualEqual, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value == right.bool_value; } },
	{ TokenKind::BangEqual, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value != right.bool_value; } },
};

int GetBinaryOperatorPrecedence(TokenKind kind)
{
	auto itr = std::find(std::begin(precedence_order), std::end(precedence_order), kind);
	if (itr == std::end(precedence_order))
		return -1;
	else
		return std::distance(precedence_order, itr);
}

std::optional<BinaryOperator> GetBinaryOperator(TokenKind op, ValueKind left, ValueKind right)
{
	auto itr = std::find_if(std::begin(binary_operators), std::end(binary_operators), [op, left, right](const BinaryOperator &bin_op)
	{
		return bin_op.op == op && bin_op.left == left && bin_op.right == right;
	});

	return itr != std::end(binary_operators) ? *itr : std::optional<BinaryOperator>();
}

bool CharacterIsNumber(char c) {
	return std::isdigit(c)
		|| c == '_';
}

bool CharacterIsIdentifier(char c) {
	return std::isalpha(c)
		|| c == '_';
}
