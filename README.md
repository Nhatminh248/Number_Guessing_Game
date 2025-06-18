# Number Guessing Game
This is an implementation for the Number Guessing Game on Roadmap.sh Project ideas.
## Overview
This is a C++ command-line game where players try to guess a randomly generated number. 
It supports multiple difficulty levels, input validation, and a timer to track how long the user takes to win or lose.

Built with:
- C++11
- `<random>` for number generation
- `<chrono>` for timing gameplay
- `<sstream>` and `<string>` for robust user input

## Requirements
It is a CLI-based game, so you need to use the command line to interact with the game. The game should work as follows:
- When the game starts, it should display a welcome message along with the rules of the game.
- The computer should randomly select a number between 1 and 100.
- User should select the difficulty level (easy, medium, hard) which will determine the number of chances they get to guess the number.
- The user should be able to enter their guess.
- If the user’s guess is correct, the game should display a congratulatory message along with the number of attempts it took to guess the number.
- If the user’s guess is incorrect, the game should display a message indicating whether the number is greater or less than the user’s guess.
- The game should end when the user guesses the correct number or runs out of chances.

## How to Play
1. Run the game in your terminal.
2. Choose a difficulty:
   - Easy: 10 attempts
   - Medium: 5 attempts
   - Hard: 3 attempts
3. Start guessing a number between 1 and 100.
4. The game will give hints whether the secret number is higher or lower.
5. The game ends when you guess correctly or run out of chances.
6. After each game, you can choose to play again or quit.

## How to Build and Run

### Prerequisites:
- A C++11-compatible compiler (e.g., `g++`, `clang++`)
- Terminal / command line

### Compile:
```bash
g++ -std=c++11 -o guess_game NumberGuessingGame.cpp
```
### Run
```bash
./guess_game
```
## ⏱️ 4. **Features**

### Features
- Difficulty selection (Easy, Medium, Hard)
- Robust input validation (no crashes on invalid input)
- Random number generation with proper seeding
- Time tracking (shows how long you took to guess)
- Option to replay 

## Repo URL
Repo URL: [link](https://github.com/Nhatminh248/Number_Guessing_Game.git)
Project URL: [link](https://roadmap.sh/projects/number-guessing-game)

