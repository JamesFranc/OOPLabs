/*
 PROGRAM NAME: Program 8: External Hashing Search (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 30, 2014
 
 DUE DATE:     December 2, 2014
 
 PROGRAM PURPOSE:
 This program is used to implement to Hashtable class, and Node class, for use in an External Hashtable Structure.
 This program will read in data from prog8.dat and create a binary index file that represents the hash table.
 
 VARIABLE DICTIONARY:
 
 t: Reference to a Hashtable Object
 infile: fstream object, input file
 
 
 ADTs: Hashtable
 
 
 FILES USED: HashTable.h Item.h index.dat index.idx
 
 
 SAMPLE INPUTS: (from index.idx)
 <<<Binary Data>>>
 
 
 SAMPLE OUTPUTS:
 
 Please enter a search key: 12345
 Please enter the index file name:
 index.idx
 Loading index.idx
 
 12345 Item06 45 14.2
 ---------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "Item.h"
#include "HashTable.h"

	using namespace std;

	int get_int(string message);
	void getRecord(int offset);

int main(int argc, const char * argv[]) {
    	    // insert code here...
    	    string search = "Please enter a search key: ";
    	    int searchKey = get_int(search);
    	    string filename;
    	    fstream infile;
    
    	    cout << "Please enter the index file name: ";
        while (true)
            {
            	        cout<<endl;
            	        getline( cin, filename);
            	        infile.open(filename.c_str(), ios::in | ios::binary);
            	        if (infile){
            	            cout<<"Loading "<<filename<<endl;
                
            	            break;
            	        }
            	        cout << "Invalid file or path. Please enter a valid input file name: ";
            	    }
    
    
    	    HashTable table = HashTable();
    
    	    Node newNode;
    
        while (infile) {
        	        infile.read(reinterpret_cast<char * >(&newNode), sizeof(Node));
        
        	        if (newNode.getKey() <= 0) {
        
        	        }
        
                else{
            	            //cout<<"inserting: "<<newNode.getKey()<<" with offset: "<<newNode.getOffset()<<endl;
    	            Node* newPtrNode = new Node(newNode.getKey(),newNode.getOffset());
    	            table.insert(newPtrNode);
    	        }
    	        newNode = Node();
        
    	    }
    
    	    infile.close();
    
    	    int offset = table.search(searchKey);
    	    getRecord(offset);
    
    
    	    return 0;
    	}

int get_int(string message){
    
    	    int out;
    	    string in;
    
    	    while(true) {
    
    	        cout << message;
    	        getline(cin,in);
    	        stringstream ss(in); //covert input to a stream for conversion to int
    
    	        if(ss >> out && !(ss >> in)) return out;
    	        //(ss >> out) checks for valid conversion to integer
    	        //!(ss >> in) checks for unconverted input and rejects it
    
    	        cin.clear(); //in case of a cin error, like eof() -- prevent infinite loop
    	        cerr << "\nInvalid input. Please try again.\n"; //if you get here, it's an error
    	    }
    }

	void getRecord(int offset){
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
fstream inputFile("index.dat", ios::in|ios::binary);
    
inputFile.seekg(offset*sizeof(Item));
cout<<endl;
inputFile.read(reinterpret_cast<char * >(&item), sizeof(Item));
   cout<<item.getStockNum()<<" "<<item.getDescription()<<" "<<item.getCount()<<" "<<item.getCost()<<endl;
inputFile.close();
}

