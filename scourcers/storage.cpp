#include "../headers/storage.h"
#include <cmath>
#include <iostream>


Storage::Storage(SymbolTable &tb) {
    this->add_consant(tb);
}


void Storage::clear() {
    this->_cells.clear();
    this->_inits.clear();
}


bool Storage::is_init(unsigned int id) const {
    return id < this->_cells.size() && this->_inits[id];
}


void Storage::add_consant(SymbolTable &tb) {
    std::cout << "Variable List:" << std::endl;
    unsigned int id = tb.add("e");
    this->add_value(id, exp(1.));
    std::cout << " * e = " << exp(1.) << std::endl;

    id = tb.add("pi");
    this->add_value(id, 2.0 * acos(0.0));
    std::cout << " * pi = " << 2.0 * acos(0.0) << std::endl;
}


double Storage::get_value(unsigned int id) const {
    assert(id < this->_cells.size());
    return this->_cells[id];
}


void Storage::set_value(unsigned int id, double val) {
    assert(id <= this->_cells.size());
    if (id < this->_cells.size()) {
        this->_cells[id] = val;
        this->_inits[id] = true;
    } else if (id == this->_cells.size()) {
        this->add_value(id, val);
    }
}


void Storage::add_value(unsigned int id, double val) {
    this->_cells.resize(id + 1);
    this->_inits.resize(id + 1);
    this->_cells[id] = val;
    this->_inits[id] = true;
}