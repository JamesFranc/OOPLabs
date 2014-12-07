//
//  main.c
//  p7
//
//  Created by James Francis II on 11/17/14.
//
//

#include "Node.h"

int main(int argc, const char * argv[]) {
    
    fstream infile("../instr/prog7.dat", ios::in);
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

}
