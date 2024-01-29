#pragma once

#include <map>
#include <string>


class SymbolTable {

public:
    SymbolTable() : _cur_id(0) {};

    unsigned int add(const std::string &str);

    unsigned int find(const std::string &str) const;

    void clear();

    std::string get_symbol_name(unsigned int id) const;

    enum {
        NOTFOUND = 0xffffffff
    };
    
private:
    std::map<const std::string, unsigned int> _dict;
    unsigned int _cur_id;
};


