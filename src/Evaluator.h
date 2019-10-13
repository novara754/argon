#pragma once

#include <memory>
#include "Node.h"
#include "Value.h"

class Evaluator
{
	std::unique_ptr<Node> &_root;
public:
	explicit Evaluator(std::unique_ptr<Node> &root);
	Value Evaluate();
private:
	Value Evaluate(Node *node);
	Value Evaluate(LiteralNode *node);
	Value Evaluate(BinaryNode *node);
};
