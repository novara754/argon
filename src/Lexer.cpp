#include <cctype>
#include <map>
#include "Lexer.h"

const std::map<std::string, TokenKind> ReservedKeywords = {
	{ "true", TokenKind::True },
	{ "false", TokenKind::False },
	{ "and", TokenKind::And },
	{ "or", TokenKind::Or },
};

Lexer::Lexer(std::string &source)
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

	if (std::isalpha(CurrentChar()))
		return Identifier();

	switch (CurrentChar())
	{
		case '+': return Token(TokenKind::Plus, _pos++, "+");
		case '-': return Token(TokenKind::Minus, _pos++, "-");
		case '*': return Token(TokenKind::Star, _pos++, "*");
		case '/': return Token(TokenKind::Slash, _pos++, "/");
		case '(': return Token(TokenKind::OParen, _pos++, "(");
		case ')': return Token(TokenKind::CParen, _pos++, ")");
		case '.': return Token(TokenKind::Period, _pos++, ".");
		case '<':
		{
			if (Peek() == '=')
			{
				_pos += 2;
				return Token(TokenKind::LessThanEqual, _pos - 2, "<=");
			}
			else
			{
				return Token(TokenKind::LessThan, _pos++, "<");
			}
		}
		case '>':
		{
			if (Peek() == '=')
			{
				_pos += 2;
				return Token(TokenKind::GreaterThanEqual, _pos - 2, ">=");
			}
			else
			{
				return Token(TokenKind::GreaterThan, _pos++, ">");
			}
		}
		case '=':
		{
			if (Peek() == '=')
			{
				_pos += 2;
				return Token(TokenKind::EqualEqual, _pos - 2, "==");
			}
			break;
		}
		case '!':
		{
			if (Peek() == '=')
			{
				_pos += 2;
				return Token(TokenKind::BangEqual, _pos - 2, "!=");
			}
			break;
		}
	}

	char c = CurrentChar();
	_diagnostics.push_back("Unrecognized token '" + std::string(1, c) + "'.");
	return Token(TokenKind::Error, _pos++, std::string(1, c));
}

const std::vector<std::string> &Lexer::GetDiagnostics() const
{
	return _diagnostics;
}

char Lexer::CurrentChar() const
{
	return _pos >= _source.length() ? '\0' : _source.at(_pos);
}

char Lexer::Peek() const
{
	return (_pos + 1) >= _source.length() ? '\0' : _source.at(_pos + 1);
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

Token Lexer::Identifier()
{
	auto start = _pos;
	while (std::isalpha(CurrentChar()) || CurrentChar() == '_' || CurrentChar() == '-')
		_pos++;
	auto end = _pos;

	auto raw = _source.substr(start, end - start);
	auto itr = ReservedKeywords.find(raw);
	return Token(itr != ReservedKeywords.end() ? itr->second : TokenKind::Identifier, _pos, raw);
}
