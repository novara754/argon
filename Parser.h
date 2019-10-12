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
	std::vector<std::string> _diagnostics;
public:
	explicit Parser(std::string &source);
	std::unique_ptr<Node> Parse();
	const std::vector<std::string> &GetDiagnostics() const;
private:
	std::unique_ptr<Node> ParseExpression();
	std::unique_ptr<Node> ParseTerm();
	std::unique_ptr<Node> ParsePrimary();
	Token Current() const;
	Token Consume();
	Token Expect(TokenKind kind);
};
