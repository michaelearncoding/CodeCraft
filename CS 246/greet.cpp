# include <iostream>
#include "greet.h"
using namespace std;

// void greet(std::string name) {
// This ensures the default argument is only defined in the header file (greet.h), resolving the redefinition error.

void greet(std::string name) {
    cout << "Hello, " << name << "!" << endl;
}