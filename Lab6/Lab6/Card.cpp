/*
 PROGRAM NAME: Card.cpp
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 1, 2014
 
 DUE DATE:     November 6, 2014
 
 PROGRAM PURPOSE:
 This file contains the class definition for the Card Class.
 
 VARIABLE DICTIONARY:
 
 
 ADTs: none
 
 FILES USED: none
 
 
 SAMPLE INPUTS(from prog6.dat):

 
 SAMPLE OUTPUTS:(to console)

 
 
 ---------------------------------------------------------------------*/

#include "Card.h"
Card::Card(){
    //--------------------
    //DEFAULT CONSTRUCTOR
    //--------------------
    setKey(0);
    setEntry("");
}

Card::Card(int n, string str){
    //------------------------
    //INITIALIZING CONSTRUCTOR
    //------------------------
    setKey(n);
    setEntry(str);
}


void Card::display(){
    //-------------------------
    // DISPLAYS THE CARD'S FACT
    //-------------------------

    
    printf("%s ", Entry.c_str());


}

//--------------------
//   GETTERS
//--------------------
int Card::getKey(){
    return Key;
}
string Card::getEntry(){
    return Entry;
}

//--------------------
//   SETTERS
//--------------------
void Card::setKey(int n){
    Key = n;
}
void Card::setEntry(string str){
    Entry = str.c_str();
}
