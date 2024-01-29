#pragma once

#include <vector>
#include "rootnode.h"


class BinaryNode : public Node {
public:
    BinaryNode(Node *left, Node *right) : _left(left), _right(right) {};

    ~BinaryNode();

protected:
    Node *const _left;
    Node *const _right;
};


class UnitaryNode : public Node {
public:
    UnitaryNode(Node *child) : _child(child) {};

    ~UnitaryNode();

protected:
    Node *const _child;
};


class MultipleNode : public Node {
public:
    MultipleNode(Node *node) {
        this->append_child(node, true);
    }

    void append_child(Node *node, bool positive) {
        this->_childs.push_back(node);
        this->_positives.push_back(positive);
    }

    ~MultipleNode();

protected:
    std::vector<Node *> _childs;
    std::vector<bool> _positives;
};


