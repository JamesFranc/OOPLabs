//
//  lab1.cpp
//  prog1
//
//  Created by James Francis II on 9/9/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

#include "lab1.h"
bool checkValueTwo(int current, int val1, int val2){
    //-------------------------------------------------------------------------------------------
    //This method compares a case in which there are only two bordering values to a current value
    //if the difference between the current value and the other two values is greater than one,
    //false is returned to the calling code.
    //
    //-------------------------------------------------------------------------------------------
    
    bool result = true;
    
    int difference1 = std::abs(current-val1);
    int difference2 = std::abs(current-val2);
    
    if (difference1 > 1||difference2 > 1) {
        result = false;
        return result;
    }else return result;
}

bool checkValueThree(int current, int val1, int val2, int val3){
    //-------------------------------------------------------------------------------------------
    //This method compares a case in which there are three bordering values to a current value.
    //If the difference between the current value and any of the other three values is greater
    //than one, false is returned to the calling code.
    //-------------------------------------------------------------------------------------------
    
    bool result = true;
    
    int difference1 = std::abs(current-val1);
    int difference2 = std::abs(current-val2);
    int difference3 = std::abs(current-val3);
    
    if (difference1 > 1){
        return result = false;
    }
    else if (difference2>1) {
        return result = false;
    } else if (difference3>1) {
        return result = false;
    }else
        
        return result;
}

bool checkValueFour(int current, int val1, int val2, int val3, int val4){
    //-------------------------------------------------------------------------------------------
    //This method compares a case in which there are four bordering values to a current value.
    //If the difference between the current value and any of the other four values is greater
    //than one, false is returned to the calling code.
    //
    //-------------------------------------------------------------------------------------------
    
    bool result = true;
    
    int difference1 = std::abs(current-val1);
    int difference2 = std::abs(current-val2);
    int difference3 = std::abs(current-val3);
    int difference4 = std::abs(current-val4);
    
    if (difference1>1||difference2>1||difference3>1||difference4>1) {
        
        return result = false;
    }else
        
        return result;
}

string swapNumforDarkChar(int array){
    std::string result = " ";
    if(array== 0){
        result = " ";
    }
    else if(array== 1){
        result = ".";
    }
    else if(array== 2){
        result = ",";
    }
    else if(array== 3){
        result = "-";
    }
    else if(array== 4){
        result = "!";
    }
    else if(array== 5){
        result = "+";
    }
    else if(array== 6){
        result = "*";
    }
    else if(array== 7){
        result = "#";
    }
    else if(array== 8){
        result = "$";
    }
    else if(array== 9){
        result = "&";
    }
    return result;
}
