//--------------------------------------------------------------
//
//  Record.h
//  p5
//
//--------------------------------------------------------------


#ifndef __p5__Record__
#define __p5__Record__

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class Record{
public:
    int key;
    int offset;
    Record();
    Record(int key,int offset);
    int getKey() const;
    int getOffset() const;
    void printDetails();
    bool operator <(const Record& r2)const;
    bool operator ==(const Record& r2)const;
    bool operator> (const Record& r2)const;
    
private:

    void setKey(int n);
    void setOffset(int n);

};

#endif /* defined(__p5__Record__) */

