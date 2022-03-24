#include"Header.hpp"
string guessed = "";
extern bool isContinueGame = true;
extern int wrongGuess = 0;
string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
 "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
};

const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
void gameStart(string secretWord) {
	cout << " ______________________________________________________________ \n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                       Game Start!                            |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "|                                                              |\n"
		<< "----------------------------------------------------------------\n";

	getchar();
}

bool isContinue() {
	return isContinueGame;
}

void addWrongGuess() {
	wrongGuess++;
}

void wonGame(string secretWord) {
	displayFinalResult(true, secretWord);
	isContinueGame = false;
}

void renderGame(string secretWord, string guessWord) {
	system("cls");
	if (guessWord == secretWord) {
		wonGame(secretWord);
		return;
	}
	cout << pylons[wrongGuess] << endl;
	cout << "Your word: " << guessWord << endl;
	cout << "Guessed: " << guessed << endl;
	cout << "Number of wrong guess: " << wrongGuess << endl;
	if (wrongGuess == 7) {
		displayFinalResult(false, secretWord);
		isContinueGame = false;
	}
}

char getPlayerGuess() {
	cout << "Please enter a letter! ";
	char playerLetter;
	cin >> playerLetter;
	guessed = guessed + " " + playerLetter;
	return playerLetter;
}

void update(string secretWord, string& guessWord, char playerGuess) {
	for (int i = 0; i < secretWord.size(); i++)
		if (secretWord[i] == playerGuess) guessWord[i] = playerGuess;
}

string chooseWord() {
	srand(time(0));
	int randomIndex = rand() % WORD_COUNT;
	return WORD_LIST[randomIndex];
}

bool contains(string secretWord, char playerGuess) {
	return (secretWord.find(playerGuess) != -1 ? true : false);
}

string creatGuessWord(string secretWord) {
	string creatWord(secretWord.size(), '-');
	return creatWord;
}