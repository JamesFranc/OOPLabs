//--------------------------------------------------------------
//
//  SearchIndex.cpp
//  p5
//
//--------------------------------------------------------------

#include "Record.h"
#include "Item.h"
#include "SearchIndex.h"

SearchIndex::SearchIndex(){
    //--------------------------------------------------------------
    // DEFAULT CONSTRUCTOR
    //--------------------------------------------------------------
}

void SearchIndex::run(string searchKey, string fileName, int records){
    //--------------------------------------------------------------
    //Preconditions: A key string values, a string containing a filename
    //                of an index file, and the total number of records
    //
    //Postconditions: The integer value of the search key is returned
    //               if found, else 0 is returned to the calling code
    //
    //Variables used: myFile: fstream object that accesses prog5.idx
    //                infile: fstream object to the data file prog5.dat
    //                sKey: integer value of the search key
    //                offset: integer containing the RRN (offset)
    //                keyArr[]: an integer array used to store keys
    //                item: used to reference a Record object
    //                bsearchResult: integer containing the result
    //                  of the binarySearchMethod
    //
    //--------------------------------------------------------------
    
    fstream myFile(fileName.c_str(), ios::in);
    fstream infile("../instr/prog5.dat", ios::in);
    
    int sKey;
    sKey = convert(searchKey);
    int n=0;
    int key, offset;
    
    int keyArr[records];
    
    int i = 0;
    
    Record item;
    
    while (myFile >> key >> offset) {
        while(i!=offset){
            i++;
        }
        
        //Creates Item objects and writes the information contained within the object to the output file
        keyArr[i] = key;
        i=0;
        n++;
        
    }
    
    int bSearchResult = binarySearch(keyArr, records, sKey);
    
    if (bSearchResult > 0) {
        getRecord(bSearchResult);
        
    } else {
        cout << "Key not found, please try again." << endl;
    }
    
    
    
}

int SearchIndex::binarySearch(int keyArr[], int numRecords, int key){
    //--------------------------------------------------------------
    //Preconditions: An array of key values, a total number of records
    //               and a key to be search for is passed to the method
    //
    //Postconditions: The integer value of the search key is returned
    //               if found, else 0 is returned to the calling code
    //
    //Variables used: mid: middle index within the array to be compared
    //                lower: leftmost index of the array to be compared
    //                upper: rightmost  index of the array to be compared
    //--------------------------------------------------------------
    
    int mid,lower = 0;
    int upper = numRecords;
    while( lower <= upper )
    {
        mid = ( lower + upper )/2;
        if( key > keyArr[mid] )
            lower = mid+1;
        else if(key < keyArr[mid])
            upper = mid-1;
        else
            return mid;
    }
    return 0;
}

void SearchIndex::getRecord(int offset){
    //--------------------------------------------------------------
    //Preconditions: An integer is passed to the method
    //
    //Postconditions: The record referenced by the passed integer is
    //                printed to the screen
    //
    //Variables used: inputFile: reference to an input file stream
    //                &item reference to an Item object
    //--------------------------------------------------------------
    
    Item item;
    
    fstream inputFile("prog5bin.dat", ios::in|ios::binary);
    inputFile.seekg(offset*sizeof(item));
    
    inputFile.read(reinterpret_cast<char * >(&item), sizeof(Item));
    outputLine(item);
    inputFile.close();
}

void SearchIndex::outputLine(const Item &record){
    //--------------------------------------------------------------
    //Preconditions: a reference to an output stream and a reference
    //               to an Item object were passed by the calling code
    //Postconditions: the contents of the record object are sent to
    //                the output stream
    //
    //Variables used: &output: reference to an output stream
    //                &record reference to an Item object
    //--------------------------------------------------------------
    cout << right << setw(5)<< record.getStockNum()<<right <<setw(8) << record.getDescription() << right << setw(3)<< record.getCount()<< right<<setw(6)<<record.getCost()<<endl;
    
    cout.clear();
    
    
}

int SearchIndex::convert(const string& str) {
    stringstream ss(str);
    int n;
    ss >> n;
    return n;
}
