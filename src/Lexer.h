#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "Token.h"

class Lexer
{
	std::string &_source;
	std::size_t _pos;
	std::vector<std::string> _diagnostics;
public:
	explicit Lexer(std::string &source);
	Token NextToken();
	const std::vector<std::string> &GetDiagnostics() const;
private:
	char CurrentChar() const;
	void SkipWhitespace();
	Token Number();
	Token Identifier();
};
