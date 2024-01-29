#pragma once
#include <cassert>


//class Noncopyable {
//protected:
//    Noncopyable() {};
//
//    ~Noncopyable() {};
//
//private:
//    Noncopyable(const Noncopyable &);
//
//    const Noncopyable &operator=(const Noncopyable &);
//};


//class Node: private Noncopyable {
class Node {
public:
    virtual double Calc() const = 0;

    virtual bool is_lvalue() const {
        return false;
    }

    virtual void assign(double val) {
        assert(!"incorrectly called assign().");
    }

    virtual ~Node() {};
};