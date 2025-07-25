#include <iostream>
#include "PizzaShop.h"
#include "greet.h"
#include<string>
#include<list>
using namespace std;



const double PI = 3.14159;

// create a struct for the operator constructor reloading

struct PerfectBFGF {
    string Name;
    int outlooking;

    PerfectBFGF(string name, int outlooking) {
        this->Name = name;
        this->outlooking = outlooking;
    }

    bool operator==( const PerfectBFGF & girl) const{
        return this->Name == girl.Name;
    }

};


struct Girls {
    list<PerfectBFGF> myGirls;
    // this operator is defined as a member function, so it can be used within the class
    void operator+=(PerfectBFGF& people) {
        this->myGirls.push_back(people);
    }

    void operator-=(PerfectBFGF& people) {
        this->myGirls.remove(people);
    }

};




// this operator is defined as a global function, so it can be used outside the class
// pass the original object by reference - save potential memory and performance issues
// it's better return some value, so that the front needs to indicate!
ostream& operator<<(ostream& COUT, const PerfectBFGF& bfgf) {
    COUT  << "Name: " << bfgf.Name << endl;
     COUT <<   ", Outlooking: " << bfgf.outlooking << endl;
    return COUT;
}


// fix: must put the operatorr << for PerfectBFGF  is defclared before the operator << for girls
// The compiler needs to know how to handle PerfectBFGF objects before it encounters them in the Girls implementation.

ostream& operator<<(ostream& COUT, Girls& myGirls) {
    for (PerfectBFGF Sexy : myGirls.myGirls )
        COUT << Sexy << endl;
    return COUT;
}


struct Point {
    int x;
    int y;
};

// for showing the Initializing Objects
/*
 * Definition: Assigning initial values to an object's data members when it is created.
*Ways to Initialize:
Default initialization (no arguments).
Parameterized initialization (with arguments).
Using a Member Initializer List (MIL).
 *
 *
 */
class PointFake {
public:
    int x, y;
    PointFake(int x = 0, int y = 0) : x(x), y(y) {} // MIL - Member Initializer List (MIL).
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



// Overload operator<< for PointFake
ostream& operator<<(ostream& COUT, const PointFake& point) {
    COUT << "PointFake(" << point.x << ", " << point.y << ")";
    return COUT;
}


// 定义：拷贝构造函数用于创建一个新对象，并将其初始化为现有对象的副本。
class ExampleCopyConstructors {
public:

    int* data;

    ExampleCopyConstructors(int value) {
        data = new int(value);
    }

    ExampleCopyConstructors(const ExampleCopyConstructors& other) {
        data = new int(*other.data);
    } // Deep copy

    ~ExampleCopyConstructors() { delete data; }
};

ExampleCopyConstructors obj1(10);
ExampleCopyConstructors obj2 = obj1; // Calls copy constructor


class PointX{
public:
    int x, y;

    PointX(int x = 0, int y = 0) : x(x), y(y) {}

    // Overload + operator
    PointX operator+(const PointX& other) const {
        return PointX(x + other.x, y + other.y);
    }

    // Overload == operator
    bool operator==(const PointX& other) const {
        return x == other.x && y == other.y;
    }
};




// Member Operators
class MOEPoint {
public:
    int x, y;
    MOEPoint(int x = 0, int y = 0) : x(x), y(y) {}
    MOEPoint operator+(const MOEPoint& other) const {
        return MOEPoint(x + other.x, y + other.y);
    }
};



// Arrays of Objects
// Member operators are overloaded operators defined as member functions of a class.

class AddPoint {
public:
    int x, y;
    AddPoint(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

// Static with OOP
// static members belong to the class,
// not individual objects, and are shared across all instances.
class Counter {
public:
    static int count; // Shared across all objects
    Counter() { count++; }
};
int Counter::count = 0; // Define static member
// In C++, static members of a class are shared across all instances of the class
// and belong to the class itself, not to any specific object.
// However, they must be defined outside the class to allocate memory for them.


// Constant Objects
class ConstPoint {
public:
    int x, y;
    ConstPoint(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() const { return x; } // Const member function
    int getY() const { return y; } // Const member function
};



class BankAccount {
private:
    double balance; // Encapsulated data

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
    }

    double getBalance() const { return balance; } // Controlled access
};


//2. Composition
// Definition: A "has-a" relationship where one class contains another class
// as a part of its implementation.
// The contained object is strongly dependent on the container.
// Key Point: If the container is destroyed, the contained object is also destroyed.
class Engine {
public:
    void start() { std::cout << "Engine started" << std::endl; }
};

class Car {
private:
    Engine engine; // Composition
public:
    void start() { engine.start(); }
};



//3. Aggregation
// Key Point: If the container is destroyed, the contained object can still exist.

class Engine2 {
public:
    void start() { std::cout << "Engine started" << std::endl; }
};

class Car2 {
private:
    Engine2* engine; // Aggregation (pointer to an external Engine object)
public:
    Car2(Engine2* eng) : engine(eng) {}
    void start() { engine->start(); }
};


// 4. Inheritance
class Vehicle {
public:
    void move() { std::cout << "Vehicle is moving" << std::endl; }
};

class Car3 : public Vehicle { // Inheritance
public:
    void honk() { std::cout << "Car is honking" << std::endl; }
};


int main() {


    const ConstPoint pp(10, 20);
    // p.x = 30; // Error: Cannot modify a const object
    std::cout << pp.getX()<<endl; // Allowed


    //  Arrays of Objects
    // Arrays can store multiple objects of a class.
    AddPoint addpoint[3] = {AddPoint(1, 2), AddPoint(3, 4), AddPoint(5, 6)};


    PointX p1x(10, 20), p2x(5, 15);
    PointX p3x = p1x+ p2x; // Uses the overloaded + operator
    std::cout << "Point p3: (" << p3x.x << ", " << p3x.y << ")" << std::endl; // Output: (15, 35)


    PointFake p1;         // Default initialization
    PointFake p2(10, 20); // Parameterized initialization
    std::cout << p1 <<endl; // Output:PointFake(0, 0)

// below example is showing how to use the operator overloading in C++

    //create a perfect boy friend or girl friend using the class PerfectBFGF
    //make sure we can generate the result with the operator <<
    // add the operator << for the class PerfectBFGF
    // fcreate another class called Girls
    // defined the operator +=
    // so that the class variable myGirls can be used to store the PerfectBFGF objects

    PerfectBFGF gf1 = PerfectBFGF("Chloe", 25);
    PerfectBFGF gf2 = PerfectBFGF("Cao YuXin", 23);

    Girls myGirls ;
    myGirls += gf1;  // This will call the overloaded += operator to add gf1 to myGirls
    // the above Girls myGirls will be diretly ref by the " operator+=  " with the key wrod "this"
    myGirls += gf2;
    myGirls -= gf2;
    cout << myGirls;



    // cout << gf1;

    // cin.get();
    cout << gf2 << gf1;


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
