#include"Header.hpp"

int main() {

	string creatGuessWord(string secretWord);
	string secretWord = chooseWord();
	string guessWord = creatGuessWord(secretWord);
	gameStart(secretWord);

	do {
		renderGame(secretWord, guessWord);
		if (!isContinue()) break;
		char playerGuess = getPlayerGuess();
		if (contains(secretWord, playerGuess)) update(secretWord, guessWord, playerGuess);
		else addWrongGuess();
	} while (isContinue());

	return 0;
}