#pragma once

#include <algorithm>
#include <optional>
#include <functional>
#include "Token.h"
#include "Value.h"

struct BinaryOperator
{
	TokenKind op;
	ValueKind left;
	ValueKind right;
	std::function<Value(Value, Value)> Operate;
};

const TokenKind PrecedenceOrder[] = {
	TokenKind::Plus,
	TokenKind::Minus,
	TokenKind::Star,
	TokenKind::Slash,
	TokenKind::And,
	TokenKind::Or,
};

const BinaryOperator BinaryOperators[] = {
	{ TokenKind::Plus, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value + right.int_value; } },
	{ TokenKind::Minus, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value - right.int_value; } },
	{ TokenKind::Star, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value * right.int_value; } },
	{ TokenKind::Slash, ValueKind::Integer, ValueKind::Integer, [](auto left, auto right) { return left.int_value / right.int_value; } },
	{ TokenKind::And, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value && right.bool_value; } },
	{ TokenKind::Or, ValueKind::Boolean, ValueKind::Boolean, [](auto left, auto right) { return left.bool_value || right.bool_value; } },
};

int GetBinaryOperatorPrecedence(TokenKind kind);
std::optional<BinaryOperator> GetBinaryOperator(TokenKind op, ValueKind left, ValueKind right);
