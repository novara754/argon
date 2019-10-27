#pragma once

#include <string>
#include <cstddef>
#include "Value.h"

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
	Size,
};

class Token
{
	TokenKind _kind;
	std::size_t _pos;
	std::string _raw;
	Value _value;
public:
	explicit Token(TokenKind kind, std::size_t pos, std::string raw);
	explicit Token(TokenKind kind, std::size_t pos, std::string raw, Value value);
	Token(const Token &token);
	TokenKind GetKind() const;
	std::size_t GetPos() const;
	const std::string &GetRaw() const;
	Value GetValue() const;
};

std::ostream &operator<<(std::ostream &out, const TokenKind &kind);
std::ostream &operator<<(std::ostream &out, const Token &token);
