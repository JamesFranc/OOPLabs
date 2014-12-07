//
//  p3.h
//  p3
//
//  Created by James Francis II on 10/5/14.
//  Copyright (c) 2014 James Francis II. All rights reserved.
//

#ifndef p3
#define p3
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX_HAND_SIZE 13

using namespace std;


class Card{
    
public:
    Card();
    Card(string token);
    int getValue();
    char getSuit();
    bool operator==(const Card &t);
    
    
private:
    int value;
    char suit;
    void setValue(char c);
    void setSuit(char f);
    bool isSuitValid(char f);
    bool isValueValid(char f);
    
};



class Hand{
    
public:
    Card myHand[20];
    string Clubs[MAX_HAND_SIZE];
    string Diamonds[MAX_HAND_SIZE];
    string Hearts[MAX_HAND_SIZE];
    string Spades[MAX_HAND_SIZE];
    int clubsCounter;
    int diamCounter;
    int heartCounter;
    int spadeCounter;

    Hand();
    Hand(string line);
    void displayHand();
    int scoreHand();
    
private:
    void mySort();
    void setCard(int n, string token);
    int isHandValid();
    void clearHand();
    void setToSuitArray(Card temp);
    void assignToClubs(int v);
    void assignToDiamonds(int v);
    void assignToHearts(int v);
    void assignToSpades(int v);
    void mySuitSort(string array[]);
};







#endif

