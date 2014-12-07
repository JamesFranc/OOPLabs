/*
 PROGRAM NAME: Program 8: External Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 17, 2014
 
 DUE DATE:     November 18, 2014
 
 PROGRAM PURPOSE:
 Definition of the Node Class
 
 
 VARIABLE DICTIONARY: in functions
 
 ADTs: none
 
 FILES USED: none
 
 SAMPLE INPUTS: none
 
 SAMPLE OUTPUTS: none
 
 
 ---------------------------------------------------------------------*/

#include "Node.h"

Node::Node()
: next(NULL) {
    //---------------------------
    // Default Constructor
    //---------------------------
    setKey(0);
    setOffset(0);
}

Node::Node(int k, int o)
: next(NULL)
{
    //---------------------------
    // Initializing Constructor
    //---------------------------
    setKey(k);
    setOffset(o);
}

//--------------
//Begin Setters
//--------------
void Node::setKey(int k){
    key = k;
}

void Node::setOffset(int o){
    offset = o;
}

void Node::setNext(Node* nextNode){
    next = nextNode;
}



//--------------
//Begin Getters
//--------------
int Node::getKey(){
    return key;
}

int Node::getOffset(){
    return offset;
}

Node* Node::getNext(){
    return next;
}




