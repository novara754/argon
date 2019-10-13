#include "Evaluator.h"

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
	switch (node->GetOperator().GetKind())
	{
		case TokenKind::Plus: return { left.int_value + right.int_value };
		case TokenKind::Minus: return { left.int_value - right.int_value };
		case TokenKind::Star: return { left.int_value * right.int_value };
		case TokenKind::Slash: return { left.int_value / right.int_value };
	}
}
