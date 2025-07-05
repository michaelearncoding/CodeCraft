//
// Created by Qingda Mai on 6/29/25.
//

/** @file PizzaShop.cpp
 * @brief Implementation of the PizzaShop class.
 * 
 * This file contains the implementation of the PizzaShop class, which manages 
 * pizza orders, points accumulation, and pizza redemption.
*/

#include "PizzaShop.h"
#include <iostream>

/**
 * @brief Default constructor for the PizzaShop class.
 * 
 * Initializes the points to zero.
 */
PizzaShop::PizzaShop() : points(0) {}

/**
 * @brief Orders pizzas and updates points.
 * 
 * This function allows the user to order a specified number of pizzas. 
 * Each pizza ordered adds 10 points to the user's total. If the order is 
 * illegal (less than 1 or more than 10 pizzas), an error message is displayed.
 * 
 * @param n Number of pizzas to order (must be between 1 and 10).
 */
void PizzaShop::orderPizza(int n) {
    if (n < 1 || n > 10) {
        std::cout << "Illegal order." << std::endl;
    } else {
        points += n * 10;
        std::cout << n << " pizzas ordered. Total points: " << points << std::endl;
    }
}

/**
 * @brief Redeems points for a free pizza.
 * 
 * If the user has at least 50 points, they can redeem a free pizza. 
 * Otherwise, an error message is displayed indicating insufficient points.
 */

void PizzaShop::redeemPizza() {
    if (points >= 50) {
        points -= 50;
        std::cout << "Free Pizza!" << std::endl;
    } else {
        std::cout << "No pizza for you! Points: " << points << std::endl;
    }
}

/**
 * @brief Prints the current points.
 * 
 * Displays the user's current points total.
 */
void PizzaShop::printPoints() const {
    std::cout << "Current points: " << points << std::endl;
}