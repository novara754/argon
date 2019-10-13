#include <sstream>
#include "Node.h"

LiteralNode::LiteralNode(Token literal)
	: _literal(literal)
{}

NodeKind LiteralNode::GetKind() const
{
	return NodeKind::Literal;
}

std::string LiteralNode::AsStr() const
{
	std::stringstream ss;
	ss << "(LiteralNode " << _literal.GetRaw() << ")";
	return ss.str();
}

const Token &LiteralNode::GetToken() const
{
	return _literal;
}

Value LiteralNode::GetValue() const
{
	switch (_literal.GetKind())
	{
		case TokenKind::Number:
		{
			int value = std::stoi(_literal.GetRaw());
			return { value };
		}
		case TokenKind::True:
		case TokenKind::False:
		{
			return { _literal.GetKind() == TokenKind::True };
		}
	}
}

BinaryNode::BinaryNode(std::unique_ptr<Node> left, std::unique_ptr<Node> right, const Token op)
	: _left(std::move(left)),
	_right(std::move(right)),
	_op(op)
{}

NodeKind BinaryNode::GetKind() const
{
	return NodeKind::BinaryOperation;
}

std::string BinaryNode::AsStr() const
{
	std::stringstream ss;
	ss << "(BinaryNode " << _op.GetRaw() << " " << _left->AsStr() << " " << _right->AsStr() << ")";
	return ss.str();
}

const std::unique_ptr<Node> &BinaryNode::GetLeft() const
{
	return _left;
}

const std::unique_ptr<Node> &BinaryNode::GetRight() const
{
	return _right;
}

const Token &BinaryNode::GetOperator() const
{
	return _op;
}
