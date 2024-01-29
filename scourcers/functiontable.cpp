#include "../headers/functiontable.h"
#include <cmath>
#include <cassert>
#include <iostream>

struct FunctionMap {
    PtrFunc func_ptr;
    char *func_name;
};


FunctionMap entries[] = {
        {log,   "log"},
        {log10, "log10"},
        {exp,   "exp"},
        {sqrt,  "sqrt"},
        {sin,   "sin"},
        {cos,   "cos"},
        {tan,   "tan"},
        {sinh,  "sinh"},
        {cosh,  "cosh"},
        {tanh,  "tanh"},
        {asin,  "asin"},
        {acos,  "acos"},
        {atan,  "atan"}
};


FunctionTable::FunctionTable(SymbolTable &tb) : _size(sizeof(entries) / sizeof(entries[0])) {
    _p_func_array = new PtrFunc[this->_size];
    this->init(tb);
}


void FunctionTable::init(SymbolTable &tb) {
    std::cout << "Function List:" << std::endl;
    for (unsigned int i = 0; i < this->_size; i++) {
        _p_func_array[i] = entries[i].func_ptr;
        unsigned int j = tb.add(entries[i].func_name);
        assert(i == j);
        std::cout << " * " << entries[i].func_name << std::endl;
    }
}


FunctionTable::~FunctionTable() {
    delete[] _p_func_array;
}