#pragma once

#include <memory>
#include <map>
#include "Node.h"
#include "Value.h"

class Evaluator
{
	std::map<std::string, Value> _bindings;
public:
	explicit Evaluator();
	Value Evaluate(std::unique_ptr<Node> &root);
private:
	Value Evaluate(Node *node);
	Value Evaluate(LiteralNode *node);
	Value Evaluate(BinaryNode *node);
	Value Evaluate(SequenceNode *node);
	Value Evaluate(BindingNode *node);
	Value Evaluate(VariableAccessNode *node);
};
