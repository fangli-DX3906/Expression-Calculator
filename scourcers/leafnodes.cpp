#include "../headers/leafnodes.h"
#include <iostream>

double NumberNode::Calc() const {
    return this->_number;
}


double VariableNode::Calc() const {
    double val = 0.0;
    if (this->_storage.is_init(this->_id)) {
        val = this->_storage.get_value(this->_id);
    } else {
        std::cout << "the variable is not initialized." << std::endl;
    }
    return val;
}


bool VariableNode::is_lvalue() const {
    return true;
}


void VariableNode::assign(double val) {
    this->_storage.set_value(this->_id, val);
}
