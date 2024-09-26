#pragma once

#include <string>
#include <vector>
using namespace std;
/**
* Class that reads a file and read every word of the archive. 
* This archive has to have every word in a new line.
*/
class FileReader
{
private:
	
	vector<string> totalWords; // Vector that has all the words
public:
	/**
	* Reads the file and put the words inside totalWords
	* @param file --> file to read
	*/
	void readFile(string file);

	/** Returns the number of words
	*/
	int numWords();

	/**
	* Returns a random word from totalWords
	*/
	string newWord();
};

