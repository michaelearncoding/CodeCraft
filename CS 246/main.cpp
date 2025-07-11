#include <iostream>
#include "PizzaShop.h"
#include "greet.h"
using namespace std;


const double PI = 3.14159;

struct Point {
    int x;
    int y;
};
//
// class Point {
//
//     public:
//         int x, y;
//
//         Point(int x = 0, int y = 0) : x(x), y(y) {}
//
//         // Overload the + operator
//         Point operator+(const Point& other) const {
//             return Point(x + other.x, y + other.y);
//         }
//
//         void print() const {
//             cout << "(" << x << ", " << y << ")" << endl;
//         }
// };

int getValue() {
    int x = 10;
    return x; // Returns a copy of x
}

int& getReference(int& x) {
    return x; // Returns a reference to x
}

void getValue(int& result) {
    result = 10; // Modifies the passed parameter
}

void increment(int x ) {
    x++;
}

void increment_passed_by_x (int &x) {
    x++;
}

void increment_passed_by_pointer (int *x) {
    (*x)++;
}


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


    // Point p1(10, 20);
    // Point p2(5, 15);
    // Point p3 = p1 + p2; // Uses the overloaded + operator
    // p3.print();         // Output: (15, 35)


    int a = 10;
    int &ref = a; // ref is a reference to a
    ref = 20;     // Modifies a directly
    std::cout << a; // Output: 20


    int *ptr = new int;  // Dynamically allocate memory for an integer
    *ptr = 42;           // Assign a value
    std::cout << *ptr;   // Output: 42
    delete ptr;          // Free the allocated memory

    // ptr holds the address of the allocated memory.
    // *ptr accesses or modifies the value at that memory address.

    int num = 5; // Variable declaration and initialization
    increment(num);
    std::cout << num << std::endl; // Output the value of num

    increment_passed_by_x(num); // value will be changed
    std::cout << num << std::endl; // Output the value of num

    num = 10;
    increment_passed_by_pointer(&num);
    std::cout << num; // Output: 6 (original value changed)

    std::cout << "Value of PI: " << PI << std::endl; // Constants
    // Constants are immutable, so we cannot change PI

    // Structs
    // A struct is a user-defined data type that allows grouping of variables
    Point p = {10, 20};
    std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl;

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
