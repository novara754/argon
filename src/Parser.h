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
	std::unique_ptr<Node> ParseSequence();
	std::unique_ptr<Node> ParseExpression();
	std::unique_ptr<Node> ParseTerm(int parent_prec = -1);
	std::unique_ptr<Node> ParsePrimary();
	Token Peek(int offset) const;
	Token Current() const;
	Token Consume();
	Token Expect(TokenKind kind);
	Token Expect(std::vector<TokenKind> kinds);
};
