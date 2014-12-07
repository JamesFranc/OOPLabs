/*
 PROGRAM NAME: Card.h
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 1, 2014
 
 DUE DATE:     November 6, 2014
 
 PROGRAM PURPOSE:
 Declaration of the Card Class
 
 VARIABLE DICTIONARY:
 
 
 ADTs: none
 
 FILES USED:
 
 
 SAMPLE INPUTS:
 
 SAMPLE OUTPUTS:

 
 
 ---------------------------------------------------------------------*/

#ifndef __p6__Card__
#define __p6__Card__

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Card{

public:
    Card();
    Card(int, string);
    int getKey();
    string getEntry();
    void display();
    
private:
    void setKey(int);
    void setEntry(string);
    int Key;
    string Entry;
    
};

#endif /* defined(__p6__Card__) */
