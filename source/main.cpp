// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include "../headers/HangMan.h"

using namespace std;


int main()
{   
    bool stop = false;
    char letter;
    
    
    HangMan hang("../data/datos.txt"); 
    cout << "THE HANGMAN GAME!\n"
        << "Press any letter to continue\n";
    cin >> letter;
    while (!stop) {
        
        cout << hang.getCurrentStatus();

        if (hang.wordFound() || hang.getAttempts() == 3) {
            system("cls");

            if (hang.getAttempts() == 3) {
                cout << "You lost " << endl;
            }
            else {
                cout << "You win. the word was: " << hang.getWord() << endl;
            }
            cout << "Press q to stop" << endl;
            cin >> letter;
            stop = 'q' == tolower(letter);
            hang.newWord();
            
        }
        else {
            cout << "Put a new letter" << endl;
            cin >> letter;
            hang.hasLetter(tolower(letter));
        }
        system("cls");

    }
    return 0;
}
