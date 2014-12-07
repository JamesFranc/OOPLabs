//
//  fileHandlerTest.h
//  p4
//
//  Created by James Francis II on 10/13/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

#ifndef __p4__fileHandlerTest__
#define __p4__fileHandlerTest__

#include <stdio.h>
#include <iomanip>
#include <fstream>

class fileHandler{
public:
    
    fileHandler();
    void outputLine(ostream &output, const Item & );
    void updateHeader(int lines, fstream& myFile);
    void printRecords(fstream& myFile);
    
private:
    
    
};

#endif /* defined(__p4__fileHandlerTest__) */
