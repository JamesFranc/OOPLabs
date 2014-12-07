/*
 PROGRAM NAME: Program 2: File Merge
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: September 19, 2014
 
 DUE DATE:     September 23, 2014
 
 PROGRAM PURPOSE:
 This text class is used to test p2. This class accepts command line arguments that are used to 
 instantiate the p2 class. This class accepts 5 arguments in the form of:
 
 p2 infile.dat startLine-endLine infile2.dat startLine-endLine outFile.dat
 
 where infile and infile2 are the source files, startLine is the first line from the proceeding infile
 to be appended to the outFile, and endLine is the last line from the proceeding infile to be appended
 to the outfile.
 
 The file outputs outfile.
 
 VARIABLE DICTIONARY:
 
 
 ADTs: none
 
 FILES USED: prog2a.dat prog2b.dat outputfile.dat
 
 
 SAMPLE INPUTS:
 
 (command line)
 p2 prog2a.dat 1-5 prog2b.dat 3-7 outfile.dat
 
 (prog2a.dat)
 This is the first line
 and this is the second line
 and this is the third line
 and the fourth
 and the fifth
 and here is the sixth and

 (prog2b.dat)
 This is the 1st line of many.
 Here is the 2nd of several,
 and the 3rd followed by
 the 4th as well as the
 5th which is the last in this paragraph
 A new paragraph has the 6th, followed
 by the 7th and
 the 8th
 and 9th closing with
 
 SAMPLE OUTPUTS:(to outfile.dat)
 
 This is the first line
 and this is the second line
 and this is the third line
 and the fourth
 and the fifth
 and the 3rd followed by
 the 4th as well as the
 5th which is the last in this paragraph
 A new paragraph has the 6th, followed
 by the 7th and
 
 ---------------------------------------------------------------------*/

#include "p2.h"

int checkEndValue(string);

int main(int argc, const char * argv[]){
    
    if (argc < 5) {
        
        // Informs the user how to run the program if they enter fewer than 5 arguments
        
        cerr << "Invalid number of arguments"<< endl;
        cerr << "Please ensure you have entered a command line argument in the following format:" << endl;
        cerr << endl;
        cerr << "fileMerge inputFile1 lineStart-lineEnd inputFile2 lineStart-lineEnd outputFile"<< endl;
        cerr << endl;
        cerr << "Example: fileMerge infil.dat 100-200 infil2.dat 150-300 outfile.dat\n"<< endl;
        return -3;
    }
    
    string file1 = argv[1];
    ifstream infile1;
    infile1.open(file1.c_str());
        if (!infile1.is_open()) {
           cerr << "Error opening file: "<<argv[1]<< "\nplease be sure the paths to the source files are correct and try again.\n";
            return -2;
        }
    
    string file2 = argv[3];
    ifstream infile2;
    infile2.open(file2.c_str());
        if (!infile2.is_open()) {
            cerr << "Error opening file: "<<argv[3]<< "\nplease be sure the paths to the source files are correct and try again.\n";
            return -1;
        }

    string startEnd1 = argv[2];
    string startEnd2 = argv[4];
    
    
    p2 merger = p2(startEnd1, startEnd2);
    
    if (merger.isRangeValid()==0) {
        cerr << "Start line cannot exceed end line. Check your inputs and try again.\n";
        return 0;
    }else if(merger.areLinesValid(checkEndValue(file1), checkEndValue(file2))==0){
        cerr << "Start line must be greater than 0 and the end line cannot exceed the number of lines in a file, check your inputs and try again.\n";
        return 1;

    }

    string file3 = argv[5];
    ofstream myfile3;
    myfile3.open(file3.c_str(), ios::out);
    //Opens an output filestream with an appending flag

    merger.mergeFile(infile1, myfile3, merger.getStart1(), merger.getEnd1());
    //Merges the first input file into the output file
    
    merger.mergeFile(infile2, myfile3, merger.getStart2(), merger.getEnd2());
    //Appends the second input file into the output file, after the first file
    
    infile1.close();
    infile2.close();
    myfile3.close();
    
    return 2;
}

int checkEndValue(string filename){
    //-----------------------------------------------------------------------------
    // This method accepts a filename and opens a stream, separate from the stream
    // used in the merger, and counts the lines in the passed filename, and returns
    // that count as an integer to the calling code.
    //-----------------------------------------------------------------------------
    ifstream file;
    file.open(filename.c_str());
    int j = 0;
    string line;
    while(getline(file, line)){
        j++;
    }
    file.close();
    return j;
}