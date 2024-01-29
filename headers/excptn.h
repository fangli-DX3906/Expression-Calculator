#pragma once

#include <iostream>
#include <string>


class Exception : public std::exception {
public:
    explicit Exception(const char *msg) : _msg(msg), _stack_trace(msg) {
        record_stack_info();
    };

    virtual ~Exception() noexcept {};

    virtual const char *what() const noexcept;

    const char *stack_trace() const noexcept;

private:
    void record_stack_info();

    std::string _msg;
    std::string _stack_trace;
};


class SyntaxError : public Exception {
public:
    explicit SyntaxError(const char *msg) : Exception(msg) {};

    virtual ~SyntaxError() noexcept {};
};

