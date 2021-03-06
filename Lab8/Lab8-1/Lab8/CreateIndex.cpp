//--------------------------------------------------------------
//
//  main.cpp
//  p5
//
//--------------------------------------------------------------

#include "Item.h"
#include "HashTable.h"
#include "Node.h"
#include "Record.h"
#include "CreateIndex.h"

CreateIndex::CreateIndex(){
    //--------------------------------------------------------------
    // DEFAULT CONSTRUCTOR
    //--------------------------------------------------------------
}

void CreateIndex::run(string fileName) {

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
    //Instantiates the list to be used to store records, and the hash table to store hashed keys
    
    Record record;
    Item item;
    
    //open fstream of input file
    
    
    fstream infile1(fileName.c_str(), ios::in);
        
    int numRecords= 0;
    string line ="";
        
        while (getline(infile1,line)) {
           //counts the number of records in the data file
            numRecords++;
        }

    records = numRecords-1;
        
    HashTable hTable = HashTable();
    //maximum size of the hash table determined and hash table created
        
    infile1.close();
        
    list <int> myList1;
    //begin inserting records into the hashtable

    fstream infile2(fileName.c_str(), ios::in);
    //reopen source file

    createBinaryFile(numRecords);
    //creates the binary file

    fstream myFile("index.dat", ios::out|ios::binary);
    //opens the previously created binary file

    
    int stockNum;
    string description;
    int code;
    double cost;
    int n=0;
    
    while ((infile2 >> stockNum >> description >> code >> cost)) {
        //While loop continues until no lines exist that fulfill the requirements for a record object
        
        item = Item(stockNum, description, code, cost);
        //Creates Item objects and writes the information contained within the object to the output file
        
        record = Record(stockNum, (stockNum%5));

        
        Node* newNode = new Node(record.getKey(), n);

        
        hTable.insert(newNode);

        myFile.seekg(n*sizeof(Item));
        //following line moves the filepointer to the item's location in bytes on the list

        myFile.write(reinterpret_cast<const char *>(&item), sizeof(Item));
        //following line writes the information to the binary output file

        //myList1.push_back(stockNum);
        
        //myList.push_back(record);

        n++;
    }
    
    infile2.close();//close input file

    
    //following block of code creates the output file
    hTable.createBinaryIndex(numRecords);
    cout<<endl;
      
        
    //hTable.printTable(records);

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
    openFile.open("index.dat", ios::out|ios::binary);
    openFile.close();
    
    Item item = Item();
    fstream myFile("index.dat", ios::in|ios::binary);

    int i = 0;
    for(i = 0; i<numRecords+1;i++){
        myFile.write(reinterpret_cast< const char * >(&item), sizeof(Item));
    }
    myFile.close();
}


