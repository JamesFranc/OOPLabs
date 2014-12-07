//--------------------------------------------------------------
//
//  Item.cpp
//  p4
//
//-------------------------------------------------------------


#include "Record.h"
Record::Record(){
    //--------------------------------------------------------------
    // Default Item Constructor
    //--------------------------------------------------------------
    
    setKey(0);
    setOffset(0);
}

Record::Record(int key, int offset){
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
    
    setKey(key);
    setOffset(offset);
}

void Record::printDetails(){
    cout << setw(6)<< getKey()<<setw(2)<< getOffset();
    cout<<endl;
    cout.clear();
}

//---------------------------------------------------------------------
//BEGIN GETTERS AND SETTERS
//---------------------------------------------------------------------

int Record::getKey()const{
    return key;
}

int Record::getOffset()const{
    return offset;
}


void Record::setKey(int stock){
    key = stock;
}


void Record::setOffset(int n){
    offset = n;
}

//---------------------------------------------------------------------
//END GETTERS AND SETTERS
//---------------------------------------------------------------------

bool Record::operator< (const Record& r2)const{
    return (key < r2.getKey());
}

bool Record::operator> (const Record& r2)const{
    return (key > r2.getKey());
}

bool Record::operator ==(const Record& r2)const{
    return(key == r2.getKey());
}
