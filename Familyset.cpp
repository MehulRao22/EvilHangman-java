#include "FamilySet.h"

FamilySet::FamilySet()
{
   iterCount = 0;
   dictionaries.begin();
   masterList.begin();
}

FamilySet::FamilySet(string file)
{
	ifstream myFile(file);
	
	iterCount = 0;
    string word;

    myFile >> word;
    if (!myFile) {
       cout << "file not found" << endl;
   }
    if (myFile.is_open()) {
       for (int i = 0; i < masterList.size(); i++) {
           masterList.push_back(word);
       }
   }

	myFile.close();
}

FamilySet::FamilySet(string file, int len)
{
   ifstream myFile(file);
	
   iterCount = 0;
   vector<string> temp_list;
   string word;

  
   if (!myFile) {
       cout << "file not found" << endl;
   }
   
   while (myFile >> word) {
       temp_list.push_back(word);
   }

   if (myFile.is_open()) {
       for (int i = 0; i < temp_list.size(); i++) {
           // looks for the appropriate sizes in the dictionary
           if (temp_list[i].size() == len) {
               masterList.push_back(temp_list[i]);
           }

       }
   }

	myFile.close();
}

FamilySet::~FamilySet()
{
	
}

void FamilySet::filterFamilies(string letter, string guessPattern) 
{
	// The first step is to clear dictionaries to prepare
	// for the new filter based on the letter and pattern

	// For each word in the master list, you need to classify
	// what family is part of based on the letter and pattern.
	// If you can find letter in the word, then we need to
	// create the new family.
	// Otherwise, if the letter does not exist in the word, then
	// the family is simply the guessPattern.
	// Example 1:Suppose letter is "a", word is "ally", and 
	//           guessPattern is ***y.
	//           In this case, the family is a**y. Once this
	//           is determined, then "ally" can be added to
	//           the "a**y" dictionary.
	// Example 2:Suppose letter is "a", word is "cool", and 
	//           guessPattern is ***y.
	//           In this case, the family is ***y and "cool"
	//           would be added to the ***y dictionary.	
	
	 vector<string> new_master_list;
   // to get the words with the target letter specified into the dictionary.
  
   for (int word = 0; word < masterList.size(); word++) {
    
       for (int let = 0; let < masterList[word].size(); let++) {
           // convert the letter into char for comparison purposes
           char character = letter[0];
      
           // checking for individual characters in the word against target letter
           if (character == masterList[word][let]) {
               // new master list now has the words with target letter
               string new_guess_pattern = guessPattern;

               new_master_list.push_back(masterList[word]);
               new_guess_pattern[let] = character;

               dictionaries.insert({new_guess_pattern,new_master_list });
          
               new_master_list.clear();
           }
           else {
               new_master_list.push_back(masterList[word]);
               dictionaries.insert({ guessPattern,new_master_list});
               new_master_list.clear();
           }
          
       }
   }
}
}

void FamilySet::setFamily(string family)
{
	// This updates the master list.  The new master list
	// should contain the words within the dictionary for family.
	// dictionaries should be cleared after updating the master list.
   masterList = dictionaries[family];
   dictionaries.clear();
   
}

vector<string> FamilySet::getFamily(string family)
{
	// Returns the dictionary associated with family.

	return dictionaries[family];
}

string FamilySet::getRandomWord()
{
	// Returns random word from master list
	return string();
}

int FamilySet::numWords()
{
	// This should return the number of words in the master list
	return 0;
}

int FamilySet::numFamilies()
{
	// This should return how many families are in dictionaries
	// (Note FAMILIES, not words)
	return 0;
}

void FamilySet::resetFamilyIter()
{
	// The iterator should return each family from
	// dictionaries (Note, it should returns the family,
	// not the words).
	// The resetFamilyIter function should be starting
	// iterator for dictionaries.
	
    family_iterator = dictionaries.begin();
}

bool FamilySet::hasNext() {
	// Returns true as long as there is another family to return
	return true;
}

string FamilySet::getNextFamily()
{
	// Returns the next family using the unordered_map iterator.

   ++family_iterator;
   return family_iterator->first;
}

int FamilySet::familySize(string family)
{
	// Returns the size of the dictionary of family.

	return 0;
}
