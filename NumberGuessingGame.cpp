#include <iostream>
#include <random>
#include <sstream>
#include <string>
using namespace std;

const int NUM_MIN = 1;
const int NUM_MAX = 100;

const int EASY_ID = 1;
const int HARD_ID = 3;

const int EASY_CHANCES = 10;
const int MEDIUM_CHANCES = 5;
const int HARD_CHANCES = 3;
///// Forward Declaration

void printInstruction() {
  cout << "Welcome to the Number Guessing Game! \n";
  cout << "I'm thinking of a number between 1 and 100.\n\n";
}

int validDiff(int easy_id, int hard_id) {
  string input;
  int value;
  while (true) {
    cout << "Enter your choice: ";
    getline(cin, input);

    stringstream ss(input);
    if ((ss >> value) && !(ss >> input) && value >= easy_id &&
        value <= hard_id) {
      return value;
    }
    cout << "Invalid input. Value must be from 1 to 3.\n";
  }
}
int diffSelection() {
  int diffLevel;
  cout << "Please select the difficult level:\n";
  cout << "1. Easy (10 chances)\n";
  cout << "2. Medium (5 chances)\n";
  cout << "3. Hard (3 chances)\n\n";

  diffLevel = validDiff(EASY_ID, HARD_ID);

  cout << "\n";

  switch (diffLevel) {
  case 1:
    cout << "Great! You have selected the Easy difficulty level.\n";
    break;
  case 2:
    cout << "Great! You have selected the Medium difficulty level.\n";
    break;
  case 3:
    cout << "Great! You have selected the Hard difficulty level.\n";
    break;
  default:
    break;
  }

  cout << "Let's start the game!\n";
  return diffLevel;
}

int generateNum() {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(NUM_MIN, NUM_MAX);

  int SecretNum = dist(gen);
  return SecretNum;
}

void validGuess() {}

void compareGuess() {}
void readInput(int &diffLevel, int &SecretNum) {
  int chances = 0;
  if (diffLevel == 1) {
    chances = EASY_CHANCES;
  } else if (diffLevel == 2) {
    chances = MEDIUM_CHANCES;
  } else if (diffLevel == 3) {
    chances = HARD_CHANCES;
  }

  int guess;
  int attempts;

  cout << "Enter your guess: ";
  cin >> guess;
  cout << "\n";
  if (guess > SecretNum) {
    cout << "Incorrect! The number is less than " << guess << ".\n";
  } else if (guess < SecretNum) {
    cout << "Incorrect! The number is greater than " << guess << ".\n";
  } else if (guess == SecretNum) {
    cout << "Congratulations! You guessed the correct  number in " << attempts
         << " attempts.\n";
  }
}

void GameLoop() {
  int diffLevel, SecrectNum;
  printInstruction();
  diffLevel = diffSelection();
  SecrectNum = generateNum();
  readInput(diffLevel, SecrectNum);
}

int main() {
  GameLoop();
  return 0;
}