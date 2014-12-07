

//--------------------------------------------------------------
//
//  Item.cpp
//  p4
//
//--------------------------------------------------------------


#include "Item.h"

Item::Item(){
    //--------------------------------------------------------------
    // Default Item Constructor
    //--------------------------------------------------------------
    
    setStockNum(0);
    setDescription("");
    setCount(0);
    setCost(0);
}

Item::Item(int stock, string desc, int qty, double c){
    //---------------------------------------------------------------------
    //Preconditions: 3 integers and a string are passed to the constructor
    //               from the calling code
    //Postconditions: an Item object is instantiated with the passed values
    //
    //Variables used: stock - integger representing an item's stock number
    //                 desc - description of an item, in a string
    //                  qty - integer value with the current quantity
    //             nextItem - next item in the stock list
    //---------------------------------------------------------------------
    
    setStockNum(stock);
    setDescription(desc);
    setCount(qty);
    setCost(c);
}

//---------------------------------------------------------------------
//BEGIN GETTERS AND SETTERS
//---------------------------------------------------------------------

int Item::getStockNum()const{
    return stockNum;
}

string Item::getDescription()const{
    return description;
}

int Item::getCount()const{
    return count;
}

double Item::getCost()const{
    return cost;
}

void Item::setStockNum(int stock){
    stockNum = stock;
}

void Item::setDescription(string desc){
    for (int i = 0; i<8;i++){
        description[i]=desc[i];
    }
    
}

void Item::setCount(int qty){
    count = qty;
}

void Item::setCost(double c){
    cost = c;
}

//---------------------------------------------------------------------
//END GETTERS AND SETTERS
//---------------------------------------------------------------------
