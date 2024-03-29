#include <sstream>
#include "Node.h"
#include "Util.h"

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
	return _literal.GetValue();
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

SequenceNode::SequenceNode(std::vector<std::unique_ptr<Node>> expressions)
	: _expressions(std::move(expressions))
{}

NodeKind SequenceNode::GetKind() const
{
	return NodeKind::Sequence;
}

std::string SequenceNode::AsStr() const
{
	std::stringstream ss;
	ss << "(Sequence";
	for (const auto &e : _expressions)
		ss << " " << e->AsStr();
	ss << ")";
	return ss.str();
}

const std::vector<std::unique_ptr<Node>> &SequenceNode::GetExpressions() const
{
	return _expressions;
}

BindingNode::BindingNode(Token identifier, std::unique_ptr<Node> value)
	: _identifier(identifier),
	_value(std::move(value))
{}

NodeKind BindingNode::GetKind() const
{
	return NodeKind::Binding;
}

std::string BindingNode::AsStr() const
{
	std::stringstream ss;
	ss << "(Binding '" << _identifier.GetRaw() << "' " << _value->AsStr() << ")";
	return ss.str();
}

const Token &BindingNode::GetIdentifier() const
{
	return _identifier;
}

const std::unique_ptr<Node> &BindingNode::GetValue() const
{
	return _value;
}

VariableAccessNode::VariableAccessNode(Token identifier)
	: _identifier(identifier)
{}

NodeKind VariableAccessNode::GetKind() const
{
	return NodeKind::VariableAccess;
}

std::string VariableAccessNode::AsStr() const
{
	std::stringstream ss;
	ss << "(VariableAccess '" << _identifier.GetRaw() << "')";
	return ss.str();
}

const Token &VariableAccessNode::GetIdentifier() const
{
	return _identifier;
}

UnnamedFunctionNode::UnnamedFunctionNode(std::unique_ptr<Node> body)
	: _body(std::move(body))
{}

NodeKind UnnamedFunctionNode::GetKind() const
{
	return NodeKind::UnnamedFunction;
}

std::string UnnamedFunctionNode::AsStr() const
{
	std::stringstream ss;
	ss << "(UnnamedFunctionNode " << _body->AsStr() << ")";
	return ss.str();
}

const std::unique_ptr<Node> &UnnamedFunctionNode::GetBody() const
{
	return _body;
}

Value UnnamedFunctionNode::GetValue() const
{
	return Value(_body.get());
}

FunctionCallNode::FunctionCallNode(std::unique_ptr<Node> fun)
	: _fun(std::move(fun))
{}

NodeKind FunctionCallNode::GetKind() const
{
	return NodeKind::FunctionCall;
}

std::string FunctionCallNode::AsStr() const
{
	std::stringstream ss;
	ss << "(FunctionCallNode " << _fun->AsStr() << ")";
	return ss.str();
}

const std::unique_ptr<Node> &FunctionCallNode::GetFun() const
{
	return _fun;
}
