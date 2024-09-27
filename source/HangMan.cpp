#include "../headers/HangMan.h"
#include "../headers/FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

HangMan::HangMan(string nameFile) {
	file.readFile(nameFile);
	newWord();
}

bool HangMan::hasLetter(char letter) {

	// The letter is in the word
	if (word.find(letter) != -1) { 
		correct.push_back(letter);
		return true;
	}
	// The letter isnt in the word
	else {
		if (find(wrongs.begin(), wrongs.end(), letter) == wrongs.end()) {
			attempts++;
			wrongs.push_back(letter);
			return true;
		}
		
	}
}

int HangMan::getAttempts() {
	return attempts;
}

string HangMan::getWord() {
	return word;
}

string HangMan::wordGuessed() {
	int guessed = 0;

	string status = "";
	for (int i = 0; i < word.size(); i++) {
		// If the letter has been already guessed
		if (find(correct.begin(), correct.end(), word[i]) != correct.end()) {
			status.push_back(word[i]);
			status += " ";
			guessed++;
		}//If not
		else
			status += "_ ";
	}
	status += "\n" + word;
	if (guessed == word.size())
		found = true;
	return status;
}


bool HangMan::wordFound() {
	return found;
}

string HangMan::getCurrentStatus() {
	string status = "Errors : " + to_string(attempts) ;
	//status += "\n " + wordGuessed() + "\n";
	status += "letters used : ";
	for (int i = 0; i < wrongs.size(); ++i) {
		status.push_back(wrongs[i]);
		status += + " ";
	}

	status += "\n";
	return status;
}

void HangMan::newWord() {
	correct.clear();
	wrongs.clear();
	word = file.newWord();
	attempts = 0;
	found = false;
}