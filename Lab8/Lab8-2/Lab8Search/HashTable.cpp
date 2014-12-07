/*
 PROGRAM NAME: Program 8: External Hashing (Seperate Chaining)
 
 PROGRAMMER:   James Francis
 
 CLASS:        CSC 331.001, Fall 2014
 
 INSTRUCTOR:   Dr. Robert Strader
 
 DATE STARTED: November 17, 2014
 
 DUE DATE:     November 18, 2014
 
 PROGRAM PURPOSE:
 Definition of the Card Class

 
 VARIABLE DICTIONARY: in functions
 
 ADTs: none
 
 FILES USED: none
 
 SAMPLE INPUTS: none
 
 SAMPLE OUTPUTS: none
 
 
 ---------------------------------------------------------------------*/



#include "HashTable.h"

HashTable::HashTable(){
    //--------------------------------------
    // Default Constructor
    // Instantiates null nodes for the table
    //--------------------------------------
    for (int i = 0; i < 5; i++) {
        table[i] = NULL;
    }

}


void HashTable::populate(fstream& infile, int n) {
    //-----------------------------------------------------------------------
    //Preconditions: Calling code calls the HashTable populate function
    //
    //Postconditions: The hashtable object has an array of Node pointers populated
    //                  with NULL Nodes or Nodes containing values.
    //
    //Variables used:
    //              table: an array of Node pointers
    //              stars: delimiting string
    //              word, line: strings that contain a line of input and a word
    //              size, count: integer variables used for the size of a word
    //              and the current line count
    //-----------------------------------------------------------------------
    
    
    
    
    /*
        
    stringstream linestream(line);
    while (linestream>>word && word.compare(stars)!=0) {
            
            int index = HashTable::hashValue(word);
            Node* newNode = new Node((int)word.length(), word, NumberToString(count));
            insert(newNode, index, table, count);
            
        }
    
    while (getline(infile, line)) {
        search(line, table);
        cout << endl;
    }
     
    */
}

int HashTable::hashValue(int n){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code has passed a key, as an integer, to this function
    //
    //Postconditions: An integer value is returned to the calling code, representing
    //                 the passed Key's hash value.
    //
    //Variables used:
    //              position: hashvalue of the passed string
    //-----------------------------------------------------------------------
    
    int position = n%5;
    
    return position;
    
}

void HashTable::printTable(int n){
    //-----------------------------------------------------------------------
    //Preconditions: calling code passed an array of Node pointers to this function
    //
    //Postconditions: The hashtable is printed along with its seperate chains
    //
    //Variables used:
    //              current: Node pointer
    //
    //-----------------------------------------------------------------------
    
    
    for(int i = 0; i<5; i++){
        Node* current = table[i];
        
        if (current == NULL) {
            cout<<"Blank"<<endl;
        } else {
            cout<<i<< ": ";

            while (current != NULL ) {
                if (current==NULL) {
                    break;
                }else{
                cout<<current->getKey()<<"/"<<current->getOffset()<<" ";
                current = current->getNext();
            }
            }
            
            cout<<endl;
            cout<<endl;
        }
    }
    
    
}

void HashTable::insert(Node* newNode){
    //-----------------------------------------------------------------------
    //Preconditions: calling code has populated the passed parameters properly
    //
    //Postconditions: The passed node has been hashed into the table, or the
    //                line that the word was on was added to the a previously
    //                hashed Node containing the same word.
    //
    //Variables used:
    //              duplicate: boolean flag to determine if the passed value is
    //                          found in the hash table
    //              current: Node pointer
    //              newNode: node Pointer that contains a word to be hashed into
    //                          the table
    //              index: integer containing the hash value for the passed word
    //
    //              count: integer containing the line the word was input from
    //
    //-----------------------------------------------------------------------
    int index = (newNode->getKey()%5);

    if (table[index] == NULL) {
        
        table[index] = newNode;
        return;
    }
    
    else {
        
        Node *current = table[index];
        
        while (current->getNext() != NULL) {
                // scans the current chain until
                // the end of the current chain is reached
                    current = current->getNext();
                
            }
        
        current->setNext(newNode);
        // Assigns new node to be the
        // last node in the current chain
        }
    
    
    }


string HashTable::NumberToString ( int t )
{
    //-----------------------------------------------------------------------
    //Preconditions: calling code has passed an integer, t, to this function
    //
    //Postconditions: a string representation of the passed integer is returned
    //
    //Variables used:
    //              ss: stringstream object used to convert the passed integer
    //
    //-----------------------------------------------------------------------
    ostringstream ss;
    ss << t;
    return ss.str();
}

int HashTable::search(int n){
    //-----------------------------------------------------------------------
    //Preconditions: calling code has encountered a word to search the table for
    //
    //Postconditions: A success, along with lines the word was found on in the
    //               input file, or a failure to find, with the number of
    //               accesses to do so is returned to console
    //
    //Variables used:
    //              accesses: integer that counted the number of accesses to
    //                        the hash table
    //              word: string, word to be searched for in the table
    //              linestream: stringstream object, used to ensure escape
    //                          charcaters are removed from input string
    //              searchValue: integer, hash value of the passed word
    //-----------------------------------------------------------------------
    

    Node *current = table[(n%5)];
    
    while (current->getKey()!= 0) {
        
        if (n == current->getKey()) {
            return current->getOffset();
        }
        else {
            current = current->getNext();
        }
    }
    
    cout<< "Unable to find '"<<n<<" "<<endl;
    
    return 0;
}

void HashTable::createBinaryIndex(int numRecords){
    //--------------------------------------------------------------
    //Preconditions: number of records in the data file is passed by
    //                  the calling code
    //Postconditions: a binary file is created that has the same
    //                information as the data file
    //
    //Variables used: openfile: ofstream used to create the binary file
    //                item: reference to an Item object
    //--------------------------------------------------------------
    
    ofstream openFile;
    openFile.open("index.idx", ios::out|ios::binary);
    openFile.close();
    
    fstream myFile("index.idx", ios::out|ios::binary);
    int i = 0;
    for(i = 0; i<5;i++){
        
        Node* current = table[i];
        
        if (current == NULL) {
            
            Node newNode = *new Node(0,0);
            //following line moves the filepointer to the item's location in bytes on the list
            myFile.write(reinterpret_cast<const char *>(&newNode), sizeof(Node));
        
        }
        else {
            
            while (current != NULL ) {
                
                    
                    Node newNode = *new Node(current->getKey(), current->getOffset());
                    //following line moves the filepointer to the item's location in bytes on the list
                    myFile.write(reinterpret_cast<const char *>(&newNode), sizeof(Node));

                current = current->getNext();
                }
            
            }

        
        }
        
    myFile.close();
}
