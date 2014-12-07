/*
 PROGRAM NAME: Program 7: Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 17, 2014
 
 DUE DATE:     November 18, 2014
 
 PROGRAM PURPOSE:
 This program is used to implement to Hashtable class, and Node class, for use in a dictionary-like Structure.
 This program will read in data from prog7.dat and search for words that may be in the hashtable based upon input from the file.
 
 VARIABLE DICTIONARY:
 
 t: Reference to a Hashtable Object
 infile: fstream object, input file
 
 
 ADTs: Hashtable
 
 
 FILES USED: Hashtable.h prog7.dat
 
 
 SAMPLE INPUTS: (from prog7.dat)
 
 the relative lack of acceptance
 of these products in the
 corporate marketplace is
 due less to technical than
 to political factors the
 availability of this technology
 threatens the perks privileges
 and traditions of corporate
 management
 **********
 the
 political
 lack
 relative
 less
 forgive
 tradition
 factors
 more
 
 SAMPLE OUTPUTS:
 
 Found 'the' with 1 access(es)
 the appears on line(s): 1 2 5 7
 
 Found 'political' with 2 access(es)
 political appears on line(s): 5
 
 Found 'lack' with 1 access(es)
 lack appears on line(s): 1
 
 Found 'relative' with 1 access(es)
 relative appears on line(s): 1
 
 Found 'less' with 1 access(es)
 less appears on line(s): 4
 
 Unable to find 'forgive' with 2 access(es).
 
 Unable to find 'tradition' with 4 access(es).
 
 Found 'factors' with 3 access(es)
 factors appears on line(s): 5
 
 Unable to find 'more' with 5 access(es).
 
 ---Averages rounded to the nearest integer---
 Average number of accesses for successful retrieval: 1
 
 Average number of accesses for unsuccessful retrieval: 3
 
 Average number of accesses over total retrievals: 2
 
 ---------------------------------------------------------------------*/


#include "HashTable.h"

int main(int argc, const char * argv[]) {
    
    HashTable t = *new HashTable();
    
    fstream infile("../instr/prog7.dat", ios::in);
    if (!infile.is_open()) {
        cout<<"File not found."<<endl;
        return -1;
    }
    
    t.populate(infile);
    
    infile.close();
    
    t.hashingReport();
    
    return 0;
}
