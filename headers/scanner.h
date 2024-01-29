#pragma once

#include<string>


enum EToken {
    TOEKN_INIT,
    TOKEN_END,
    TOKEN_ERROR,
    TOKEN_NUMBER,
    TOKE_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPARENTHESIS,
    TOKEN_RPARENTHESIS,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN
};


class Scanner {
public:
    Scanner(const std::string &buf);

    void tokenize_pos_char_and_move();

    double get_number() const;

    EToken get_token() const;

    std::string get_symbol() const;

    bool is_empty() const;

    bool is_done() const;


private:
    void skip_blank();

    const std::string _buf;
    EToken _token;
    double _number;
    unsigned int _pos;
    std::string _symbol;
    bool _is_empty;
};