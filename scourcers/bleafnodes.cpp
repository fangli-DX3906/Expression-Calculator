#include "../headers/bleafnodes.h"
#include<cmath>
#include<iostream>

using namespace std;


double AddNode::Calc() const {
    return this->_left->Calc() + this->_right->Calc();
}


double SubNode::Calc() const {
    return this->_left->Calc() - this->_right->Calc();
}


double MultiplyNode::Calc() const {
    return this->_left->Calc() * this->_right->Calc();
}


double DivideNode::Calc() const {
    double divisor = this->_right->Calc();
    if (divisor != 0.0) {
        return this->_left->Calc() / divisor;
    } else {
        cout << "Error: zero divisor!" << endl;
        return HUGE_VAL;
    }
}


double AssignNode::Calc() const {
    double val = 0.0;
    val = this->_right->Calc();
    this->_left->assign(val);
    return val;
}
