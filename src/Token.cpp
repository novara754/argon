#include <ostream>
#include "Token.h"

Token::Token(TokenKind kind, std::size_t pos, std::string raw)
	: _kind(kind),
	_pos(pos),
	_raw(raw)
{}

Token::Token(const Token &token)
	: _kind(token._kind),
	_pos(token._pos),
	_raw(token._raw)
{}

TokenKind Token::GetKind() const
{
	return _kind;
}

std::size_t Token::GetPos() const
{
	return _pos;
}

std::string Token::GetRaw() const
{
	return _raw;
}

std::ostream &operator<<(std::ostream &out, const TokenKind &kind)
{
#define KIND_TO_STR(kind) case TokenKind::##kind: kind_str = #kind; break
	std::string kind_str;
	switch (kind)
	{
		KIND_TO_STR(Plus);
		KIND_TO_STR(Minus);
		KIND_TO_STR(Star);
		KIND_TO_STR(Slash);
		KIND_TO_STR(OParen);
		KIND_TO_STR(CParen);
		KIND_TO_STR(Period);
		KIND_TO_STR(Comma);
		KIND_TO_STR(Number);
		KIND_TO_STR(Identifier);
		KIND_TO_STR(True);
		KIND_TO_STR(False);
		KIND_TO_STR(And);
		KIND_TO_STR(Or);
		KIND_TO_STR(EndOfFile);
		KIND_TO_STR(Error);
	}
	return out << kind_str;
#undef KIND_TO_STR
}

std::ostream &operator<<(std::ostream & out, const Token & token)
{
	return out << "Token(kind=" << token.GetKind() << ", pos=" << token.GetPos() << ", raw=\"" << token.GetRaw() << "\")";
}
