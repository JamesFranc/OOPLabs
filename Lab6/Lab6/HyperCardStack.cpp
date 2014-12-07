/*
 PROGRAM NAME: HyperCardStack.cpp
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 1, 2014
 
 DUE DATE:     November 6, 2014
 
 PROGRAM PURPOSE:
 This file contains the class definition for the HyperCardStack Class.
 
 VARIABLE DICTIONARY:
 
 
 ADTs: HyperCardStack
 
 FILES USED: none
 
 
 ---------------------------------------------------------------------*/

#include "HyperCardStack.h"

HyperCardStack::HyperCardStack(){
    //---------------------------
    // Default Constructor
    //---------------------------
    Current = new Node;
    Tail = new Node;
    count = 0;
}

void HyperCardStack::insert(int n, string str){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code calls the HyperCardStack insert function
    //
    //Postconditions: A new Card object was added as part of a Node within
    //              the HyperCardStack
    //
    //Variables used:
    //              count: integer that stores the current count of nodes in the
    //                 HyperCardStack
    //              newCard: object containing the new Card to be added
    //-----------------------------------------------------------------------
    
    
    Card newCard = Card(n, str);
    cout<<"Inserting: "<<newCard.getKey()<<newCard.getEntry();
    if (count == 0) {
        emptyInsert(newCard);
        count++;
    }else{
        stdInsert(newCard);
        
    count++;
    }
    
    cout<<endl;
}

void HyperCardStack::remove(int n){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code calls the HyperCardStack remove function
    //
    //Postconditions: The node that contains the integer passed by the calling
    //                  code has been removed from the HypercardStack
    //
    //Variables used:
    //              k: integer that stores the current count of nodes in the
    //                 HyperCardStack
    //              ptr: Node that maintains a reference to the Current Node's
    //                 location, prior to printing all the requested data
    //                Tail: Node that points to the last Card object
    //                Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    
    int k = count;
    Node* ptr;
    ptr = Current;
    
    if (count ==1) {
        Current = NULL;
        Tail = NULL;
    }
    
    while (ptr->next->data.getKey() != n && k>0) {
        ptr = ptr->next;
        k--;
    }
    if (ptr->next->data.getKey() !=n) {
        cout<< "Key not found in the list.";
    }else
        
    cout<<"Removing: "<<ptr->next->data.getKey()<<ptr->next->data.getEntry();
    cout <<endl;
    ptr->next = ptr->next->next;
    count--;
    Current = ptr;

}

void HyperCardStack::traverse(){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code calls the HyperCardStack traverse function
    //
    //Postconditions: All facts contained in the Card objects, referenced by nodes:
    // beginning with the Current Node and ending with the node before Current
    //
    //Variables used: ptr: Node that maintains a reference to the Current Node's
    //                 location, prior to printing all the requested data
    //                Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    Node *ptr = new Node;
    ptr = Current;
    cout<<"Traversing: ";

    do {
            Current -> data.display();
            Current = Current -> next;
            
        }while(Current != ptr);
    cout.clear();
    cout<<endl;
    Current = ptr;
}

void HyperCardStack::forward(){
    //-----------------------------------------------------------------------
    //Preconditions: The calling code has invoked the forward method
    //
    //Postconditions: The current pointer now references the node at
    //                 Current->next
    //
    //Variables used:
    //                  Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    cout<<"Moving the current pointer forward.";
    cout<<endl;

    Current = Current->next;
}

void HyperCardStack::home(){
    //-----------------------------------------------------------------------
    //Preconditions: The calling code has invoked the home method
    //
    //Postconditions: The current pointer now references the node at
    //                 Tail->next
    //
    //Variables used:
    //                  Tail: Node that points to the last Card object
    //                  Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    cout<<"Moving the current pointer home.";
    cout<<endl;
    Current = Tail->next;
}

void HyperCardStack::emptyInsert(Card newCard){
    //-----------------------------------------------------------------------
    //Preconditions: a new Card object has been instantiated by the
    //               calling code
    //
    //Postconditions: The passed Card object has been added as the
    //                Tail element in the HyperCardStack
    //
    //Variables used:   newCard: Reference to a Card Object
    //                  temp: Node containing a reference to newCard
    //                  Tail: Node that points to the last Card object
    //                  Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    
    Node *temp = new Node;
    temp->data = newCard;
    temp->next = Tail;
    Tail = temp;
    Tail->next = Tail;
    
    Current = Tail;
    Current->next = Tail;


}

void HyperCardStack::stdInsert(Card newCard){
    //-----------------------------------------------------------------------
    //Preconditions: a new Card object has been instantiated by the
    //               calling code
    //
    //Postconditions: The passed Card object has been added as the
    //                Tail element in the HyperCardStack
    //
    //Variables used:   newCard: Reference to a Card Object
    //                  temp: Node containing a reference to newCard
    //                  Tail: Node that points to the last Card object
    //                  Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    
    if(Current == Tail){
    Node  *temp = new Node;//new node ptr
    
    temp->data = newCard;// newCard object is referenced to by temp node pointer
    temp->next = Tail->next;// Current
    Current->next = temp;
    Current = temp;
    Tail = Current;

    
}
    else {
        Node  *temp = new Node;//new node ptr

        temp->data = newCard;// newCard object is referenced to by temp node pointer
        temp->next = Current->next;// Current
        Current->next = temp;


    }
}

void HyperCardStack::print(){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code calls this Node's object's print method
    //
    //Postconditions: The requested Node's object's fact is displayed
    //
    //Variables used:
    //                Current: Node that points to the current Card object
    //-----------------------------------------------------------------------
    cout<<"Printing: ";
    Current->data.display();
    cout<<endl;

}
