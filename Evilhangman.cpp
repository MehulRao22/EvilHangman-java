#include <string>
#include <iostream>
#include "FamilySet.h"
using namespace std;

bool debug;	// Global variable to indicate debugging

bool PromptYesNoMessage(string msg) {
	while (true) {
		cout << msg << "(y/n) ";
		string response;
		cin >> response;
		if (response == "y")
			return true;
		if (response == "n")
			return false;
		cout << "Please enter y or n..." << endl;
	}
}

int PromptGuesses() 
{
	while (true) {
		int len;
		cout << "Please enter how many guesses: ";
		cin >> len;
		if (len > 0)
			return len;
	}
}

int PromptWordLength()
{
	int len;

	cout << "choose your word length: ";
    cin >> len;
   
	return len;
}

string PromptGuess(string& guessedLetters)
{
	string guess = "";

    cout << "What will be your guess?";
    cin >> guess;
	return guess;
}

string ChooseFamily(string guess, string guessProgress, FamilySet& set) 
{
	// filter families by guess and guessProgress/guessPattern

	string maxFamily;

	/* 
	 * Use the iterator to loop through each family and
	 * figure out the biggest family size.
	 * Return this family
	 */

	return maxFamily;
}

bool isWin(string guessedProgress)
{
	return guessedProgress.find("*") == string::npos;
}

void PlayEvilHangman(string file) 
{ 	set<char> uL; // uL are the letters that have been used
	// Prompt user for word length and number of guesses

	// Load dictionary based on word length
	cout << "Loading dictionary..." << endl;
	FamilySet families(file, len);

	string guessedLetters = "";
	string correctlyGuessed = "";	// correctly guessed positions
	for (int i = 0; i < len; i++)
		guessProgress += "*";

	// Actual game loop...
	while (true) { 
	
	// Letting the player guess a letter
	char newGuess = askForLetter(uL);
	
	uL.insert(newGuess);

	// Divide all words in the dictionary into families
	filterFamilies( newGuess, guessPatern)
	
	ChooseFamily(newGuess, currentWord, families);

	// Pick the family with the highest amount of words
	
	string biggestFamily;
	
	int biggestSize = 0;
	
	for () {
	string familyName = family.first;
	int familySize = family.second;

	if (familySize > biggestSize) {
	
	biggestFamily = familyName;
	biggestSize = familySize;
	}
	}

	// Decrease the amount of remaining guesses if the player didn't find a letter
	bool mCorrectGuess = currentWord != biggestFamily;
	
	if (!mCorrectGuess)
	guesses--;

	currentWord = biggestFamily;

	
		
	

		if (isWin(guessProgress)) {
			cout << "Wow! You won!" << endl;
			break;
		}

		if (guessesLeft <= 0) {
			cout << "Wow... you are a really bad guesser..." << endl;
			cout << "The mystery word was " << endl;
			break;
		}
	}
}

int main()
{
	string file; 
	cout << "Enter file: ";
	cin >> file;				// Can comment out this line and include the following while developing
	//file = "dictionary.txt";  // Convenient to hard code while developing
	
	while (true) {
		debug = PromptYesNoMessage("Turn debugging on?");
		PlayEvilHangman(file);
		if (!PromptYesNoMessage("Would you like to play again ?"))
			break;
	}
}
