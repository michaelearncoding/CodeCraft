#include <iostream>
#include "PizzaShop.h"
#include "greet.h"
using namespace std;


/**
 * @file main.cpp
 * @brief Main function to demonstrate the PizzaShop class and other functionalities.
 *
 * This file contains the main function which demonstrates the usage of the PizzaShop class,
 * as well as a simple greeting function.
 */


// method1 : defined in the main file and call it under the main(){} , and it can have a default argument
// void greet(string name = "Guest") {
//     cout << "Hello, " << name << "!" << endl;
// }

// method2 : add the header file & cpp file
// The default argument is only defined in the header file (greet.h), resolving the redefinition error.



int main() {
    greet(); // method 1

    // PizzaShop shop;

    // shop.orderPizza(5);
    // shop.printPoints();
    // shop.redeemPizza();
    // shop.printPoints();



    // // I/O (Input/Output)
    // int number;
    // std::cout << "Enter a number:";
    // std::cin >> number;
    // // Error Handling, the order matters
    // if (std::cin.fail()) {
    //     std::cerr << "Error: Invalid input. Please enter a valid number." << std::endl;
    //     return 1;
    // }
    // std::cout << "You entered: " << number << std::endl;
    // std::cout << "Hello, World!" << std::endl;



    return 0;
}
