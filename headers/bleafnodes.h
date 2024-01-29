#pragma once

#include "subnodes.h"
#include <cassert>


class AddNode : public BinaryNode {
public:
    AddNode(Node *left, Node *right) : BinaryNode(left, right) {};

    double Calc() const;
};


class SubNode : public BinaryNode {
public:
    SubNode(Node *left, Node *right) : BinaryNode(left, right) {};

    double Calc() const;
};


class MultiplyNode : public BinaryNode {
public:
    MultiplyNode(Node *left, Node *right) : BinaryNode(left, right) {};

    double Calc() const;
};


class DivideNode : public BinaryNode {
public:
    DivideNode(Node *left, Node *right) : BinaryNode(left, right) {};

    double Calc() const;
};


class AssignNode : public BinaryNode {
public:
    AssignNode(Node *left, Node *right) : BinaryNode(left, right) {
        assert(this->_left->is_lvalue());
    };

    double Calc() const;
};