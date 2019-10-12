#pragma once

#include <vector>
#include <cstddef>
#include <memory>
#include "Token.h"
#include "Node.h"

class Parser
{
	std::vector<Token> _tokens;
	std::size_t _pos;
public:
	explicit Parser(std::string &source);
	std::unique_ptr<Node> Parse();
private:
	std::unique_ptr<Node> ParseExpression();
	std::unique_ptr<Node> ParseTerm();
	std::unique_ptr<Node> ParsePrimary();
	Token Current() const;
	Token Consume();
	Token Expect(TokenKind kind);
};
