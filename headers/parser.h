#pragma once

#include <string>
#include "rootnode.h"
#include "scanner.h"
#include "calc.h"


enum STAUTS {
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT
};


class Parser {
public:
    Parser(Scanner &scanner, Calc &calc);

    STAUTS parse();

    double calculate() const;

    Node *experssion();

    Node *term();

    Node *factor();

private:
    Scanner &_scanner;
    Node *_root;
    STAUTS _status;
    Calc &_calc;
};