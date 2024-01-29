#include "../headers/mleafnodes.h"
#include <vector>
#include <iostream>


double SumNode::Calc() const {
    double result = 0.0;
    std::vector<Node *>::const_iterator child_it = this->_childs.begin();
    std::vector<bool>::const_iterator positive_it = this->_positives.begin();

    for (; child_it != this->_childs.end(); ++child_it, ++positive_it) {
        assert(positive_it != this->_positives.end());
        double val = (*child_it)->Calc();
        if (*positive_it) {
            result += val;
        } else {
            result -= val;
        }
    }
    assert(positive_it == this->_positives.end());

    return result;
}


double ProductNode::Calc() const {
    double result = 1.0;
    std::vector<Node *>::const_iterator child_it = this->_childs.begin();
    std::vector<bool>::const_iterator positive_it = this->_positives.begin();

    for (; child_it != this->_childs.end(); ++child_it, ++positive_it) {
        assert(positive_it != this->_positives.end());
        double val = (*child_it)->Calc();
        if (*positive_it) {
            result *= val;
        } else if (val != 0.0) {
            result /= val;
        } else {
            std::cout << "Invalid divisor: zero" << std::endl;
            return HUGE_VAL;
        }
    }
    assert(positive_it == this->_positives.end());

    return result;
}