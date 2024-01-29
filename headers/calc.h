#pragma once

// 定义对象不能使用前向声明，需要包涵头文件；引用则可以前向声明
#include "storage.h"
#include "symboltable.h"
#include "functiontable.h"


class Parser;


class Calc {
    friend class Parser;

public:
    Calc() : _functable(_symtable), _storage(_symtable) {};

private:
    Storage &get_storage() {
        return _storage;
    }

    unsigned int find_symbol(const std::string &str) const;

    unsigned int add_symbol(const std::string &str);

    // 函数个数固定，所以超过固定个数就一定是变量，否则是函数
    bool is_function(unsigned int id) const {
        return id < this->_functable.get_size();
    }

    PtrFunc get_function_ptr(unsigned int id) const {
        return this->_functable.get_function_ptr(id);
    }

    // 不是用引用是为了不在外部构造
    SymbolTable _symtable;
    FunctionTable _functable;
    Storage _storage;
};