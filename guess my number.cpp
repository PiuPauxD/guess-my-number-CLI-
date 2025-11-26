#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int secretNumber(int& value);
int userInput();

void gameCycle();

int tries = 0;
//change console output color
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
	
	char again = 'y';
	SetConsoleTextAttribute(console, FOREGROUND_BLUE);

	while (again == 'y') {
		gameCycle();
		cout << "\nPlay again?(y/n): "; cin >> again;
		if (again == 'y') {
			tries = 0;
		}
	}

	system("pause");

	return 0;
}

//generate a random nuber
int secretNumber(int& value) {
	//random numbers generator
	srand(static_cast<unsigned int>(time(0)));
	//random number from 1 to 100
	value = rand() % 100 + 1;
	return value;
}

//user input function
int userInput() {
	int input;
	cout << "\nEnter your guess: "; cin >> input;
	return input;
}

void gameCycle() {

	int userGuess;
	int number = secretNumber(number);

	do {
		userGuess = userInput();
		++tries;
		if (userGuess > number) {
			//change console output color
			SetConsoleTextAttribute(console, FOREGROUND_RED);
			cout << "Too high!\n";
			SetConsoleTextAttribute(console, FOREGROUND_INTENSITY);
		}
		else if (userGuess < number) {
			SetConsoleTextAttribute(console, FOREGROUND_BLUE);
			cout << "Too low!\n";
			SetConsoleTextAttribute(console, FOREGROUND_BLUE);
		}
		else {
			SetConsoleTextAttribute(console, FOREGROUND_GREEN);
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
			SetConsoleTextAttribute(console, FOREGROUND_BLUE);
		}
	} while (userGuess != number);
}