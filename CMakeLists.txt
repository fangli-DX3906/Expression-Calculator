cmake_minimum_required(VERSION 3.23)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator main.cpp)
add_executable(calculator headers/rootnode.h scourcers/bleafnodes.cpp test_calculator.cpp headers/subnodes.h headers/bleafnodes.h scourcers/uleafnodes.cpp headers/uleafnodes.h scourcers/subnodes.cpp headers/scanner.h scourcers/scanner.cpp headers/parser.h scourcers/parser.cpp headers/mleafnodes.h scourcers/mleafnodes.cpp scourcers/symboltable.cpp headers/symboltable.h scourcers/storage.cpp headers/storage.h headers/leafnodes.h scourcers/leafnodes.cpp headers/calc.h scourcers/calc.cpp scourcers/functiontable.cpp headers/functiontable.h scourcers/excptn.cpp headers/excptn.h)
