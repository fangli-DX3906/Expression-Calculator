#include "../headers/parser.h"
#include "../headers/subnodes.h"
#include "../headers/leafnodes.h"
#include "../headers/uleafnodes.h"
#include "../headers/mleafnodes.h"
#include "../headers/bleafnodes.h"
#include "../headers/excptn.h"
#include <string>

using namespace std;


Parser::Parser(Scanner &scanner, Calc &calc)
        : _scanner(scanner), _root(0), _status(STATUS_OK), _calc(calc) {};


STAUTS Parser::parse() {
    this->_root = this->experssion();
    if (!this->_scanner.is_done()) {
        this->_status = STATUS_ERROR;
    }
    return this->_status;
};


double Parser::calculate() const {
    assert(this->_root != 0);
    return this->_root->Calc();
}


// experssion can be:
//     term1 +- term2 +- ... +- termn
// or:
//     term(variable2) = expression
Node *Parser::experssion() {
    Node *node = this->term();
    EToken current_token = this->_scanner.get_token();
    if (current_token == TOKE_PLUS || current_token == TOKEN_MINUS) {
        MultipleNode *multiple_node = new SumNode(node);
        do {
            this->_scanner.tokenize_pos_char_and_move();
            Node *next_node = this->term();
            multiple_node->append_child(next_node, current_token == TOKE_PLUS);
            current_token = this->_scanner.get_token();
        } while (current_token == TOKE_PLUS || current_token == TOKEN_MINUS);
        node = multiple_node;
    } else if (current_token == TOKEN_ASSIGN) {
        this->_scanner.tokenize_pos_char_and_move();
        Node *node_right = this->experssion();
        if (node->is_lvalue()) {
            node = new AssignNode(node, node_right);
        } else {
            this->_status = STATUS_ERROR;
            throw SyntaxError("LHS of assignment should be a variable.");
        }
    }
    return node;
}


// term: factor1 */ factor */ ... */ factorm
Node *Parser::term() {
    Node *node = this->factor();
    EToken current_token = this->_scanner.get_token();
    if (current_token == TOKEN_MULTIPLY || current_token == TOKEN_DIVIDE) {
        MultipleNode *multiple_node = new ProductNode(node);
        do {
            this->_scanner.tokenize_pos_char_and_move();
            Node *next_node = this->factor();
            multiple_node->append_child(next_node, current_token == TOKEN_MULTIPLY);
            current_token = this->_scanner.get_token();
        } while (current_token == TOKEN_MULTIPLY || current_token == TOKEN_DIVIDE);
        node = multiple_node;
    }
    return node;
}


// factor: number; or identifier; or -factor; or (experssion)
Node *Parser::factor() {
    Node *node;
    EToken current_token = this->_scanner.get_token();
    if (current_token == TOKEN_LPARENTHESIS) {
        this->_scanner.tokenize_pos_char_and_move();
        node = this->experssion();
        if (this->_scanner.get_token() == TOKEN_RPARENTHESIS) {
            this->_scanner.tokenize_pos_char_and_move();
        } else {
            this->_status = STATUS_ERROR;
            throw SyntaxError("Invalid expression: missing ).");
            node = 0;
        }
    } else if (current_token == TOKEN_NUMBER) {
        node = new NumberNode(this->_scanner.get_number());   // number leaf, next
        this->_scanner.tokenize_pos_char_and_move();
    } else if (current_token == TOKEN_IDENTIFIER) {
        std::string symbol = this->_scanner.get_symbol();
        unsigned int id = this->_calc.find_symbol(symbol);
        this->_scanner.tokenize_pos_char_and_move();
        if (this->_scanner.get_token() == TOKEN_LPARENTHESIS) {
            this->_scanner.tokenize_pos_char_and_move();
            node = this->experssion();
            if (this->_scanner.get_token() == TOKEN_RPARENTHESIS) {
                this->_scanner.tokenize_pos_char_and_move();
                if (id != SymbolTable::NOTFOUND && this->_calc.is_function(id)) {
                    node = new FunctionNode(node, this->_calc.get_function_ptr(id));
                } else {
                    this->_status = STATUS_ERROR;
                    string buf = "Unknown function: " + symbol + '.';
                    throw SyntaxError(buf.c_str());
                }
            } else {
                this->_status = STATUS_ERROR;
                throw SyntaxError("Invalid expression: missing ')' in a function call.");
            }
        } else {
            if (id == SymbolTable::NOTFOUND) {
                id = this->_calc.add_symbol(symbol);
            }
            node = new VariableNode(id, this->_calc.get_storage());
        }
    } else if (current_token == TOKEN_MINUS) {
        this->_scanner.tokenize_pos_char_and_move();
        node = new UMinusNode(this->factor());
    } else {
        this->_status = STATUS_ERROR;
        throw SyntaxError("Invalid expression.");
        node = 0;
    }
    return node;
}