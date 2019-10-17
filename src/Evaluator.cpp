#include <sstream>
#include "Evaluator.h"
#include "Facts.h"

Evaluator::Evaluator()
{}

Value Evaluator::Evaluate(std::unique_ptr<Node> &root)
{
	return Evaluate(root.get());
}

Value Evaluator::Evaluate(Node *node)
{
	switch (node->GetKind())
	{
		case NodeKind::Literal: return Evaluate(static_cast<LiteralNode *>(node));
		case NodeKind::BinaryOperation: return Evaluate(static_cast<BinaryNode *>(node));
		case NodeKind::Sequence: return Evaluate(static_cast<SequenceNode *>(node));
		case NodeKind::Binding: return Evaluate(static_cast<BindingNode *>(node));
		case NodeKind::VariableAccess: return Evaluate(static_cast<VariableAccessNode *>(node));
	}
}

Value Evaluator::Evaluate(LiteralNode *node)
{
	return node->GetValue();
}

Value Evaluator::Evaluate(BinaryNode *node)
{
	auto left = Evaluate(node->GetLeft().get());
	auto right = Evaluate(node->GetRight().get());

	std::optional<BinaryOperator> bin_op = GetBinaryOperator(node->GetOperator().GetKind(), left.kind, right.kind);
	if (bin_op.has_value())
	{
		return bin_op.value().Operate(left, right);
	}
	else
	{
		std::stringstream out;
		out << "TypeError: Unknown operator '" << node->GetOperator().GetRaw() << "' for operands " << left.kind << " and " << right.kind << ".";
		throw std::runtime_error{ out.str() };
	}
}

Value Evaluator::Evaluate(SequenceNode *node)
{
	Value val;
	for (const auto &e : node->GetExpressions())
		val = Evaluate(e.get());
	return val;
}

Value Evaluator::Evaluate(BindingNode *node)
{
	auto itr = _bindings.find(node->GetIdentifier().GetRaw());
	if (itr != _bindings.end())
	{
		std::stringstream out;
		out << "ReferenceError: Variable '" << node->GetIdentifier().GetRaw() << "' has already been bound.";
		throw std::runtime_error{ out.str() };
	}

	auto val = Evaluate(node->GetValue().get());
	_bindings.insert({ node->GetIdentifier().GetRaw(), val });

	return val;
}

Value Evaluator::Evaluate(VariableAccessNode *node)
{
	auto itr = _bindings.find(node->GetIdentifier().GetRaw());
	if (itr == _bindings.end())
	{
		std::stringstream out;
		out << "ReferenceError: Variable '" << node->GetIdentifier().GetRaw() << "' is unbound.";
		throw std::runtime_error{ out.str() };
	}
	return itr->second;
}
