#pragma once

#include <string>
#include <cstddef>

enum class TokenKind
{
	Plus,
	Minus,
	Star,
	Slash,
	OParen,
	CParen,
	Period,
	Comma,
	LeftArrow,
	Number,
	Identifier,
	True,
	False,
	And,
	Or,
	LessThan,
	LessThanEqual,
	GreaterThan,
	GreaterThanEqual,
	EqualEqual,
	BangEqual,
	EndOfFile,
	Error,
};

class Token
{
	TokenKind _kind;
	std::size_t _pos;
	std::string _raw;
public:
	explicit Token(TokenKind kind, std::size_t pos, std::string raw);
	Token(const Token &token);
	TokenKind GetKind() const;
	std::size_t GetPos() const;
	std::string GetRaw() const;
};

std::ostream &operator<<(std::ostream &out, const TokenKind &kind);
std::ostream &operator<<(std::ostream &out, const Token &token);
