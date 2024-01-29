#include <iostream>
#include <string>
#include "headers/scanner.h"
#include "headers/parser.h"
#include "headers/calc.h"
#include "headers/excptn.h"

using namespace std;


int test() {
    Calc calc;
    STAUTS status = STATUS_OK;
    do {
        cout << "> ";
        string buf;
        getline(cin, buf);
        Scanner scanner(buf);
        if (!scanner.is_empty()) {
            Parser parser(scanner, calc);
            try {
                status = parser.parse();
                if (status == STATUS_OK) {
                    cout << parser.calculate() << endl;
                }
            } catch (SyntaxError &se) {
                cout << se.what() << endl;
            } catch (Exception &e) {
                cout << e.what() << endl;
            } catch (...) {
                cout << "Internal error" << endl;
            }
        } else {
            cout << "Expression is empty." << endl;
        }
    } while (status != STATUS_QUIT);
    return 0;
}


int main() {
    test();
    cout << "no mistakes" << endl;
    return 0;
}
