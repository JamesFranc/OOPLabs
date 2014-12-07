 PROGRAM NAME: Program 5: Indexed Files
 
 DATE STARTED: October 21, 2014
 
 DUE DATE:     October 28, 2014
 
 PROGRAM PURPOSE:
 
* Create a blank binary file
* Read in "inventory" updates from prog5.dat to Item objects
* Write the Item objects to the previously created binary file
* Print to console the item record in the file going from one item to the next based on their nextItem variable
 
 
 VARIABLE DICTIONARY:
 
- indexer: CreateIndex object that will create an index of records within the data file
- searcher: SearchIndex object that will perform search operations
- key: String holds the value of the key to be searched for
- fileName: String holds the value of the index file

 SAMPLE INPUTS:
 
 search 12382 prog5.idx
 
 SAMPLE OUTPUTS: 
 
 12382 Item09 62 41.37
