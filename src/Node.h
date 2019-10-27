#pragma once

#include <memory>
#include <ostream>
#include <vector>
#include "Token.h"
#include "Value.h"

enum class NodeKind
{
	Literal,
	BinaryOperation,
	Sequence,
	Binding,
	VariableAccess,
	UnnamedFunction,
	FunctionCall,
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
	Value GetValue() const;
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

class SequenceNode : public Node
{
	std::vector<std::unique_ptr<Node>> _expressions;
public:
	explicit SequenceNode(std::vector<std::unique_ptr<Node>> expressions);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const std::vector<std::unique_ptr<Node>> &GetExpressions() const;
};

class BindingNode : public Node
{
	Token _identifier;
	std::unique_ptr<Node> _value;
public:
	explicit BindingNode(Token identifier, std::unique_ptr<Node> value);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const Token &GetIdentifier() const;
	const std::unique_ptr<Node> &GetValue() const;
};

class VariableAccessNode : public Node
{
	Token _identifier;
public:
	explicit VariableAccessNode(Token identifier);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const Token &GetIdentifier() const;
};

class UnnamedFunctionNode : public Node
{
	std::unique_ptr<Node> _body;
public:
	explicit UnnamedFunctionNode(std::unique_ptr<Node> body);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const std::unique_ptr<Node> &GetBody() const;
	Value GetValue() const;
};

class FunctionCallNode : public Node
{
	std::unique_ptr<Node> _fun;
public:
	explicit FunctionCallNode(std::unique_ptr<Node> fun);
	NodeKind GetKind() const;
	std::string AsStr() const;
	const std::unique_ptr<Node> &GetFun() const;
};
