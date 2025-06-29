//
// Created by Qingda Mai on 6/29/25.
//

#ifndef PIZZASHOP_H
#define PIZZASHOP_H



class PizzaShop {

private:
        int points;
public:
        PizzaShop(); //Constructor
        void orderPizza(int n);
        void redeemPizza();
        void printPoints() const; //return type  +

};



#endif //PIZZASHOP_H
