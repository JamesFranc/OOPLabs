//--------------------------------------------------------------
//
//  main.cpp
//  p5
//
//--------------------------------------------------------------

#include "Item.h"
#include "Record.h"
#include "CreateIndex.h"

CreateIndex::CreateIndex(){
    //--------------------------------------------------------------
    // DEFAULT CONSTRUCTOR
    //--------------------------------------------------------------
}

void CreateIndex::run() {

    //--------------------------------------------------------------
    //Preconditions: The calling code has called this method
    //
    //Postconditions: An index file containing 
    //
    //Variables used: infile1: fstream object that accesses prog5.idx
    //                infile2: fstream object to the data file prog5.dat
    //                numRecords: number of records in the data file
    //                keyArr[]: an integer array used to store keys
    //                item: used to reference a Record object
    //                bsearchResult: integer containing the result
    //                  of the binarySearchMethod
    //                stockNum: int to hold the Stock value
    //                description: string description of the current record
    //                count: count value for the current record
    //                cost: double value of the cost of the current record
    //
    //--------------------------------------------------------------
    
    list <Record> myList;
    Record record;
    Item item;
    int lines = 0;
    
    //open fstream of input file
    
    
    fstream infile1("../instr/prog5.dat", ios::in);
    if (!infile1.is_open()) {
        cout<<"could not open prog5.dat"<<endl;
    }else{
    int numRecords;
    infile1>>numRecords;
    records = numRecords;
    infile1.close();
    list <int> myList1;
    
    fstream infile2("../instr/prog5.dat", ios::in);
    
    
    createBinaryFile(numRecords);
    
    
    fstream myFile("prog5bin.dat", ios::in|ios::out|ios::binary);
    
    
    int stockNum;
    string description;
    int count;
    double cost;
    int n=0;
    
    
    while (infile2 >> stockNum >> description >> count >> cost) {
        
        
        
        item = Item(stockNum, description, count, cost);
        //Creates Item objects and writes the information contained within the object to the output file
        record = Record(stockNum, lines);
        
        //following line moves the filepointer to the item's location in bytes on the list
        myFile.seekg(lines*sizeof(Item));
        
        //following line writes the information to the output file
        myFile.write(reinterpret_cast<const char *>(&item), sizeof(Item));
        
        
        
        myList1.push_back(stockNum);

        myList.push_back(record);

        n++;
        lines++;
    }
    
    infile2.close();//close input file

    
    //following block of code creates the output file
    ofstream openFile;
    openFile.open("prog5.idx", ios::out);
    openFile.close();
    //end creation of output file
    
    fstream indexFile("prog5.idx", ios::out);
    myList.sort();
    printInventory(myList, indexFile);

    cout<<endl;

    }
    
    
}

void CreateIndex::printInventory(list <Record> myList, fstream& myFile){
    //--------------------------------------------------------------
    //Preconditions: a reference to an output stream and a reference
    //               to List were passed by the calling code
    //Postconditions: the contents of the list are sent to
    //                the output stream
    //
    //Variables used: &myfile: reference to an output stream
    //                item: reference to an Item object
    //--------------------------------------------------------------
    
    for(std::list<Record>::iterator it = myList.begin(); it!= myList.end(); ++it)
    {
        Record item = *it;
        if(item.getOffset()>0){
        myFile <<left << setw(6)<< item.getKey()<<setw(2)<< item.getOffset()<<endl;
        }
    }
}

int CreateIndex::getRecords(){
    return records;
}

void CreateIndex::createBinaryFile(int numRecords){
    //--------------------------------------------------------------
    //Preconditions: number of records in the data file is passed by
    //                  the calling code
    //Postconditions: a binary file is created that has the same
    //                information as the data file
    //
    //Variables used: openfile: ofstream used to create the binary file
    //                item: reference to an Item object
    //--------------------------------------------------------------
    
    ofstream openFile;
    openFile.open("prog5bin.dat", ios::out|ios::binary);
    openFile.close();
    
    Item item = Item();
    fstream myFile("prog5bin.dat", ios::in|ios::binary);

    int i = 0;
    for(i = 0; i<numRecords+1;i++){
        myFile.write(reinterpret_cast< const char * >(&item), sizeof(Item));
    }
    myFile.close();
}


