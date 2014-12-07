//--------------------------------------------------------------
//
//  SearchIndex.h
//  p5
//
//--------------------------------------------------------------

#ifndef __p5__SearchIndex__
#define __p5__SearchIndex__

#include "Item.h"
#include "Record.h"
#include <sstream>
#include <list>

using namespace std;

class SearchIndex{
public:
    SearchIndex();
    void run(string searchKey, string fileName, int records);
    int binarySearch(int keyArr[], int numRecords, int key);
    void getRecord(int offset);
    void outputLine(const Item &record);
    int convert(const string& str);
};

#endif /* defined(__p5__SearchIndex__) */
