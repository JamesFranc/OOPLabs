//
//  main.cpp
//  p4
//
//  Created by James Francis II on 10/7/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

#include "Item.h"
#include "fileHandler.h"


fileHandler::fileHandler() {
    //--------------------------------------------------------------
    //DEFAULT FILEHANDLER CONSTRUCTOR
    //--------------------------------------------------------------
    }

void fileHandler::outputLine(ostream &output, const Item &record){
    //--------------------------------------------------------------
    //Preconditions: a reference to an output stream and a reference
    //               to an Item object were passed by the calling code
    //Postconditions: the contents of the record object are sent to
    //                the output stream
    //
    //Variables used: &output: reference to an output stream
    //                &record reference to an Item object
    //--------------------------------------------------------------
    output << right << setw(4)<< record.getStockNum()<<right <<setw(8) << record.getDescription() << right<<setw(4)<< record.getCount();

    cout.clear();

    
}

void fileHandler::updateHeader(int lines, fstream& myFile){
    //--------------------------------------------------------------
    //Preconditions: a reference to a file stream and an integer
    //               were passed by the calling code.
    //Postconditions: An integer value representing the number of
    //                valid records is written to the Header record
    //
    //Variables used: lines -  integer representing valid records
    //               myFile - reference to an fstream output file
    //--------------------------------------------------------------
    
    myFile.seekp(0);
    int stockNum = lines;
    string description = "Records";
    int qty = 0;
    int nextItem = 0;
    Item record = Item(stockNum, description, qty, nextItem);
    
    // following line writes the information stored in the object record
    // to the output filestream
    myFile.write(reinterpret_cast<const char *>(&record), sizeof(Item));
    myFile.seekp(0);
}

void fileHandler::printRecords(fstream& myFile){
    //----------------------------------------------------------------------------
    //Preconditions: a reference to a file stream is passed from the calling code.
    //Postconditions: All records are printed in a random access fashion 
    //
    //Variables used: lines -  integer representing valid records
    //               myFile - reference to an fstream output file
    //----------------------------------------------------------------------------
    

    
    int n=0;
    Item record;
    bool eof = false;
    cout<<endl;
    while (eof==false) {
        myFile.seekg(n*sizeof(Item));

        myFile.read(reinterpret_cast<char * >(&record), sizeof(Item));
    
        if (record.getStockNum()>0 && record.getNext()>0  ) {
            
            // This statement sends the record to be printed and cout
            // so the record's content can be printed to console
            // n is set to the next item so the pointer within the fstream
            // can be moved to the next item in sequence
 
            outputLine(cout, record);
            cout<<endl;
            cout.clear();
            n=record.getNext();

        }else if(record.getStockNum()>0 && record.getNext()==-1){
            
            // This statement sends the last Item to be printed
            // so the record's content can be returned to console
            // eof is encountered because a nextItem value of -1
            // indicates the last Item
            
            outputLine(cout, record);
            cout<<endl;

            cout.clear();
            eof = true;
            
        } else n=1;
        
    }
    cout<<endl;
}
