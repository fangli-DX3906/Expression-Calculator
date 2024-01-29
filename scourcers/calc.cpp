#include "../headers/calc.h"


unsigned int Calc::find_symbol(const std::string &str) const {
    return this->_symtable.find(str);
}


unsigned int Calc::add_symbol(const std::string &str) {
    return this->_symtable.add(str);
}