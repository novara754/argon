#pragma once

#include <memory>
#include <ostream>
#include "Token.h"

enum class NodeKind
{
	Literal,
	BinaryOperation,
};

class Node
{
public:
	virtual NodeKind GetKind() const = 0;
	virtual std::string AsStr() const = 0;
};

class LiteralNode : public Node
{
	Token _literal;
public:
	explicit LiteralNode(Token literal);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const Token &GetToken() const;
};

class BinaryNode : public Node
{
	std::unique_ptr<Node> _left;
	std::unique_ptr<Node> _right;
	const Token _op;
public:
	explicit BinaryNode(std::unique_ptr<Node> left, std::unique_ptr<Node> right, const Token op);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const std::unique_ptr<Node> &GetLeft() const;
	const std::unique_ptr<Node> &GetRight() const;
	const Token &GetOperator() const;
};
