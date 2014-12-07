/*
 PROGRAM NAME: Program 2: File Merge
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: September 19, 2014
 
 DUE DATE:     September 23, 2014
 
 PROGRAM PURPOSE:
 
 This class will accept two strings that contain line ranges and use the parseInput1() &
 parseInput2() functions to set the start and end lines for the merge function to use.
 
 VARIABLE DICTIONARY:
 
 int dump: used by the mergeFile() function to iterate through lines not wanted in the output file
 int startMerge: value of first line to be written to the output file
 int endMerge: value of the last line to be written to the output file
 string line: used to hold a line from an input file
 ifstream& infile: reference to an input filestream from the calling code
 ofstream& outfile: reference to an output filestream from the calling code
 string argv: a set of characters that represent the start and end values 
              that will be appended from the input file.
 string delimeter: a dash, that is used to represent lines between the start
                   and end values.
 strong token: used to store a substring of the input
 size_t pos: starting position for the substring
 string startEnd: used to hold the value of argv
 
 ADTs: none
 
 FILES USED: none
 
 
 SAMPLE INPUTS:
 
 
 
 SAMPLE OUTPUTS:
 
 
 ---------------------------------------------------------------------*/



#include "p2.h"

p2::p2(string startEnd1, string startEnd2 ){
    //-----------------------------------------------------------------------------
    // This is the only constructor for the p2 class. This constructor accepts two
    // strings, that contain the start and end values for the 2 files to be merged.
    //-----------------------------------------------------------------------------
    parseInput1(startEnd1);
    parseInput2(startEnd2);
}

void p2::mergeFile(ifstream& infile,ofstream& outfile,int startMerge,int endMerge){
    //-----------------------------------------------------------------------------
    // This method will accept an input filestream, output filestream, beginning
    // index, the line of the input file to start the merge, and the line of the
    // input file to end the merge. It will then append the lines of the input file
    // to the output file. This method is used for both input files passed through
    // at command line.
    //-----------------------------------------------------------------------------

    string line;
    int dump = 1;
    while(dump<startMerge){
        getline(infile,line);
        dump++;
    }
    
    while(startMerge<=endMerge){
        getline(infile,line);
        outfile<<line+"\n";
        startMerge++;
    }
    
    
}

void p2::parseInput1(string argv){
    //-----------------------------------------------------------------------------
    // This function accepts a string, it is assimed the string contains 2 integers
    // delimited by a '-'. This function then tries to set the separated values
    // as the beginning and ending lines for the first file.
    //-----------------------------------------------------------------------------
    string startEnd = argv;
    string delimiter = "-";
    
    size_t pos = 0;
    string token;
    while ((pos = startEnd.find(delimiter)) != string::npos) {
        token = startEnd.substr(0, pos);
        try {
            stringstream ss(token);
            int value;
            ss>>value;
            setStart1(value);
        } catch (int e) {
            cout << "Invalid start value for File1, please try again.\n";
            exit(-7);
        }
        startEnd.erase(0, pos + delimiter.length());
    }
    try {
        stringstream ss(startEnd);
        int value;
        ss>>value;
        setEnd1(value);

    } catch (int e) {
        cout << "Invalid end value for File1, please try again.\n";
        exit(-6);

    }
    
}
void p2::parseInput2(string argv){
    //-----------------------------------------------------------------------------
    // This function accepts a string, it is assimed the string contains 2 integers
    // delimited by a '-'. This function then tries to set the separated values
    // as the beginning and ending lines for the second file.
    //-----------------------------------------------------------------------------
    string startEnd = argv;
    string delimiter = "-";
    
    size_t pos = 0;
    string token;
    while ((pos = startEnd.find(delimiter)) != string::npos) {
        token = startEnd.substr(0, pos);
        try {
            stringstream ss(token);
            int value;
            ss>>value;
            setStart2(value);
        } catch (int e) {
            cout << "Invalid start value for File2, please try again.";
            exit(-5);
        }
        startEnd.erase(0, pos + delimiter.length());
    }
    try {
        stringstream ss(startEnd);
        int value;
        ss>>value;
        setEnd2(value);

    } catch (int e) {
        cout << "Invalid end value for File2, please try again.";
        exit(-4);

    }
    

    
}

int p2::areLinesValid(int n, int m){
    //-----------------------------------------------------------------------------
    // This method accepts integer values from the calling code and compares those
    // with the end values for each of the input files' entered end lines.
    // If either end value entered at command line is greater than the passed
    // integers then the line count for one of the files is exceeded and a 0 is
    // returned to the calling code.
    //-----------------------------------------------------------------------------
    
    if (end1 > n  || end2 > m) {
        return 0;
    }
    else return 1;
}

int p2::isRangeValid(){
    //-----------------------------------------------------------------------------
    // This method compares the proposed start and end lines for both files.
    // if either of the start values exceed their respective end values then a 0 is
    // returned to the calling code.
    //-----------------------------------------------------------------------------
    
    if (start1 > end1  || start2 > end2) {
        return 0;
    }
    else return 1;

}


//-----------------------------------------------------------------------------
// Setters and Getters follow
//-----------------------------------------------------------------------------
void p2::setStart1(int n){
    if (n>0) {
        start1 = n;
    }
}

void p2::setEnd1(int n){
    if (n>0) {
        end1 = n;
    }
}

void p2::setStart2(int n){
    if (n>0) {
        start2 = n;
    }
}

void p2::setEnd2(int n){
    if (n>0) {
        end2 = n;
    }
}


const int p2::getStart1(){
    return p2::start1;
}
const int p2::getStart2(){
    return p2::start2;
}
const int p2::getEnd1(){
    return p2::end1;
}
const int p2::getEnd2(){
    return p2::end2;
}