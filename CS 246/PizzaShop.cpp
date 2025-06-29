//
// Created by Qingda Mai on 6/29/25.
//

#include "PizzaShop.h"
#include <iostream>

PizzaShop::PizzaShop() : points(0) {}

void PizzaShop::orderPizza(int n) {
    if (n < 1 || n > 10) {
        std::cout << "Illegal order." << std::endl;
    } else {
        points += n * 10;
        std::cout << n << " pizzas ordered. Total points: " << points << std::endl;
    }
}

void PizzaShop::redeemPizza() {
    if (points >= 50) {
        points -= 50;
        std::cout << "Free Pizza!" << std::endl;
    } else {
        std::cout << "No pizza for you! Points: " << points << std::endl;
    }
}

void PizzaShop::printPoints() const {
    std::cout << "Current points: " << points << std::endl;
}