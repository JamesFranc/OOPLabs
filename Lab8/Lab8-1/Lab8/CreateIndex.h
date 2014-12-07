//--------------------------------------------------------------
//
//  CreateIndex.h
//  p5
//
//--------------------------------------------------------------


#ifndef p5_CreateIndex_h
#define p5_CreateIndex_h
#include <list>
#include <string>
#include <fstream>
#include "Record.h"
#include "HashTable.h"

using namespace std;

class CreateIndex{
public:

    CreateIndex();
    void run(string fileName);
    void printInventory(list <Record> myList, fstream& myFile);
    int getRecords();
    void createBinaryFile(int numRecords);
    void createBinaryIndex(int numRecords);

    
private:
    int records;
    string NumberToString (int t);
};
#endif
