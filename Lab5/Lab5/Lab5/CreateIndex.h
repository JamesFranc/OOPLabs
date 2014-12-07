//--------------------------------------------------------------
//
//  CreateIndex.h
//  p5
//
//--------------------------------------------------------------


#ifndef p5_CreateIndex_h
#define p5_CreateIndex_h
#include <list>


class CreateIndex{
public:

    CreateIndex();
    void run();
    void printInventory(list <Record> myList, fstream& myFile);
    int getRecords();
    void createBinaryFile(int numRecords);
private:
    int records;
};
#endif
