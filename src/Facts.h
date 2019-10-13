#pragma once

#include <algorithm>
#include "Token.h"

const TokenKind PrecedenceOrder[] = {
	TokenKind::Plus,
	TokenKind::Minus,
	TokenKind::Star,
	TokenKind::Slash,
};

int GetBinaryOperatorPrecedence(TokenKind kind)
{
	auto itr = std::find(std::begin(PrecedenceOrder), std::end(PrecedenceOrder), kind);
	if (itr == std::end(PrecedenceOrder))
		return -1;
	else
		return std::distance(PrecedenceOrder, itr);
}
