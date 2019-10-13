#include "Evaluator.h"
#include "Facts.h"

Evaluator::Evaluator(std::unique_ptr<Node> &root)
	: _root(root)
{}

Value Evaluator::Evaluate()
{
	return Evaluate(_root.get());
}

Value Evaluator::Evaluate(Node *node)
{
	switch (node->GetKind())
	{
		case NodeKind::Literal: return Evaluate((LiteralNode *)node);
		case NodeKind::BinaryOperation: return Evaluate((BinaryNode *)node);
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
		throw std::exception{"TypeError: invalid types for binary operator"};
	}
}
