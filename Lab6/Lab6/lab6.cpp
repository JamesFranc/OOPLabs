/*
 PROGRAM NAME: Program 6: Linked Lists
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 1, 2014
 
 DUE DATE:     November 6, 2014
 
 PROGRAM PURPOSE:
 This program is used to implement to Linked List class, and Card class, for use in a Hyperstack-like Structure.
 This program will read in data from prog6.dat and perform operations on the hyperstack based upon input.
 
 VARIABLE DICTIONARY:
 
 stack: Reference to a HyperCardStack Object
 command: charcater containing the command to be performed
 key: key value to be inserted or deleted
 entry: string containing a fact
 line: string containin a line of input from the input file
 
 ADTs: HyperCardStack
 
 
 FILES USED: prog6.dat
 
 
 SAMPLE INPUTS(from prog6.dat):
 
 i 27 Mary had a little lamb
 i 15 Today is a good day
 i 35 Now is the time!
 i 9 This lab is easy and fun
 p
 d 35
 t
 i 37 Better Now.
 f
 p
 h
 p
 d 27
 d 15
 d 37
 d 9
 i 44 This should be it!
 t
 p
 
 SAMPLE OUTPUTS:(to console)
 
 Inserting: 27
 
 Inserting: 15
 
 Inserting: 35
 
 Inserting: 9
 
 Printing:  This lab is easy and fun
 
 Removing: 35
 
 Traversing:  Today is a good day   This lab is easy and fun   Mary had a little lamb
 
 Inserting: 37
 
 Moving the current pointer forward.
 
 Printing:  Better Now.
 
 Moving the current pointer home.
 
 Printing:  Mary had a little lamb
 
 Removing: 27
 
 Removing: 15
 
 Removing: 37
 
 Removing: 9
 
 Inserting: 44
 
 Traversing:  This should be it!
 
 Printing:  This should be it!

 
 ---------------------------------------------------------------------*/

#include "Card.h"
#include "HyperCardStack.h"

void parseInput(HyperCardStack& stack,char c, int key, string entry);


int main(int argc, const char * argv[]) {

    HyperCardStack stack = HyperCardStack();

    fstream infile("../instr/prog6.dat", ios::in);
    if (!infile.is_open()) {
        cout<<"File not found."<<endl;
        return -1;
    }
    string line;
    char command;
    int key;
    string entry;
    
    
    while (!infile.eof()) {
        command='\0';
        key='\0';
        entry=" ";
        
        getline(infile, line);
        stringstream linestream(line);
        linestream>>command;
        linestream>>key;
        string str;
        while (linestream>>str) {
            str+=" ";
            entry+=str.c_str();
        }
        
        parseInput(stack, command, key, entry);
    }

    infile.close();


       return 0;
}

void parseInput(HyperCardStack& stack,char c, int key, string entry){
    //--------------------------------------------------------------
    //Preconditions: a reference to a HyperCardStack, a character,
    //       an integer and a string are passed by the calling code.
    //
    //Postconditions: An insert, delete, traverse, home, forward or
    //             print are performed on the passed HyperCardStack.
    //
    //Variables used:   stack: Reference to a HyperCardStack Object
    //                  c: charcater containing the command to be
    //                      performed
    //                  key: key value to be inserted or deleted
    //                  entry: string to be inserted
    //--------------------------------------------------------------
    
    switch (c) {
        case 'i':
            stack.insert(key, entry);
            cout<<endl;
            break;
            
        case 'd':
            stack.remove(key);
            cout<<endl;
            break;
            
        case 't':
            stack.traverse();
            cout<<endl;
            break;
            
        case 'h':
            stack.home();
            cout<<endl;
            break;
            
        case 'f':
            stack.forward();
            cout<<endl;
            break;
            
        case 'p':
            stack.print();
            cout<<endl;
            break;
            
        default:
            break;
    }

}
