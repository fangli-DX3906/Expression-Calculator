#include "../headers/scanner.h"
#include <cmath>


Scanner::Scanner(const std::string &buf) : _buf(buf), _pos(0), _token(TOEKN_INIT), _number(0) {
    this->tokenize_pos_char_and_move();
    this->_is_empty = (this->_token == TOKEN_END);
}


double Scanner::get_number() const {
    return this->_number;
}


EToken Scanner::get_token() const {
    return this->_token;
}


// move until the char on next position is not a blank space
void Scanner::skip_blank() {
    while (isspace(this->_buf[this->_pos])) {
        ++this->_pos;
    }
}


std::string Scanner::get_symbol() const {
    return this->_symbol;
}


bool Scanner::is_empty() const {
    return this->_is_empty;
}


bool Scanner::is_done() const {
    return this->_token == TOKEN_END;
}


void Scanner::tokenize_pos_char_and_move() {
    this->skip_blank();
    char cur_char = this->_buf[this->_pos];
    switch (cur_char) {
        case '+':
            this->_token = TOKE_PLUS;
            ++this->_pos;
            break;
        case '-':
            this->_token = TOKEN_MINUS;
            ++this->_pos;
            break;
        case '*':
            this->_token = TOKEN_MULTIPLY;
            ++this->_pos;
            break;
        case '/':
            this->_token = TOKEN_DIVIDE;
            ++this->_pos;
            break;
        case '=':
            this->_token = TOKEN_ASSIGN;
            ++this->_pos;
            break;
        case '(':
            this->_token = TOKEN_LPARENTHESIS;
            ++this->_pos;
            break;
        case ')':
            this->_token = TOKEN_RPARENTHESIS;
            ++this->_pos;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            this->_token = TOKEN_NUMBER;
            char *p;
            this->_number = strtod(&this->_buf[this->_pos], &p);
            this->_pos = p - &this->_buf[0];
            break;
        case '\0':
        case '\n':
        case '\r':
        case EOF:
            this->_token = TOKEN_END;
            break;
        default:
            if (isalpha(cur_char) || cur_char == '_') {
                this->_token = TOKEN_IDENTIFIER;
                this->_symbol.erase();
                char ch = this->_buf[this->_pos];
                do {
                    this->_symbol += ch;
                    ++this->_pos;
                    ch = this->_buf[this->_pos];
                } while (isalnum(ch) || ch == '_');
            } else {
                this->_token = TOKEN_ERROR;
            }
            break;
    }
}