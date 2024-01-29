#include "../headers/symboltable.h"
#include "../headers/excptn.h"

unsigned int SymbolTable::add(const std::string &str) {
    this->_dict[str] = this->_cur_id;
    return _cur_id++;    // index is always 1 less than the number of elements
};


unsigned int SymbolTable::find(const std::string &str) const {
    std::map<const std::string, unsigned int>::const_iterator it;
    it = this->_dict.find(str);
    if (it != this->_dict.end()) {
        return it->second;
    }
    return NOTFOUND;
};


void SymbolTable::clear() {
    this->_dict.clear();
    this->_cur_id = 0;
};


// functor: 本质上重载了括号运算符
class IsEqual {
public:
    IsEqual(unsigned int id) : id(id) {};

    bool operator()(const std::pair<const std::string, unsigned int> &it) const {
        return it.second == this->id;
    };
private:
    unsigned int id;
};


std::string SymbolTable::get_symbol_name(unsigned int id) const {
    std::map<const std::string, unsigned int>::const_iterator it;
    it = std::find_if(this->_dict.begin(), this->_dict.end(), IsEqual(id));
    if (it == this->_dict.end()) {
        throw Exception("Internal error: entry does not exist.");
    }
    return (*it).first;
};