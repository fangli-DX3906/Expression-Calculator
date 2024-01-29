#include "../headers/uleafnodes.h"


double UMinusNode::Calc() const {
    return -this->_child->Calc();
}


double FunctionNode::Calc() const {
    return (*this->_p_func)(this->_child->Calc());
}