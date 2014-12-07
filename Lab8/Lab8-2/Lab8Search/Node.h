/*
 PROGRAM NAME: Program 8: External Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 17, 2014
 
 DUE DATE:     November 18, 2014
 
 PROGRAM PURPOSE:
 Declaration of the Node Class
 
 
 VARIABLE DICTIONARY: in functions
 
 ADTs: none
 
 FILES USED: none
 
 SAMPLE INPUTS: none
 
 SAMPLE OUTPUTS: none
 
 
 ---------------------------------------------------------------------*/

#ifndef __p7__Node__
#define __p7__Node__

#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


class Node{
    
public:
    Node();
    Node(int k, int o);
    int getKey();
    int getOffset();
    Node* getNext();
    void setNext(Node* next);
    
private:
    int key;
    int offset;
    Node* next;
    void setKey(int n);
    void setOffset(int o);
    
};

#endif /* defined(__p7__Node__) */
