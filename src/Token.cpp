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
#define KIND_TO_STR(kind, name) case kind: kind_str = #name; break
	std::string kind_str;
	switch (kind)
	{
		KIND_TO_STR(TokenKind::Plus, Plus);
		KIND_TO_STR(TokenKind::Minus, Minus);
		KIND_TO_STR(TokenKind::Star, Star);
		KIND_TO_STR(TokenKind::Slash, Slash);
		KIND_TO_STR(TokenKind::OParen, OParen);
		KIND_TO_STR(TokenKind::CParen, CParen);
		KIND_TO_STR(TokenKind::Period, Period);
		KIND_TO_STR(TokenKind::Comma, Comma);
		KIND_TO_STR(TokenKind::LeftArrow, LeftArrow);
		KIND_TO_STR(TokenKind::Number, Number);
		KIND_TO_STR(TokenKind::Identifier, Identifier);
		KIND_TO_STR(TokenKind::True, True);
		KIND_TO_STR(TokenKind::False, False);
		KIND_TO_STR(TokenKind::And, And);
		KIND_TO_STR(TokenKind::Or, Or);
		KIND_TO_STR(TokenKind::EndOfFile, EndOfFile);
		KIND_TO_STR(TokenKind::Error, Error);
	}
	return out << kind_str;
#undef KIND_TO_STR
}

std::ostream &operator<<(std::ostream & out, const Token & token)
{
	return out << "Token(kind=" << token.GetKind() << ", pos=" << token.GetPos() << ", raw=\"" << token.GetRaw() << "\")";
}
