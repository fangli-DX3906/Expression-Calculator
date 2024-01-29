#pragma once

#include "subnodes.h"


class SumNode : public MultipleNode {
public:
    SumNode(Node *node) : MultipleNode(node) {};

    double Calc() const;
};


class ProductNode : public MultipleNode {
public:
    ProductNode(Node *node) : MultipleNode(node) {};

    double Calc() const;
};