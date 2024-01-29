#pragma once

#include "rootnode.h"
#include "storage.h"


class NumberNode : public Node {
public:
    NumberNode(double number) : _number(number) {};

    double Calc() const;

private:
    const double _number;
};


class VariableNode : public Node {
public:
    VariableNode(unsigned int id, Storage &storage) : _id(id), _storage(storage) {};

    double Calc() const;

    bool is_lvalue() const;

    void assign(double val);

private:
    const unsigned int _id;
    Storage &_storage;
};