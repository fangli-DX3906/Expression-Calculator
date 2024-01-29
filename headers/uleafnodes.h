#pragma once

#include "subnodes.h"
#include "functiontable.h"


class UMinusNode : public UnitaryNode {
public:
    UMinusNode(Node *node) : UnitaryNode(node) {};

    double Calc() const;
};


class FunctionNode : public UnitaryNode {
public:
    FunctionNode(Node *child, PtrFunc p_func) : UnitaryNode(child), _p_func(p_func) {};

    double Calc() const;

private:
    PtrFunc _p_func;
};