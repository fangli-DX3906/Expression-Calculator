#include "../headers/subnodes.h"


BinaryNode::~BinaryNode() {
    delete this->_left;
    delete this->_right;
}


UnitaryNode::~UnitaryNode() {
    delete this->_child;
}


MultipleNode::~MultipleNode() {
    std::vector<Node *>::const_iterator it;
    for (it = this->_childs.begin(); it != this->_childs.end(); it++) {
        delete *it;
    }
}
