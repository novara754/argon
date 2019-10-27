#include "Facts.h"

int GetBinaryOperatorPrecedence(TokenKind kind)
{
	auto itr = std::find(std::begin(PrecedenceOrder), std::end(PrecedenceOrder), kind);
	if (itr == std::end(PrecedenceOrder))
		return -1;
	else
		return std::distance(PrecedenceOrder, itr);
}

std::optional<BinaryOperator> GetBinaryOperator(TokenKind op, ValueKind left, ValueKind right)
{
	auto itr = std::find_if(std::begin(BinaryOperators), std::end(BinaryOperators), [op, left, right](const BinaryOperator &bin_op)
	{
		return bin_op.op == op && bin_op.left == left && bin_op.right == right;
	});

	return itr != std::end(BinaryOperators) ? *itr : std::optional<BinaryOperator>();
}

bool CharacterIsNumber(char c) {
	return std::isdigit(c)
		|| c == '_';
}

bool CharacterIsIdentifier(char c) {
	return std::isalpha(c)
		|| c == '_';
}
