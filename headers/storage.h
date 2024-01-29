#pragma once

#include <vector>
#include "symboltable.h"


class Storage {
public:
    Storage(SymbolTable &tb);    // where symbols of constant are stored

    void clear();

    bool is_init(unsigned int id) const;

    void add_consant(SymbolTable &tb);

    double get_value(unsigned int id) const;

    void set_value(unsigned int id, double val);

    void add_value(unsigned int id, double val);


private:
    std::vector<double> _cells;   // store the value of the constants
    std::vector<bool> _inits;    // store the info if contants are initialized
};



