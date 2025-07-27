#include <iostream>
#include "PizzaShop.h"
#include "greet.h"
#include<string>
#include<list>
#include <map>
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

//Polymorphism
// Definition: Polymorphism allows objects of different derived classes
// to be treated as objects of a common base class,
// enabling dynamic behavior.

class Animal {
public:
    void eat() { std::cout << "This animal eats food." << std::endl; }
    // Declared using the virtual keyword in the base class.

    // Definition: Virtual methods are member functions in a base class
    //  that can be overridden in derived classes.
    //  They enable run-time polymorphism.

    virtual void sound() { std::cout << "Animal makes a sound." << std::endl; }
    //Allows the derived class to provide its own implementation.
    // The function to be called is determined at runtime using a virtual table (vtable).
};

class Dog : public Animal { // Dog inherits from Animal
public:
    void bark() { std::cout << "The dog barks." << std::endl; }
    void sound() override { std::cout << "Dog barks." << std::endl; }
};

class Cat : public Animal {
public:
    void sound() override { std::cout << "Cat meows." << std::endl; }
};


// Virtual Methods
class Base {
public:
    virtual void show() { std::cout << "Base class method." << std::endl; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class method." << std::endl; }
};

//  在 C++ 中，->
//  是成员访问运算符，用于通过指针访问对象的成员。
// 它的作用是简化对指针指向的对象成员的访问。

// 访问类或结构体的成员： 如果有一个指针指向一个对象，
//  可以使用 -> 来访问该对象的成员，
// 而不是先解引用指针再使用 . 运算符。



class Point_ {
public:
    int x, y;

    Point_ (int x, int y) : x(x), y(y) {}

    void display() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};



// Definition: An abstract class in C++ is a class that cannot be instantiated
// and is designed to be a base class for other classes. It contains at least one pure virtual function.
class Shape {
public:

    // Virtual Destructors
    virtual void draw() const = 0; // Pure virtual function
    // 避免资源泄漏的方法1
    virtual ~Shape()  { cout << "Shape Destructor" << endl; }        // Virtual destructor
    // the destructor of the derived class is called first,
    //followed by the base class destructor.

};


class Circle : public Shape {
public:
    void draw() const override { cout << "Drawing Circle" << endl; }

    // 避免资源泄漏的方法2
    ~Circle() { cout << "Circle Destructor" << endl; }
};


// Inheritance and Copy/Move
//
// Inheritance: Allows a derived class to inherit members and behavior from a base class.

// Copy Constructor: Creates a copy of an object. Must be explicitly defined for deep copies.

// Move Constructor: Transfers ownership of resources from one object to another,
// avoiding deep copies.

class Base_Variant {
public:
    int* data;
    // Base_Variant(int value): 普通构造函数，用于动态分配内存并初始化 data。

    // 使用 成员初始化列表
    // 动态分配内存并将值赋给 data
    Base_Variant(int value) : data(new int(value)) {}


    Base_Variant(const Base_Variant& other) {
        data = new int(*other.data); // 分配新内存，并将 other.data 指向的值复制到新内存中。
    } // Copy constructor
    // 深拷贝避免了多个对象共享同一块内存，防止潜在的内存管理问题。


    // A shallow copy creates a new object, but it does not recursively copy the objects that
    // the original object references. Instead, it copies references to those objects.
    // This means that changes to mutable objects inside the original will also affect the shallow copy.

    // Base_Variant&&：右值引用，表示可以安全地“窃取”资源。
    // data(other.data)：将 other 的资源转移到当前对象。
    // noexcept：声明此函数不会抛出异常，优化性能。
    // 声明此函数不会抛出异常，优化性能。
    Base_Variant(Base_Variant&& other) noexcept : data(other.data)
    { other.data = nullptr; } // Move constructor
    // other.data = nullptr：将 other 的指针置空，防止析构时重复释放内存。
    // 用于移动语义，转移资源的所有权。

    ~Base_Variant() { delete data; }
    // delete data：释放 data 指向的内存。


};


// Inheritance: Allows a derived class to inherit members and behavior from a base class.
// Copy Constructor: Creates a copy of an object. Must be explicitly defined for deep copies.
// Move Constructor: Transfers ownership of resources from one object to another, avoiding deep copies.


// Iterator Design Pattern
// Purpose: Provides a way to sequentially access elements
// in a collection without exposing its internal structure.
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class VectorIterator : public Iterator {
    vector<int>& data;
    size_t index = 0;

public:
    VectorIterator(vector<int>& vec) : data(vec) {}

    bool hasNext() override { return index < data.size(); }
    int next() override { return data[index++]; }
};


// Observer Design Pattern
// Purpose: Establishes a one-to-many dependency where changes in one object
// notify all dependent objects.

class Observer {
public:
    virtual void update(int value) = 0;
};

class Subject {
    vector<Observer*> observers;
    int state;

public:
    void attach(Observer* obs) { observers.push_back(obs); }
    void setState(int value) { state = value; notify(); }
    void notify() { for (Observer* obs : observers) obs->update(state); }
};
class ConcreteObserver : public Observer {
    string name;

public:
    ConcreteObserver(string n) : name(n) {}
    void update(int value) override { cout << name << " received: " << value << endl; }
};


// Decorator Design Pattern
// Purpose: Dynamically adds new behavior to objects by wrapping them in decorator classes.
// Example:
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component() = default;
};

class ConcreteComponent : public Component {
public:
    void operation() override { cout << "ConcreteComponent operation" << endl; }
};

class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* comp) : component(comp) {}
    void operation() override { component->operation(); }
};

class ConcreteDecorator : public Decorator {
public:
    ConcreteDecorator(Component* comp) : Decorator(comp) {}
    void operation() override {
        Decorator::operation();
        cout << "ConcreteDecorator additional behavior" << endl;
    }
};

int divide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero");
    return a / b;
}

class Product {
public:
    virtual void use() = 0;
    virtual ~Product() = default;
};

class ConcreteProductA : public Product {
public:
    void use() override { cout << "Using Product A" << endl; }
};

class ConcreteProductB : public Product {
public:
    void use() override { cout << "Using Product B" << endl; }
};

class Factory {
public:
    virtual Product* createProduct() = 0;
};

class FactoryA : public Factory {
public:
    Product* createProduct() override { return new ConcreteProductA(); }
};

class FactoryB : public Factory {
public:
    Product* createProduct() override { return new ConcreteProductB(); }
};

// Template Method Design Pattern
// Purpose: Defines the skeleton of an algorithm in a base class,
// allowing subclasses to override specific steps.


class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
    }
    virtual void step1() = 0;
    virtual void step2() = 0;
};

class ConcreteClass : public AbstractClass {
public:
    void step1() override { cout << "Step 1" << endl; }
    void step2() override { cout << "Step 2" << endl; }
};


// Non-Virtual Interface (NVI) Idiom
// Purpose: Enforces a consistent interface by making public
// methods non-virtual and delegating to private virtual methods.

class Base_M {
public:
    void interface() { implementation(); }
private:
    virtual void implementation() = 0;
};

class Derived_M : public Base_M {
private:
    void implementation() override { cout << "Derived implementation" << endl; }
};



#include <fstream>

class FileHandler {
    ifstream file;

public:
    FileHandler(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("Failed to open file");
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

    void readFile() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
};


int main() {

    try {
        FileHandler fh("example.txt");
        fh.readFile();
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    // Purpose: A C++ associative container that stores key-value pairs in sorted order.
    // new data structure :
    // std::map
    // Purpose: A C++ associative container that stores key-value pairs in sorted order.
    map<string, int> scores;
    scores["Alice"] = 90;
    scores["Bob"] = 85;

    for (const auto& [key, value] : scores) {
        cout << key << ": " << value << endl;
    }


    Derived_M obj;
    obj.interface();



    Factory* factory = new FactoryA();
    Product* product = factory->createProduct();
    product->use();
    delete product;
    delete factory;


    // Exceptions
    // Purpose: Handle runtime errors or unexpected conditions in a controlled manner.
    try {
        cout << divide(10, 0) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }


    // Factory Method Design Pattern
    // Purpose: Defines an interface for creating objects
    // but lets subclasses decide which class to instantiate.



    // Decorator Design Pattern
    Component* component = new ConcreteComponent();
    Component* decorated = new ConcreteDecorator(component);
    decorated->operation();
    delete decorated;
    delete component;


    // observer design pattern
    Subject subject;
    ConcreteObserver obs1("Observer1"), obs2("Observer2");
    subject.attach(&obs1);
    subject.attach(&obs2);
    subject.setState(10);

    // iterator design pattern
    vector<int> numbers = {1, 2, 3};
    VectorIterator it(numbers);
    while (it.hasNext()) cout << it.next() << " " <<endl;

    Base_Variant obj1_variant(10);

    Base_Variant obj2_variant = obj1_variant; // Copy constructor

    Base_Variant obj3_variant = move(obj1_variant); // Move constructor

    cout << *obj2_variant.data << endl; // Output: 10
    cout << (obj1_variant.data == nullptr) << endl; // Output: 1 (true)


    // Abstract Classes
    // Definition: An abstract class in C++ is a class
    // that cannot be instantiated and is designed
    // to be a base class for other classes. It contains at least one pure virtual function.
    Shape* shape = new Circle();
    shape->draw(); // Output: Drawing Circle
    // Purpose: Enforces derived classes to implement specific behavior.
    delete shape;
    // 他会先删除circle，然后才是shape


    // Virtual Destructors


    // 为什么是 Point_* ptr = &p; 而不是 直接 Point_* ptr = p;
    // 在 C++ 中，Point_* ptr = &p; 是正确的，
    // 因为 ptr 是一个指向 Point_ 对象的指针，而 &p 是 p 的地址。以下是详细解释：
    Point_ p_num(10, 20);      // 创建一个对象
    Point_* ptr_num = &p_num;      // 创建一个指向对象的指针

    //
    // ptr is a pointer to a Point_ object
    // .
    // &p
    // gives the memory address of the object p
    // .
    // This assigns the address of p to the pointer p

    // 使用 -> 访问成员
    ptr_num->x = 30;          // 修改 x 的值
    ptr_num->y = 40;          // 修改 y 的值
    ptr_num->display();       // 调用成员函数



    Base* basePtr;
    Derived derivedObj;
    basePtr = &derivedObj;
    basePtr->show(); // Output: Derived class method.


    Animal* animal;
    Cat cat;

    // Inheritance
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Defined in Dog

    // 俗称变态 -》 变换形态。。。
    animal = &dog;
    animal->sound(); // Output: Dog barks.

    // 俗称变态。。。
    animal = &cat;
    animal->sound(); // Output: Cat meows.


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
