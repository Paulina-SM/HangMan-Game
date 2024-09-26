#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void FileReader::readFile(string nameFile) {
    string word;
    ifstream fptr(nameFile);
    if (!fptr.is_open()) perror("Error opening file");
    while (getline(fptr, word)) {
        totalWords.push_back(word);
    }
    fptr.close();
}

int FileReader::numWords() {
    return totalWords.size();
}

string FileReader::newWord() {
    return totalWords.at((rand() % totalWords.size()));
}