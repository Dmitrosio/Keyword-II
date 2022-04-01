#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
// Display Title of the program to the user
	cout << "Welcome to Keywords II Code Breaker Training Simulation Program." << endl;

	for (int i = 0; i <= 3; i++) {
		cout << " " << endl;
	}

// Ask the recruit to log in using their name
	cout << "Please, recruit, enter your login information: First Name: ";

// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string first_name;
	cin >> first_name;

	cout << "You have to guess 3 words to pass the simulations you have 8 attempts" << endl;
	for (int i = 0; i <= 1; i++) {
		cout << " " << endl;
	}
	// creates the vector for 10 words
	vector<string> CodeWords;
	CodeWords.push_back("ROSE");
	CodeWords.push_back("CODE");
	CodeWords.push_back("STEALTH");
	CodeWords.push_back("GUN");
	CodeWords.push_back("BOND");
	CodeWords.push_back("GAME");
	CodeWords.push_back("ESPIONAGE");
	CodeWords.push_back("LIME");
	CodeWords.push_back("AZKABAN");
	CodeWords.push_back("PLANE");

	// int for the simulations
	int sim = 1;

	// int for tries
	int tries = 0;

	// int for tries left
	int tleft = 8;

	// prints the simulation number
	cout << "Simulation #" <<  sim << endl;

	// randomizzer
	srand(static_cast<unsigned int>(time(0)));
	// suffles the vector
	random_shuffle(CodeWords.begin(), CodeWords.end());

	const string WordToGuess = CodeWords[0];
	string guessedLetters(WordToGuess.size(), '_');
	// string for the used letters
	string usedLetter = "";
	// for loop to check for the main part of the code
	for (sim; sim < 2; sim++) {
		while ((tries < tleft) && (guessedLetters != WordToGuess)) {
			for (int i = 0; i <= 1; i++) {
				cout << " " << endl;
			}

			cout << first_name << " ,you have " << (tleft - tries) << " guesses left!" << endl;

			for (int i = 0; i <= 1; i++) {
				cout << " " << endl;
			}

			cout << "You have used the following letters: " << usedLetter << endl;

			for (int i = 0; i <= 1; i++) {
				cout << " " << endl;
			}

			cout << "Current Word: " << guessedLetters << endl;

			for (int i = 0; i <= 1; i++) {
				cout << " " << endl;
			}
			// var for the guess's
			char guess;
			cout << "Enter a character/word Guess: ";
			cin >> guess;
			guess = toupper(guess);

			while (usedLetter.find(guess) != string::npos)
			{
				cout << first_name << " ,you have already guessed that!" << endl;
				cout << "Enter new guess: ";
				cin >> guess;
				guess = toupper(guess);
				system("CLS");
			}
			usedLetter += guess;

			//checks if the guess is correct
			if (WordToGuess.find(guess) != string::npos) {
				cout << "Your guess is correct: " << guess << " is in the word.\n";
				for (int i = 0; i < WordToGuess.length(); i++) {
					if (WordToGuess[i] == guess) {
						guessedLetters[i] = guess;
					}
				}
			}
			else {
				cout << guess << " is not correct.\n";
				++tries;
			}

		}
		if (tries == tleft) {
			cout << "Wrong guess" << endl;

		}
		else {
			cout << "Correct guess!" << endl;

		}

		// prints out the word was right and puases the simulation
		cout << "The word was: " << WordToGuess << endl;
		system("PAUSE");
	}
}