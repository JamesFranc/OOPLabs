//
//  Item.h
//  p4
//
//  Created by James Francis II on 10/9/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

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
    Item(int stockNum, string description, int qty, int nextItem);
    int getStockNum() const;
    string getDescription() const;
    int getCount() const;
    int getNext() const;
    
private:
    int stockNum;
    char description[8];
    int count;
    int next;
    void setStockNum(int n);
    void setDescription(string str);
    void setCount(int n);
    void setNext(int n);
};


#endif /* defined(__p4__item__) */
