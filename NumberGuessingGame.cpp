#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
using namespace std;

const int NUM_MIN = 0;
const int NUM_MAX = 100;

const int EASY_ID = 1;
const int HARD_ID = 3;

const int EASY_CHANCES = 10;
const int MEDIUM_CHANCES = 5;
const int HARD_CHANCES = 3;

enum Difficulty { Easy = 1, Medium, Hard };

// Helper functions
int validInput(int start_id, int end_id) {
  string input;
  int value;
  while (true) {
    cout << "Enter your choice: ";
    getline(cin, input);

    stringstream ss(input);
    if ((ss >> value) && !(ss >> input) && value >= start_id &&
        value <= end_id) {
      return value;
    }
    cout << "Invalid input. Value must be from " << start_id << " to " << end_id
         << "\n";
  }
}
bool validContInput() {
  string input;

  while (true) {
    cout << "Do you want to continue? [Y/n]: \n";

    getline(cin, input);

    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "y")
      return true;
    if (input == "n")
      return false;

    cout << "Invalid input, please enter Y for yes, N for no only.\n";
  }
}

// Game functions

void printInstruction() {
  cout << "--------------------------------------------------\n";
  cout << "Welcome to the Number Guessing Game! \n";
  cout << "I'm thinking of a number between 1 and 100.\n";
  cout << "Your mission is to guess that random number!\n";
  cout << "--------------------------------------------------\n";
}

int diffSelection() {
  int diffLevel;
  cout << "Please select the difficult level:\n";
  cout << "1. Easy (10 chances)\n";
  cout << "2. Medium (5 chances)\n";
  cout << "3. Hard (3 chances)\n\n";

  diffLevel = validInput(Easy, Hard);

  cout << "\n";

  switch (diffLevel) {
  case Easy:
    cout << "Great! You have selected the Easy difficulty level.\n";
    break;
  case Medium:
    cout << "Great! You have selected the Medium difficulty level.\n";
    break;
  case Hard:
    cout << "Great! You have selected the Hard difficulty level.\n";
    break;
  }

  cout << "Let's start the game!\n";
  return diffLevel;
}

int generateNum() {
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> dist(NUM_MIN, NUM_MAX);
  return dist(gen);
}

int getChancesLevel(int level) {
  switch (level) {
  case Easy:
    return EASY_CHANCES;
  case Hard:
    return HARD_CHANCES;
  default:
    return MEDIUM_CHANCES;
  }
}

bool guessGuessingRound(int secret, int chances) {
  for (int attempts = 1; attempts <= chances; attempts++) {
    int guess = validInput(NUM_MIN, NUM_MAX);
    if (guess > secret)
      cout << "Incorrect! The number is less than " << guess << ".\n";
    else if (guess < secret)
      cout << "Incorrect! The number is greater than " << guess << ".\n";
    else {
      cout << "Congratulations! You guessed the correct number in " << attempts
           << " attempts.\n";
      return true;
    }
    cout << "Remaining attempts: " << (chances - attempts) << "\n";
  }
  cout << "Too many attemps, you lose!\n";
  cout << "The number was " << secret << endl;
  return false;
}

void startGame() {
  int diffLevel, secret;
  secret = generateNum();
  printInstruction();
  diffLevel = diffSelection();
  int chances = getChancesLevel(diffLevel);
  int guess;
  int attempts = 0;
  cout << "You have " << chances << " attempts. Good Luck!\n\n";
  guessGuessingRound(secret, chances);
}

int main() {
  bool isContinue = true;
  while (isContinue) {
    startGame();
    isContinue = validContInput();
  }
  return 0;
}
