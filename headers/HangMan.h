#include <string>
#include <vector>
#include "FileReader.h"
/**
* Class that defines the game.
*/
using namespace std;
class HangMan
{
private:
	string word; // word that has to be guessed
	vector<char> wrongs;  // Letters that the player has choosed and aren't in the word
	vector<char> correct; // Letters that the player has choosed and are in the word
	int attempts = 0;     // Number of letters that the player have failed to guess
	bool found = false;   // has the word been guessed?
	FileReader file;      // FileReader object that contains all the letters that can be guessed

	/**
	* this method return the actual state of the word that is being guessed
	* @return string with the state of the word
	*/
	string wordGuessed(); 

public:
	/**
	* Constructor
	* @Param nameFile --> Name of the file that contains all the words that can be guessed
	*/
	HangMan(string nameFile);

	/**
	* Checks if a letter is in the word that has to be guessed
	* @param  letter --> the letter that is checked
	* @return if the letters is in the word or not
	*/
	bool hasLetter(char letter);

	/**
	* Number of times that the player has failed guessing the word
	* @return number of attempts
	*/
	int getAttempts();

	/**
	* Returns the word that has to be guessed
	*/
	string getWord();

	/**
	* Returns the actual state of the word
	*/
	string getCurrentStatus();

	/**
	* Returns if the word has been completely guessed or not
	*/
	bool wordFound();

	/**
	* Reset the state of the object and choose a new word to be guessed
	*/
	void newWord();
};

