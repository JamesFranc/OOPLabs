/*
 PROGRAM NAME: Program 8: Exetrnal Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 17, 2014
 
 DUE DATE:     November 18, 2014
 
 PROGRAM PURPOSE:
 Declaration of the HashTable Class

 
 VARIABLE DICTIONARY: in functions
 
 ADTs: none
 
 FILES USED: none
 
 SAMPLE INPUTS: none
 
 SAMPLE OUTPUTS: none
 
 
 ---------------------------------------------------------------------*/

#ifndef p7_HashTable_h
#define p7_HashTable_h

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

#include "Node.h"


using namespace std;


class HashTable{
public:
    HashTable();
    void populate(fstream& infile, int n);
    void hashingReport();
    void insert(Node* newNode);
    Node* table[5];
    void printTable(int n);
    int search(int n);
    void createBinaryIndex(int numRecords);
private:
    
    int hashValue(int n);
    string NumberToString(int t);

};

#endif
