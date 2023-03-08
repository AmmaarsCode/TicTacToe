#ifndef _PROGRAM
#define _PROGRAM

class Program
{
public:
	Program();
	void Run();

private:
	void Setup();
	void ClearBoard();
	void DrawBoard();
	bool IsTaken(int row, int col);
	void PlaceToken(char symbol, int row, int col);
	int CheckForWinner();
	bool BoardIsFull();

	const int WIDTH;
	const int HEIGHT;
	char m_board[3][3];
	char m_symbols[2];
	int m_currentTurn;
};

#endif#pragma once
