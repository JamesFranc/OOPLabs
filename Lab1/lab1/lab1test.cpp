//
//  lab1test.cpp
//  prog1
//
//  Created by James Francis II on 9/9/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

#include "lab1.h"

int main(int argc, const char * argv[])
{
    int size = 0;
    int left=0;
    int right=0;
    int bottom=0;
    int top = 0;
    
    // Open input file and determine the size of the the array by assigning the first valeu in the file to the size variable
    ifstream infile("../instr/prog1.dat");
    for (int i=0;i<1;i++){
        infile>>size;
        std::cout<<std::endl;
    }
    
    int intArray[size][size];
    //
    // Populate the previously made array
    //
    for (int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            infile>>intArray[i][j];
            
        }
    }
    
    std::string spaces = "";
    std::string dashes = "-";
    
    
    std::cout << "Uncorrected Input" <<std::endl;
    
    for (int i = 0; i <size;i++){
        dashes=dashes+"--";
        spaces=spaces+"  ";
    }
    
    std::cout << dashes << "| " <<std::endl;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            std::cout << intArray[i][j] << ' ';
        }
        std::cout << " | " <<std::endl;
    }
    
    std::cout << spaces <<" | " <<std::endl;
    
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            int value = intArray[i][j];
            std::cout << swapNumforDarkChar(value) << ' ';
        }
        std::cout << " | " <<std::endl;
    }
    
    std::cout << dashes << "| " <<std::endl;
    std::cout <<std::endl<<std::endl;
    
    
    
    //-------------------------------------------------------------------------------------------
    //Begin segment of code for corrected Input
    //-------------------------------------------------------------------------------------------
    
    std::cout << "Corrected Input" << std::endl;
    
    std::cout << dashes << "| " <<std::endl;
    int current = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            current = 0;
            double avg=0;
            current = intArray[i][j];
            //std::cout <<"current = "<<current;
            
            //-----------------------------------------------------------------------------------------
            //This statement handles the special case of the first element within the first row
            //-----------------------------------------------------------------------------------------
            if (i==0 && j==0) {
                //-----------------------------------------------------------------------------------------
                //This statement handles the special case of the first element within the first row
                //-----------------------------------------------------------------------------------------
                right = intArray[i][j+1];
                bottom = intArray[i+1][j];
                
                int difference1 = std::abs(current-bottom);
                int difference2 = std::abs(current-right);
                
                if((difference1==1 && difference2==1) || (difference1==0&&difference2 ==0) || (difference1==1 && difference2==0)|| (difference1==0 && difference2==1)){
                    intArray[i][j] = intArray[i][j];
                    
                    //checking the value of i=0,j=0 is:
                    //std::cout <<"checkedArray["<<i<<"]["<<j<<"] = "<<checkedArray[i][j]<< ' ';
                    
                }
                else{
                    avg = (right+bottom)/2.0;
                    intArray[i][j] = static_cast<int>(floor(avg+.5));
                }
            }
            
            
            //-------------------------------------------------------------------------------------
            //This statement handles the special case of the nonfirst and nonlast elements in the
            //first row
            //-------------------------------------------------------------------------------------
            if (i==0 && (j>0 && j<(size-1))) {
                //-------------------------------------------------------------------------------------
                //This statement handles the special case of the nonfirst and nonlast elements in the
                //first row
                //-------------------------------------------------------------------------------------
                
                left = intArray[i][j-1];
                
                
                right = intArray[i][j+1];
                
                bottom = intArray[i+1][j];
                
                if(checkValueThree(current,left, right, bottom)){
                    intArray[i][j] = intArray[i][j];
                    //std::cout <<"checkedArray["<<i<<"]["<<j<<"] = "<<checkedArray[i][j]<< ' ';
                    
                }
                else{
                    avg =(left+right+bottom)/3.0;
                    intArray[i][j] = static_cast<int>(floor(avg+.5));
                    //std::cout <<"checkedArray["<<i<<"]["<<j<<"] = "<<checkedArray[i][j]<< ' ';
                    
                    //std::cout << ' ' <<checkedArray[i][j];
                    
                }
            }
            
            //-----------------------------------------------------------------------------------------
            //This statement handles the special case of the last element within the first row
            //-----------------------------------------------------------------------------------------
            if (i==0 && j==size-1) {
                //-----------------------------------------------------------------------------------------
                //This statement handles the special case of the last element within the first row
                //-----------------------------------------------------------------------------------------
                
                left = intArray[i][j-1];
                bottom = intArray[i+1][j];
                if(checkValueTwo(current, left, bottom)==true){
                    intArray[i][j] = intArray[i][j];
                    //std::cout <<"checkedArray["<<i<<"]["<<j<<"] = "<<checkedArray[i][j]<< ' ';
                    
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((left+bottom)/2.0)+.5));
                }
            }
            
            //-------------------------------------------------------------------------------------
            //This statement handles the special case of nonfirst and nonlast elements in the
            //first column
            //-------------------------------------------------------------------------------------
            if ( (i>0 && i<(size-1)) && j==0) {
                //-------------------------------------------------------------------------------------
                //This statement handles the special case of nonfirst and nonlast elements in the
                //first column
                //-------------------------------------------------------------------------------------
                
                top = intArray[i-1][j];
                right = intArray[i][j+1];
                bottom = intArray[i+1][j];
                if(checkValueThree(current,top, right, bottom)){
                    intArray[i][j] = intArray[i][j];
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((top+right+bottom)/3.0)+.5));
                }
            }
            
            //-------------------------------------------------------------------------------------
            //This statement handles all elements not in the first or last row or column
            //-------------------------------------------------------------------------------------
            if ( (i>0 && i<(size-1)) && (j>0||j<(size-1)) ){
                //-------------------------------------------------------------------------------------
                //This statement handles all elements not in the first or last row or column
                //-------------------------------------------------------------------------------------
                
                top = intArray[i-1][j];
                left = intArray[i][j-1];
                right = intArray[i][j+1];
                bottom = intArray[i+1][j];
                if(checkValueFour(current, top, left, right, bottom)){
                    intArray[i][j] = intArray[i][j];
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((top+left+right+bottom)/4.0)+.5));
                }
            }
            
            //-------------------------------------------------------------------------------------
            //This statement handles the special case of last elements in the last column
            //-------------------------------------------------------------------------------------
            if ( (i>0 && i<(size-1)) && j==(size-1)) {
                //-------------------------------------------------------------------------------------
                //This statement handles the special case of last elements in the last column
                //-------------------------------------------------------------------------------------
                
                top = intArray[i-1][j];
                left = intArray[i][j-1];
                bottom = intArray[i+1][j];
                if(checkValueThree(current,top, left, bottom)){
                    intArray[i][j] = intArray[i][j];
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((top+left+bottom)/3.0)+.5));
                }
            }
            
            //-----------------------------------------------------------------------------------------
            //This statement handles the special case of the first element within the last row
            //-----------------------------------------------------------------------------------------
            if (i==(size-1) && j==0) {
                //-----------------------------------------------------------------------------------------
                //This statement handles the special case of the first element within the last row
                //-----------------------------------------------------------------------------------------
                top = intArray[i-1][j];
                right = intArray[i][j+1];
                if(checkValueTwo(current, right, top)){
                    intArray[i][j] = intArray[i][j];
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((right+top)/2.0)+.5));
                }
            }
            
            //-------------------------------------------------------------------------------------
            //This statement handles the special case of the nonfirst and nonlast elements in the
            //last row
            //-------------------------------------------------------------------------------------
            if (i==(size-1) && (j>0&&j<(size-1))) {
                //-------------------------------------------------------------------------------------
                //This statement handles the special case of the nonfirst and nonlast elements in the
                //last row
                //-------------------------------------------------------------------------------------
                
                left = intArray[i][j-1];
                right = intArray[i][j+1];
                top = intArray[i-1][j];
                if(checkValueThree(current,left, right, top)){
                    intArray[i][j] = intArray[i][j];
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((left+right+top)/3.0)+.5));
                }
            }
            
            //-----------------------------------------------------------------------------------------
            //This statement handles the special case of the first element within the first row
            //-----------------------------------------------------------------------------------------
            if (i==size-1&&j==size-1) {
                //-----------------------------------------------------------------------------------------
                //This statement handles the special case of the first element within the first row
                //-----------------------------------------------------------------------------------------
                top = intArray[i-1][j];
                left = intArray[i][j-1];
                if(checkValueTwo(current, top, left)){
                    intArray[i][j] = intArray[i][j];
                    
                }
                else{
                    intArray[i][j] = static_cast<int>(floor(((top+left)/2.0)+0.5));
                }
            }
            std::cout<< intArray[i][j]<< ' ';
            
            
        }
        
        std::cout << " | " <<std::endl;
    }
    
    std::cout << spaces <<" | " <<std::endl;
    
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            int value = intArray[i][j];
            std::cout << swapNumforDarkChar(value) << ' ';
        }
        std::cout << " | " <<std::endl;
    }
    std::cout << dashes << "| " <<std::endl;
    std::cout <<std::endl<<std::endl;
    
    return 0;
}
