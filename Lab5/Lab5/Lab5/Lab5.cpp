/*
 PROGRAM NAME: Program 5: Indexed Files
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: October 21, 2014
 
 DUE DATE:     October 28, 2014
 
 PROGRAM PURPOSE:
 
 1) Create a blank binary file
 2) Read in "inventory" updates from prog4.dat to Item objects
 3) Write the Item objects to the previously created binary file
 4) Print to console the item record in the file going from one
 item to the next based on their nextItem variable
 
 
 VARIABLE DICTIONARY:
 
 indexer: CreateIndex object that will create an index of records within the data file
 searcher: SearchIndex object that will perform search operations
 key: String holds the value of the key to be searched for
 fileName: String holds the value of the index file
 
 ADTs: std::list
 
 FILES USED: prog5.dat
 
 
 SAMPLE INPUTS:
 
search 12382 prog5.idx
 
 
 SAMPLE OUTPUTS: 
 
 12382 Item09 62 41.37
 
 
 ---------------------------------------------------------------------*/

#include "Record.h"
#include "Item.h"
#include "CreateIndex.h"
#include "SearchIndex.h"

int main(int argc, const char * argv[]){
    
    CreateIndex indexer = CreateIndex();
    indexer.run();
    
    SearchIndex searcher = SearchIndex();
    string key = argv[1];
    string fileName = argv[2];
    
    searcher.run(key,fileName, indexer.getRecords());
    
    return 0;
}
