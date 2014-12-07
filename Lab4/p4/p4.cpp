/*
 PROGRAM NAME: Program 4: Random Access Files
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: October 9, 2014
 
 DUE DATE:     October 16, 2014
 
 PROGRAM PURPOSE:
 
 1) Create a blank binary file
 2) Read in "inventory" updates from prog4.dat to Item objects
 3) Write the Item objects to the previously created binary file
 4) Print to console the item record in the file going from one
    item to the next based on their nextItem variable
 
 
 VARIABLE DICTIONARY:
 
 handler: fileHandler object that will handle records within the file
 lines: integer that counts the number of records from the update file
 record: Item object used to hold values from the update file
 stockNum: integer representation of an item's stock number
 description: string - brief description of the current record
 qty: integer used to hold the count of a given stockNum
 nextItem: integer used to hold the next stock number in "inventory"
 
 ADTs: none
 
 FILES USED: prog4.dat
 
 
 SAMPLE INPUTS:
 
 10 zidgits 17 -1
 14 lidgits 2 7
 6 gidgits 12 8
 1 bidgits 25 3
 16 widgits 9 10
 7 midgits 0 2
 3 didgits 11 6
 5 tidgits 6 16
 2 pidgits 7 5
 8 kidgits 6 14

 
 SAMPLE OUTPUTS: (to prog4out.dat)
 
  1 bidgits  25
  3 didgits  11
  6 gidgits  12
  8 kidgits   6
 14 lidgits   2
  7 midgits   0
  2 pidgits   7
  5 tidgits   6
 16 widgits   9
 10 zidgits  17
 
 ---------------------------------------------------------------------*/

#include "Item.h"
#include "fileHandler.h"

int main(int argc, const char * argv[]){

    fileHandler handler = fileHandler();
    int lines = 0;
    
    //following block of code creates the output file
    ofstream openFile;
    openFile.open("prog4out.dat", ios::out|ios::binary);
    openFile.close();
    //end creation of output file
    
    fstream myFile("prog4out.dat", ios::in|ios::out|ios::binary);
    Item record;
    
    // files the output file with empty Item objects, each 20 bytes in size
    // 21 items are written, the first is a placeholder for the header record
    int i = 0;
    for(i = 0; i<21;i++){
        myFile.write(reinterpret_cast< const char * >(&record), sizeof(Item));
    }
    
    fstream infile("../instr/prog4.dat", ios::in|ios::binary);
    
    int stockNum;
    string description;
    int qty;
    int nextItem;

    while (infile >> stockNum >> description >> qty >> nextItem) {
        cout<<stockNum;
        //Creates Item objects and writes the information contained within the object to the output file
        record = Item(stockNum, description, qty, nextItem);

        //following line moves the filepointer to the item's location in bytes on the list
        myFile.seekg(record.getStockNum()*sizeof(Item));
        
        //following line writes the information to the output file
        myFile.write(reinterpret_cast<const char *>(&record), sizeof(Item));
        
        lines++;
    }

    infile.close();//close input file
    
    myFile.seekg(0);//move filepointer to the beginning of the filestream
    
    handler.updateHeader(lines, myFile);//update the header record with the number of records now in the file
    
        
    handler.printRecords(myFile);//print the records, sequentially, from the updated file
    
    myFile.close();//close output file

    return 0;
}
