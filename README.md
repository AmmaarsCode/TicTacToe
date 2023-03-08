# TicTacToe
Tic Tac Toe Game
This is a simple command line Tic Tac Toe game implemented in C++ language. The game uses a 3x3 board and two players, 'X' and 'O', take turns marking spaces in the board. The objective of the game is to get three in a row either horizontally, vertically, or diagonally.

Getting Started
These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

Prerequisites
The following software should be installed on your machine to run the project:

A C++ compiler
An IDE or a text editor
Installing
To install the project, clone the repository from GitHub using the following command:

git clone https://github.com/username/repository.git

Running the tests
To test the game, navigate to the project directory and run the following command in the terminal:

g++ -o tictactoe Header.h main.cpp && ./tictactoe

This command will compile and run the program.

Code Overview
The project consists of a single C++ file containing the implementation of the Tic Tac Toe game. It includes a Program class which is responsible for managing the game logic. The Program class has the following methods:

Program() : The constructor that initializes the WIDTH and HEIGHT of the board.

void Setup() : Initializes the game by calling the ClearBoard() method and setting the symbols for the two players.

void Run() : This is the main loop of the game that checks for a winner or a tie and allows each player to take turns.

void ClearBoard() : Clears the board by setting all cells to empty.

void DrawBoard() : Draws the game board.

bool IsTaken(int row, int col) : Checks if a cell is taken by a player.

void PlaceToken(char symbol, int row, int col) : Places the symbol of the current player on the board.

bool BoardIsFull() : Checks if the board is full.

int CheckForWinner() : Checks if a player has won the game.

int main() : Initializes a Program object and calls the Run() method to start the game.

Game Flow
The game starts by clearing the board and setting the symbols for each player. The game then enters a loop where it checks for a winner or a tie, and allows each player to take turns. The loop continues until a winner is declared or the board is full. The game is then terminated.

Conclusion
The Tic Tac Toe game is a simple and fun game that can be implemented in a few lines of code. The implementation in this project is easy to understand and modify, making it an excellent starting point for learning C++ programming.
