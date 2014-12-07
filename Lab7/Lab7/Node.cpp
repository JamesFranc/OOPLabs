/*
 PROGRAM NAME: Program 7: Hashing (Seperate Chaining)
 
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
    setSize(0);
    setWord("");
}

Node::Node(int n, string str, string line)
: next(NULL)
{
    //---------------------------
    // Initializing Constructor
    //---------------------------
    setSize(n);
    setWord(str);
    setLine(line);
}

//--------------
//Begin Setters
//--------------
void Node::setSize(int n){
    size = n;
}

void Node::setWord(string str){
    word = str;
}

void Node::setNext(Node* nextNode){
    next = nextNode;
}

void Node::setLine(string line){
    lines=(line+" ");
}
void Node::addLine(string line){
    lines+=(line+" ");
}


//--------------
//Begin Getters
//--------------
int Node::getSize(){
    return size;
}

string Node::getWord(){
    return word;
}
Node* Node::getNext(){
    return next;
}
string Node::getLines(){
    return lines;
}



