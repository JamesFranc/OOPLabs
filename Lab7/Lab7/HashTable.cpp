/*
 PROGRAM NAME: Program 7: Hashing (Seperate Chaining)
 
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
    //---------------------------
    // Default Constructor
    //---------------------------
    
    setSuccess(0);
    setFailed(0);
}


void HashTable::populate(fstream& infile) {
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
    
    
    Node* table[23];
    
    for (int i = 0; i < 23; i++) {
        table[i] = NULL;
    }
    
    string stars = "**********";
    
    
    string word;
    string line;
    int size;
    int count = 0;
    
    while (line.compare(stars)!=0) {
        getline(infile, line);
        count++;
        word='\0';
        size = 0;
        
        
        stringstream linestream(line);
        while (linestream>>word && word.compare(stars)!=0) {
            
            int index = HashTable::hashValue(word);
            Node* newNode = new Node((int)word.length(), word, NumberToString(count));
            insert(newNode, index, table, count);
            
        }
    }
    
    
    while (getline(infile, line)) {
        search(line, table);
        cout << endl;
    }
    
}

int HashTable::hashValue(string str){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code has passed a word, as a string, to this function
    //
    //Postconditions: An integer value is returned to the calling code, representing
    //                 the passed word's hash value.
    //
    //Variables used:
    //              first: integer, offset of first character in the word from 'a'
    //              last: integer, offset of last character in the word from 'a'
    //              position: hashvalue of the passed string
    //-----------------------------------------------------------------------
    
    int first = str.at(0) - 97;
    int last = str.at(str.size()-1) - 97;
    
    
    int position = (int) (first*256+last)%23;
    
    return position;
    
}

void HashTable::printTable(Node* table[]){
    //-----------------------------------------------------------------------
    //Preconditions: calling code passed an array of Node pointers to this function
    //
    //Postconditions: The hashtable is printed along with its seperate chains
    //
    //Variables used:
    //              current: Node pointer
    //
    //-----------------------------------------------------------------------
    
    
    for(int i = 0; i<23; i++){
        Node* current = table[i];
        
        if (current == NULL) {
            cout<<endl;
        }
        else{
            while (current!= NULL) {
                cout<<current->getWord()<<" ";
                current = current->getNext();
            }
            cout<<endl;
            cout<<endl;
        }
    }
    
    
}

void HashTable::insert(Node* newNode, int index, Node* table[], int count){
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
    
    
    
    bool duplicate = false;
    
    if (table[index]==NULL) {
        table[index] = newNode;
        
    } else {
        Node *current = table[index];
        
        
        if (scanChain(current, newNode->getWord())) {
            
            current->addLine(NumberToString(count));
            duplicate = true;
            
        }
        else{
            
            while (current->getNext() != NULL) {
                if (scanChain(current, newNode->getWord())) {
                    
                    current->addLine(NumberToString(count));
                    duplicate = true;
                    break;
                }
                else
                    current = current->getNext();
                
            }
        }
        
        if (duplicate) {
            newNode = NULL;
            current = NULL;
        }else{
            current->setNext(newNode);
        }
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

bool HashTable::scanChain(Node* current, string word){
    //-----------------------------------------------------------------------
    //Preconditions: Calling code has encountered a seperate chain in the
    //               hash table
    //
    //Postconditions: a string representation of the passed integer is returned
    //
    //Variables used:
    //              result: boolean flag that identifies if a duplicate word is
    //                      encountered
    //
    //-----------------------------------------------------------------------
    
    bool result = false;
    while (current!=NULL) {
        
        if (word.compare(current->getWord())==0) {
            result = true;
            break;
        }
        else current = current->getNext();
    }
    return result;
}

void HashTable::search(string line, Node* table[]){
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
    
    
    int accesses= 1;
    string word;
    stringstream linestream (line);
    linestream >>word;
    int searchValue = hashValue(word);
    Node *current = table[searchValue];
    
    while (current!=NULL) {
        
        if (word.compare(current->getWord())==0) {
            setSuccess(accesses);
            cout<< "Found '"<<word<<"' with "<<accesses<<" access(es)"<<endl;
            cout<< word <<" appears on line(s): "<< current->getLines()<<endl;
            return;
        }
        else {
            current = current->getNext();
            accesses++;
        }
    }
    
    cout<< "Unable to find '"<<word<<"' with "<<accesses<<" access(es)."<<endl;
    
    setFailed(accesses);
    return;
}


void HashTable::hashingReport() {
    //-----------------------------------------------------------------------
    //Preconditions: calling code has finished searching
    //
    //Postconditions: Average number of successful accesses, failed accesses,
    //                 and avwrage total accessess are printed to screen
    //
    //Variables used:
    //              successRate: double, stores the average success rate
    //              failRate: double, stores the average fail rate
    //              totalRetrievalRate: double, stores the overall average
    //-----------------------------------------------------------------------
    
    cout<<"---Averages rounded to the nearest integer---"<<endl;
    
    double successRate = floor(((double)this->getSuccess()/(double)successCount)+.5);
    
    cout<<"Average number of accesses for successful retrieval: "<< successRate<<endl;
    
    
    cout<<endl;
    
    double failRate = floor(((double)this->getFailed()/(double)this->failedCount)+.5);
    
    cout<<"Average number of accesses for unsuccessful retrieval: "<< failRate <<endl;
    
    cout<<endl;
    double totalRetrievalRate = floor(((this->getSuccess()+this->getFailed())/(this->successCount))+.5);
    
    cout<<"Average number of accesses over total retrievals: "<< totalRetrievalRate <<endl;
}


//--------------------
//   SETTERS
//--------------------
void HashTable::setSuccess(int n){
    success +=n;
    successCount++;
}

void HashTable::setFailed(int n){
    failed +=n;
    failedCount++;
}

//--------------------
//   GETTERS
//--------------------
int HashTable::getSuccess(){
    return success;
}

int HashTable::getFailed(){
    return failed;
}

