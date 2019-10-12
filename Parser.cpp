#include "Parser.h"
#include "Lexer.h"

Parser::Parser(std::string &source)
	: _pos(0)
{
	Lexer lexer(source);
	while (true)
	{
		auto token = lexer.NextToken();
		_tokens.push_back(token);
		if (token.GetKind() == TokenKind::EndOfFile)
			break;
	}
}

std::unique_ptr<Node> Parser::Parse()
{
	auto expr = ParseExpression();
	auto eof = Expect(TokenKind::EndOfFile);
	return expr;
}

std::unique_ptr<Node> Parser::ParseExpression()
{
	auto term = ParseTerm();
	auto period = Expect(TokenKind::Period);
	return term;
}

std::unique_ptr<Node> Parser::ParseTerm()
{
	auto left = ParsePrimary();

	if (Current().GetKind() == TokenKind::Plus || Current().GetKind() == TokenKind::Minus)
	{
		auto op = Consume();
		auto right = ParseTerm();
		left = std::make_unique<BinaryNode>(std::move(left), std::move(right), op);
	}
	
	return left;
}

std::unique_ptr<Node> Parser::ParsePrimary()
{
	auto literal = Expect(TokenKind::Number);
	return std::make_unique<LiteralNode>(literal);
}

Token Parser::Current() const
{
	return _pos >= _tokens.size() ? _tokens.back() : _tokens.at(_pos);
}

Token Parser::Consume()
{
	auto token = Current();
	_pos++;
	return token;
}

Token Parser::Expect(TokenKind kind)
{
	if (Current().GetKind() == kind)
		return Consume();

	return Token(kind, Current().GetPos(), "");
}
