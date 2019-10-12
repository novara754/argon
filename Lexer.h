#pragma once

#include <cstddef>
#include <string>
#include "Token.h"

class Lexer
{
	std::string _source;
	std::size_t _pos;
public:
	explicit Lexer(std::string source);
	Token NextToken();
private:
	char CurrentChar() const;
	void SkipWhitespace();
	Token Number();
};
