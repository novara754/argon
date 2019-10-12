#include <cctype>
#include "Lexer.h"

Lexer::Lexer(std::string source)
	: _source(source),
	_pos(0)
{}

Token Lexer::NextToken()
{
	if (_pos >= _source.length())
		return Token(TokenKind::EndOfFile, _pos, "\0");

	if (std::isspace(CurrentChar()))
		SkipWhitespace();

	if (std::isdigit(CurrentChar()))
		return Number();

	switch (CurrentChar())
	{
		case '+': return Token(TokenKind::Plus, _pos++, "+");
		case '-': return Token(TokenKind::Minus, _pos++, "-");
		case '*': return Token(TokenKind::Star, _pos++, "*");
		case '/': return Token(TokenKind::Slash, _pos++, "/");
		case '(': return Token(TokenKind::OParen, _pos++, "(");
		case ')': return Token(TokenKind::CParen, _pos++, ")");
		case '.': return Token(TokenKind::Period, _pos++, ".");
	}

	char c = CurrentChar();
	return Token(TokenKind::Error, _pos++, std::string(1, c));
}

char Lexer::CurrentChar() const
{
	return _pos >= _source.length() ? '\0' : _source.at(_pos);
}

void Lexer::SkipWhitespace()
{
	while (std::isspace(CurrentChar()))
		_pos++;
}

Token Lexer::Number()
{
	auto start = _pos;
	while (std::isdigit(CurrentChar()))
		_pos++;
	auto end = _pos;

	auto raw = _source.substr(start, end - start);
	return Token(TokenKind::Number, start, raw);
}