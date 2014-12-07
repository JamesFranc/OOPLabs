/*
 PROGRAM NAME: p2.h
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: September 19, 2014
 
 DUE DATE:     September 23, 2014
 
 PROGRAM PURPOSE:
 header file used to define the p2 class and include all the libraries to be used in the class.
 
 VARIABLE DICTIONARY:
 int start1: value representing the first line of the first input file to be appended to the output file
 int end1: value representing the last line of the first input file to be appended to the output file
 int start2: value representing the first line of the second input file to be appended to the output file
 int end2: value representing the first line of the second input file to be appended to the output file
 
 ADTs: None
 
 FILES USED: None
 
 SAMPLE INPUTS: None
 
 SAMPLE OUTPUTS: None
 ---------------------------------------------------------------------*/


#ifndef p2_p2_h
#define p2_p2_h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;
class p2{
    
public:
    
p2(string , string);
void parseInput1(string);
void parseInput2(string);
void mergeFile(ifstream& ,ofstream& ,int ,int );
const int getStart1();
const int getEnd1();
const int getStart2();
const int getEnd2();
int areLinesValid(int, int);
int isRangeValid();


private:
    
int start1;
int end1;
int start2;
int end2;
void setStart1(int);
void setEnd1(int);
void setStart2(int);
void setEnd2(int);
};
#endif
