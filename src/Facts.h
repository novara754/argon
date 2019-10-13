#pragma once

#include "Token.h"

int GetBinaryOperatorPrecedence(TokenKind kind)
{
	switch (kind)
	{
		case TokenKind::Star:
		case TokenKind::Slash:
			return 2;
		case TokenKind::Plus:
		case TokenKind::Minus:
			return 1;
		default:
			return 0;
	}
}
