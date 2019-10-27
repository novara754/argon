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

int GetBinaryOperatorPrecedence(TokenKind kind);
std::optional<BinaryOperator> GetBinaryOperator(TokenKind op, ValueKind left, ValueKind right);

bool CharacterIsNumber(char c);
bool CharacterIsIdentifier(char c);
