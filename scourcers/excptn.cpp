#include "../headers/excptn.h"
#include <exception>


const char *Exception::what() const noexcept {
    return this->_msg.c_str();
}


const char *Exception::stack_trace() const noexcept {
    return this->_stack_trace.c_str();
}


void Exception::record_stack_info() {

}

