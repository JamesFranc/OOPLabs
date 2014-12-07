//--------------------------------------------------------------
//
//  Item.h
//  p4
//
//--------------------------------------------------------------


#ifndef __p4__item__
#define __p4__item__

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Item{
public:
    Item();
    Item(int stockNum, string description, int qty, double cost);
    int getStockNum() const;
    string getDescription() const;
    int getCount() const;
    double getCost() const;
    
private:
    int stockNum;
    char description[8];
    int count;
    double cost;
    void setStockNum(int n);
    void setDescription(string str);
    void setCount(int n);
    void setCost(double n);
};


#endif /* defined(__p4__item__) */
