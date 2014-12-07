/*
 PROGRAM NAME: Program 3: BRIDGE
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: September 5, 2014
 
 DUE DATE:     September 7, 2014
 
 PROGRAM PURPOSE:
 This file contains the class definitions for Hand and Card objects.
 
 VARIABLE DICTIONARY:
 myHand[]: an array used to house references to Card objects
 clubsCounter: integer used to count the number of diamonds in a hand
 diamCounter: integer used to count the number of diamonds in a hand
 heartCounter: integer used to count the number of diamonds in a hand
 spadeCounter: integer used to count the number of diamonds in a hand
 item: String used to contain the current Value and Suit of a Card
 
 
 ADTs: Arrays
 
 FILES USED: NONE
 
 
 SAMPLE INPUTS: NONE
 SAMPLE OUTPUTS: NONE
 
 ---------------------------------------------------------------------*/



#include "p3.h"
Hand::Hand(){
    //-----------------------------------------------------------------------------
    //Default Hand Constructor
    //-----------------------------------------------------------------------------
    
}

Hand::Hand(string line){
    //-----------------------------------------------------------------------------
    // Hand constructor that catches errors thrown by invalid hands
    //-----------------------------------------------------------------------------
    
    clubsCounter = 0;
    diamCounter = 0;
    heartCounter = 0;
    spadeCounter = 0;
    try{
        stringstream linestream(line);
        string item;
        int i = 0;
        while (getline(linestream, item, ' '))
        {
            // "Tokenizes" the input line from the calling code
            // Each token is a potential Card
            // supposed to contain a Value followed by a Suit
            
            if (i< MAX_HAND_SIZE+1) {
                setCard(i, item);
                setToSuitArray(myHand[i]);
                i++;
            }
            
        }
        
        displayHand();
        
        
    }
    catch (int e){
        if (e == 1) {
            cout<<"Error in setting the Suit for a card, hand is invalid."<<endl<<endl;
            clearHand();
            
        }
        if (e == 2) {
            cout<<"Error in setting the Value for a card, hand is invalid."<<endl<<endl;
            clearHand();
            
        }
        if (e == 3){
            cout << "Too few cards in this hand, hand is invalid."<<endl<<endl;
            clearHand();
            
        }
        if (e == 4){
            cout << "Too many cards in this hand, hand is invalid."<<endl<<endl;
            clearHand();
            
        }
        if (e == 5){
            cout << "Duplicate Cards Detected in Hand, hand is inavlid."<<endl<<endl;
            clearHand();
            
        }
        
        
        
    }
    
}


void Hand::setCard(int n, string token){
    //-----------------------------------------------------------------------------
    // Populates the value at myHand[n] with a Card(Value,Suit)
    //-----------------------------------------------------------------------------
    myHand[n] = Card(token);
    
}


void Hand::displayHand(){
    //-----------------------------------------------------------------------------
    // Displays the current hand, this method checks hand validity and throws
    // errors if the hand is too short, too long, or duplicates exist
    // Displays each suit's
    //-----------------------------------------------------------------------------
    
    if (isHandValid()==3) {
        clearHand();
        throw 3;
        
    }
    if (isHandValid()==4) {
        clearHand();
        throw 4;
        
    }
    if (isHandValid()==5) {
        clearHand();
        throw 5;
    }
    if (isHandValid() == 6){
        cout<<endl;
        
        printf("%s", "CLUBS:   ");
        mySuitSort(Clubs);
        for (int i = 0; i < MAX_HAND_SIZE; i++) {
            if (Clubs[i].length() != 0) {
                printf(" %s ",Clubs[i].c_str());
            }
        }
        cout<<endl;
        printf("%s", "DIAMONDS:");
        mySuitSort(Diamonds);
        
        for (int i = 0; i < MAX_HAND_SIZE; i++) {
            if (Diamonds[i].length() != 0) {
                printf(" %s ",Diamonds[i].c_str());
            }
        }
        cout<<endl;
        printf("%s", "HEARTS:  ");
        
        for (int i = 0; i< MAX_HAND_SIZE; i++) {
            mySuitSort(Hearts);
            if (Hearts[i].length() != 0) {
                printf(" %s ",Hearts[i].c_str());
                mySuitSort(Hearts);
                
            }
        }
        cout<<endl;
        printf("%s", "SPADES:  ");
        
        for (int i = 0; i< MAX_HAND_SIZE; i++) {
            mySuitSort(Spades);
            
            if (Spades[i].length() != 0) {
                printf(" %s ",Spades[i].c_str());
                mySuitSort(Spades);
                
            }
            
        }
        
        cout<<"\n\nPoints = "<<scoreHand()<<endl;
        
        cout<<endl;
        clearHand();
    }
}
int Hand::isHandValid(){
    //-----------------------------------------------------------------------------
    // Checks the current hand and returns values associated with illegal hands
    //-----------------------------------------------------------------------------
    
    int j = 0;
    while (myHand[j].getSuit() != '\0') {
        
        //Counts the number of Cards in the current hand
        j++;
        
    }
    if (j< MAX_HAND_SIZE) {
        
        //Returns a 3 to the calling code if too few cards are present in the hand
        return 3;
    }
    if (j > MAX_HAND_SIZE){
        
        //Returns a 4 to the calling code if too many cards are present in the hand
        return 4;
    }
    
    for(int i = 0; i < MAX_HAND_SIZE; i++){
        for(int j = i+1; j < MAX_HAND_SIZE; j++){
            
            //Returns a 5 to the calling code if any duplicate cards are encountered
            if (myHand[i] == myHand[j]){
                return 5;
                break;
            }
        }
    }
    
    return 6;
}

int Hand::scoreHand(){
    //-----------------------------------------------------------------------------
    // Scores the current hand
    //-----------------------------------------------------------------------------
    
    int worth = 0;
    for (int i = 0; i < MAX_HAND_SIZE; i++){
        if (myHand[i].getValue() == 27) {
            //Adds 3 to the worth of the hand if a King is encountered
            
            worth+=3;
        }
        if (myHand[i].getValue() == 26) {
            //Adds 1 to the worth of the hand if a Jack is encountered
            
            worth+=1;
        }
        if (myHand[i].getValue() == 33) {
            //Adds 2 to the worth of the hand if a Queen is encountered
            
            worth+=2;
        }
        if (myHand[i].getValue() == 17) {
            //Adds 4 to the worth of the hand if an Ace is encountered
            
            worth+=4;
        }
    }
    
    
    //Void Scoring Begins
    
    if (clubsCounter==0) {
        worth+=3;
    }
    if (diamCounter==0) {
        worth+=3;
    }
    if (heartCounter==0) {
        worth+=3;
    }
    if (spadeCounter==0) {
        worth+=3;
    }//End Void Scoring
    
    
    //Single Scoring Begins
    
    if (clubsCounter==1) {
        worth+=2;
    }
    if (diamCounter==1) {
        worth+=2;
    }
    if (heartCounter==1) {
        worth+=2;
    }
    if (spadeCounter==1) {
        worth+=2;
    }//End Singleton Scoring
    
    
    //Doubleton Scoring Begins
    
    if (clubsCounter==2) {
        worth+=1;
    }
    if (diamCounter==2) {
        worth+=1;
    }
    if (heartCounter==2) {
        worth+=1;
    }
    if (spadeCounter==2) {
        worth+=1;
    }//End Doubleton Scoring
    
    
    //Long Scoring Begins
    
    if (clubsCounter>5) {
        worth+= (clubsCounter-5);
    }
    if (diamCounter>5) {
        worth+= (diamCounter-5);
    }
    if (heartCounter>5) {
        worth+=(heartCounter-5);
    }
    if (spadeCounter>5) {
        worth+=(spadeCounter-5);
    }//End Long Scoring
    
    
    return worth;
}

void Hand::clearHand(){
    //-----------------------------------------------------------------------------
    // Clears the references to any objects within the myHand array
    // Assigns null values to each suit array.
    //-----------------------------------------------------------------------------
    
    for(int i = 0; i< MAX_HAND_SIZE; i++){
        myHand[i] = *new Card();
        Clubs[i] = '\0';
        Diamonds[i] = '\0';
        Hearts[i] = '\0';
        Spades[i] = '\0';
        
    }
}

void Hand::mySuitSort(string arr[]){
    //-----------------------------------------------------------------------------
    // Bubble Sort that orders all the values within an Array in Descending order
    //-----------------------------------------------------------------------------
    
    string temp;
    
    for(int i = 0; i < MAX_HAND_SIZE; i++)
    {
        for(int j = 0;j < MAX_HAND_SIZE - 1; j++)
        {
            if(arr[j] < arr[j+1])
            {
                //we need to swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            if(arr[j+1]=="A"){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            if(arr[j+1]=="K" && arr[j]=="Q"){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
    }
}


Card::Card(){
    //-----------------------------------------------------------------------------
    // Default Card Constructor
    //-----------------------------------------------------------------------------
    value = -1;
    suit = '\0';
    
}

Card::Card(string token){
    //-----------------------------------------------------------------------------
    // Card Constructor that accepts a string containing: value and suit
    //-----------------------------------------------------------------------------
    value = -1;
    suit = '\0';
    //cout<<"Creating Card: "<<token[0]<<" "<<token[1]<<endl;
    setValue(token[0]);
    setSuit(token[1]);
    
}

//-----------------------------------------------------------------------------
// --------------BEGIN GETTERS AND SETTERS-------------------------------------
//-----------------------------------------------------------------------------
int Card::getValue(){
    return value;
}
char Card::getSuit(){
    return suit;
}
void Card::setValue(char c){
    
    if (isValueValid(c)) {
        
        value = c -'0';
    }
    else throw 2;
}
void Card::setSuit(char f){
    if (isSuitValid(f)) {
        suit = f;
    }else throw 1;
    
}
//-----------------------------------------------------------------------------
// --------------END GETTERS AND SETTERS---------------------------------------
//-----------------------------------------------------------------------------


bool Card::operator==(const Card &t){
    //-----------------------------------------------------------------------------
    // Overloaded == operator for the Card class, returns true if current card and
    // the card passed reference to a card are equal
    //-----------------------------------------------------------------------------
    
    if (value == t.value && suit == t.suit) {
        return true;
    }
    
    return false;
}

bool Card::isSuitValid(char f){
    //-----------------------------------------------------------------------------
    // Accepts a character representing a Card's suit, if the suit is valid true
    // is returned, else false is returned
    //-----------------------------------------------------------------------------
    
    
    switch (f) {
        case 'C':
            return true;
            break;
        case 'S':
            return true;
            break;
        case 'H':
            return true;
            break;
        case 'D':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool Card::isValueValid(char f){
    //-----------------------------------------------------------------------------
    // Accepts a character representing a Card's value, if the valus is valid true
    // is returned, else false is returned
    //-----------------------------------------------------------------------------
    
    switch (f) {
        case '2':
            return true;
            break;
        case '3':
            return true;
            break;
        case '4':
            return true;
            break;
        case '5':
            return true;
            break;
        case '6':
            return true;
            break;
        case '7':
            return true;
            break;
        case '8':
            return true;
            break;
        case '9':
            return true;
            break;
        case 'T':
            return true;
            break;
        case 'J':
            return true;
            break;
        case 'Q':
            return true;
            break;
        case 'K':
            return true;
            break;
        case 'A':
            return true;
            break;
            
        default:
            return false;
            break;
    }
}

void Hand::setToSuitArray(Card temp){
    //-----------------------------------------------------------------------------
    // Accepts a valid Card object representing a newly created Card object
    // Assigns the card value to the first free index in the appropriate Suit array
    //-----------------------------------------------------------------------------
    
    switch (temp.getSuit()) {
        case 'C':
            assignToClubs(temp.getValue());
            break;
        case 'D':
            assignToDiamonds(temp.getValue());
            break;
        case 'H':
            assignToHearts(temp.getValue());
            break;
        case 'S':
            assignToSpades(temp.getValue());
            break;
        default:
            break;
    }
}

void Hand::assignToClubs(int v){
    //----------------------------------------------------------------------------------
    // Assigns a String representation of v to the first free index to the Clubs array
    //----------------------------------------------------------------------------------
    
    clubsCounter++;
    
    if(v<=9){
        int i = 0;
        while (Clubs[i].length() != 0) {
            i++;
        }
        string value;
        ostringstream convert;
        convert << v;
        value = convert.str();
        Clubs[i] = value;
    }
    else if(v == 36){
        int i =0;
        while (Clubs[i]!="\0") {
            i++;
        }
        Clubs[i] = "10";
    }
    else if(v == 27){
        int i =0;
        while (Clubs[i]!="\0") {
            i++;
        }
        Clubs[i] = "K";
    }
    else if(v == 26){
        int i =0;
        while (Clubs[i]!="\0") {
            i++;
        }
        Clubs[i] = "J";
    }
    else if(v == 33){
        int i =0;
        while (Clubs[i]!="\0") {
            i++;
        }
        Clubs[i] = "Q";
    }
    else if(v == 17){
        int i =0;
        while (Clubs[i]!="\0") {
            i++;
        }
        Clubs[i] = "A";
    }
}
void Hand::assignToDiamonds(int v){
    //-----------------------------------------------------------------------------------
    // Assigns a String representation of v to the first free index to the Diamonds array
    //-----------------------------------------------------------------------------------
    
    diamCounter++;
    
    if(v<=9){
        int i = 0;
        while (Diamonds[i].length() != 0) {
            i++;
        }
        string value;
        ostringstream convert;
        convert << v;
        value = convert.str();
        Diamonds[i] = value;
    }
    else if(v == 36){
        int i =0;
        while (Diamonds[i]!="\0") {
            i++;
        }
        Diamonds[i] = "10";
    }
    else if(v == 27){
        int i =0;
        while (Diamonds[i]!="\0") {
            i++;
        }
        Diamonds[i] = "K";
    }
    else if(v == 26){
        int i =0;
        while (Diamonds[i]!="\0") {
            i++;
        }
        Diamonds[i] = "J";
    }
    else if(v == 33){
        int i =0;
        while (Diamonds[i]!="\0") {
            i++;
        }
        Diamonds[i] = "Q";
    }
    else if(v == 17){
        int i =0;
        while (Diamonds[i]!="\0") {
            i++;
        }
        Diamonds[i] = "A";
    }
}
void Hand::assignToHearts(int v){
    //-----------------------------------------------------------------------------------
    // Assigns a String representation of v to the first free index to the Hearts array
    //-----------------------------------------------------------------------------------
    
    heartCounter++;
    if(v<=9){
        int i = 0;
        while (Hearts[i].length() != 0) {
            i++;
        }
        string value;
        ostringstream convert;
        convert << v;
        value = convert.str();
        Hearts[i] = value;
    }
    else if(v == 36){
        int i =0;
        while (Hearts[i]!="\0") {
            i++;
        }
        Hearts[i] = "10";
    }
    else if(v == 27){
        int i =0;
        while (Hearts[i]!="\0") {
            i++;
        }
        Hearts[i] = "K";
    }
    else if(v == 26){
        int i =0;
        while (Hearts[i]!="\0") {
            i++;
        }
        Hearts[i] = "J";
    }
    else if(v == 33){
        int i =0;
        while (Hearts[i]!="\0") {
            i++;
        }
        Hearts[i] = "Q";
    }
    else if(v == 17){
        int i =0;
        while (Hearts[i]!="\0") {
            i++;
        }
        Hearts[i] = "A";
    }
}
void Hand::assignToSpades(int v){
    //-----------------------------------------------------------------------------------
    // Assigns a String representation of v to the first free index to the Spades array
    //-----------------------------------------------------------------------------------
    
    spadeCounter++;
    
    if(v<=9){
        
        int i = 0;
        while (Spades[i].length() != 0) {
            i++;
        }
        string value;
        ostringstream convert;
        convert << v;
        value = convert.str();
        
        Spades[i] = value;
    }
    else if(v == 36){
        int i =0;
        while (Spades[i]!="\0") {
            i++;
        }
        Spades[i] = "10";
    }
    else if(v == 27){
        int i =0;
        while (Spades[i]!="\0") {
            i++;
        }
        Spades[i] = "K";
    }
    else if(v == 26){
        int i =0;
        while (Spades[i]!="\0") {
            i++;
        }
        Spades[i] = "J";
    }
    else if(v == 33){
        int i =0;
        while (Spades[i]!="\0") {
            i++;
        }
        Spades[i] = "Q";
    }
    else if(v == 17){
        int i =0;
        while (Spades[i]!="\0") {
            i++;
        }
        Spades[i] = "A";
    }
}




