/*
 PROGRAM NAME: Program 8: External Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 30, 2014
 
 DUE DATE:     December 2, 2014
 
 PROGRAM PURPOSE:
 This program is used to implement to Hashtable class, and Node class, for use in an External Hashtable Structure.
 This program will read in data from prog8.dat and create a binary index file that represents the hash table.
 
 VARIABLE DICTIONARY:
 
 t: Reference to a Hashtable Object
 infile: fstream object, input file
 
 
 ADTs: Hashtable
 
 
 FILES USED: CreateIndex.h prog8.dat
 
 
 SAMPLE INPUTS: (from prog8.dat)
 12345 Item06 45 14.2
 12434 Item04 21 17.3
 12382 Item09 62 41.37
 34186 Item25 18 17.75
 12165 Item16 30 7.69
 16541 Item12 21 9.99
 21212 Itme31 19 8.35
 41742 Item14 55 12.36


 
 SAMPLE OUTPUTS:
 
 Hash table has been written to index.idx
 
 ---------------------------------------------------------------------*/

#include <iostream>
#include "CreateIndex.h"

using namespace std;

int main(int argc, const char * argv[]) {
 
    CreateIndex list = CreateIndex();
    // Will create the HashTable
    
    string filename;
    fstream infile;
    cout << "Please enter the data file name: ";
    while (true)
    {
        cout<<endl;
        getline( cin, filename);
        infile.open(filename.c_str(), ios::in | ios::binary);
        if (infile){
            infile.close();
            break;
        }
        cout << "Invalid file or path. Please enter a valid input file name: ";
    }
    
    list.run(filename.c_str());
    cout<<"Hash table has been written to index.idx"<<endl;
    
    
    return 0;
}
