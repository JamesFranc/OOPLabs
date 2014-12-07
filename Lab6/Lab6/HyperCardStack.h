/*
 PROGRAM NAME: HyperCardStack.h
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 1, 2014
 
 DUE DATE:     November 6, 2014
 
 PROGRAM PURPOSE:
 Declaration for the HyperCardStack class. Also includes a declaration 
 for a Node struct to be used by calling code. As a way to move through
 the list.
 
 VARIABLE DICTIONARY:
 
 ADTs: none
 
 FILES USED: 

 
 
 ---------------------------------------------------------------------*/

#ifndef __p6__HyperCardStack__
#define __p6__HyperCardStack__

#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Card.h"

using namespace std;

struct Node{
    Card data;
    Node* next;
};

class HyperCardStack{
public:
    HyperCardStack();
    void insert(int, string);
    void remove(int);
    void traverse();
    void forward();
    void home();
    void print();
    
private:
    int count;
    void emptyInsert(Card);
    void stdInsert(Card);
    void printPointers();
    Node *Current;
    Node *Tail;
};




#endif /* defined(__p6__HyperCardStack__) */
