#include <sstream>
#include "Parser.h"
#include "Lexer.h"
#include "Facts.h"

Parser::Parser(std::string &source)
	: _pos(0)
{
	Lexer lexer(source);
	while (true)
	{
		auto token = lexer.NextToken();
		if (token.GetKind() == TokenKind::Error)
			continue;
		_tokens.push_back(token);
		if (token.GetKind() == TokenKind::EndOfFile)
			break;
	}
	_diagnostics.insert(_diagnostics.end(), lexer.GetDiagnostics().begin(), lexer.GetDiagnostics().end());
}

std::unique_ptr<Node> Parser::Parse()
{
	auto expr = ParseExpression();
	auto eof = Expect(TokenKind::EndOfFile);
	return expr;
}

const std::vector<std::string> &Parser::GetDiagnostics() const
{
	return _diagnostics;
}

std::unique_ptr<Node> Parser::ParseExpression()
{
	auto term = ParseTerm();
	auto period = Expect(TokenKind::Period);
	return term;
}

std::unique_ptr<Node> Parser::ParseTerm(int parent_prec)
{
	auto left = ParsePrimary();
	while (true)
	{
		auto prec = GetBinaryOperatorPrecedence(Current().GetKind());
		if (prec == 0 || prec <= parent_prec)
			break;
		auto op = Consume();
		auto right = ParseTerm(prec);
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
	
	std::stringstream out;
	out << "Unexpected token '" << Current().GetKind() << "' where token '" << kind << "' was expected.";
	_diagnostics.push_back(out.str());
	return Token(kind, Current().GetPos(), "");
}