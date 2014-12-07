/*
 PROGRAM NAME: Program 3: BRIDGE
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: September 5, 2014
 
 DUE DATE:     September 7, 2014
 
 PROGRAM PURPOSE:
 This class implements the Hand class and tests the data with a file supplied by the Instructor
 
 VARIABLE DICTIONARY:
 file: ifstream from the input file
 line: String used to store the current line of data from the ifstream
 currentHand: used to represent the current potential bridge hand to be score
 
 
 
 ADTs: none
 
 FILES USED: prog3.dat
 
 
 SAMPLE INPUTS: (first 6 lines of prog3.dat)
 
 2C QD TC AD 6C 3D TD 3H 5H 7H AS JH KH
 3C 4C 2D AC QC 7S 7C TD 9C 4D KS 8D 6C
 2C 3C KC JC 4C 8C 7C QC AC 5C 9C 6C TC
 5H 3S 4D KC 9S 3D 4S 8H JC TC 8S 2S 4C
 2S 5D 6S 8S 9D 3C 2H TH
 2H 6D %S 8S 7S 4D 3H 4S KS QH JH 5C 9S
 
 SAMPLE OUTPUTS:
 
 CLUBS:    6  2  10
 DIAMONDS: A  Q  3  10
 HEARTS:   K  J  7  5  3
 SPADES:   A
 
 Points = 16
 
 
 CLUBS:    A  Q  9  7  6  4  3
 DIAMONDS: 8  4  2  10
 HEARTS:
 SPADES:   K  7
 
 Points = 15
 
 
 CLUBS:    A  K  Q  J  9  8  7  6  5  4  3  2  10
 DIAMONDS:
 HEARTS:
 SPADES:
 
 Points = 27
 
 
 CLUBS:    K  J  4  10
 DIAMONDS: 4  3
 HEARTS:   8  5
 SPADES:   9  8  4  3  2
 
 Points = 6
 
 Too few cards in this hand, hand is invalid.
 
 Error in setting the Value for a card, hand is invalid.
 
 No more hands, File is closed
 
 ---------------------------------------------------------------------*/



#include "p3.h"

int main(int argc, const char * argv[]) {


    ifstream file("../instr/prog3.dat");
    if (!file.is_open()) {
        cerr << "Error opening file please ensure the data file is in the proper location.\n";
        return -2;
    }
    string line;
    while (!file.eof())
    {
        getline(file, line);
        Hand currentHand = Hand(line);
    }
    file.close();
    cout<<"No more hands, File is closed"<<endl;

    return 0;
}

