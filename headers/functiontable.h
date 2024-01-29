#pragma once

#include "symboltable.h"


typedef double (*PtrFunc)(double);


class FunctionTable {
public:
    FunctionTable(SymbolTable &tb);

    ~FunctionTable();

    unsigned int get_size() const {
        return this->_size;
    }

    PtrFunc get_function_ptr(unsigned int id) const {
        return _p_func_array[id];
    }

    void init(SymbolTable &tb);

private:
    // 数组元素均为(函数)指针，数组首地址赋给_p_funcs
    PtrFunc *_p_func_array;
    unsigned int _size;
};


