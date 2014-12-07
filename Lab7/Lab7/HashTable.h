/*
 PROGRAM NAME: Program 7: Hashing (Seperate Chaining)
 
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
    void populate(fstream& infile);
    void hashingReport();
    
private:
    
    int success;
    int failed;
    int successCount;
    int failedCount;
    
    int hashValue(string str);
    void printTable(Node* table[]);
    string NumberToString(int t);
    void insert(Node* newNode, int index, Node* table[], int count);
    bool scanChain(Node* current, string word);
    void search(string line, Node* table[]);
    int getSuccess();
    int getFailed();
    void setSuccess(int n);
    void setFailed(int n);
};

#endif
