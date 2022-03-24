#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

const int maxWrongGuess = 7;
const string pylons[] = { "_____________      \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  "_____________      \n"
						  " |          |      \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |                 \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  
						  "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |          |      \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |         /|      \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |         /|\\    \n"
						  " |                 \n"
						  " |                 \n"
						  "-------",
						  "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |         /|\\    \n"
						  " |         /       \n"
						  " |                 \n"
						  "-------",
						 "_____________      \n"
						  " |          |      \n"
						  " |          o      \n"
						  " |         /|\\    \n"
						  " |         / \\    \n"
						  " |                 \n"
						  "-------",

};

void gameStart(string secretWord);
void wonGame(string secretWord);
void renderGame(string secretWord, string guessWord);
char getPlayerGuess();
void update(string secretWord, string& guessWord, char playerGuess);
string chooseWord();
bool contains(string secretWord, char playerGuess);
string creatGuessWord(string secretWord);
bool isContinue();
void addWrongGuess();
void displayFinalResult(bool won, const string& word);