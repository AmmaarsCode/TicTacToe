#include "Header.h"

#include <iostream>
using namespace std;

Program::Program()
	: WIDTH(3), HEIGHT(3)
{
}

void Program::Setup()
{
	ClearBoard();
	m_symbols[0] = 'X';
	m_symbols[1] = 'O';
	m_currentTurn = 0;
}

void Program::Run()
{
	Setup();

	while (true)
	{
		DrawBoard();

		int winner = CheckForWinner();
		if (winner != -1)
		{
			cout << "PLAYER " << m_symbols[winner] << " WINS!" << endl;
			break;
		}

		bool fullBoard = BoardIsFull();
		if (fullBoard)
		{
			cout << "STALEMATE! NOBODY WINS!" << endl;
			break;
		}

		cout << endl << "PLAYER " << m_currentTurn << "'s TURN" << endl;
		int row, col;
		cout << "Enter ROW COL to place your " << m_symbols[m_currentTurn] << ": ";
		cin >> row >> col;

		while (IsTaken(row, col))
		{
			cout << endl << "That spot is taken! Try again!" << endl;
			cout << "Enter ROW COL to place your " << m_symbols[m_currentTurn] << ": ";
			cin >> row >> col;
		}

		PlaceToken(m_symbols[m_currentTurn], row, col);

		if (m_currentTurn == 0) {
			m_currentTurn = 1;
		}
		else {
			m_currentTurn = 0;
		}
	}
}

void Program::ClearBoard()
{
	for (int r = 0; r < HEIGHT; r++)
	{
		for (int c = 0; c < WIDTH; c++)
		{
			m_board[r][c] = ' ';
		}
	}
}

void Program::DrawBoard()
{
	cout << endl;
	for (int r = 0; r < HEIGHT; r++)
	{
		if (r != 0) { cout << "-----------" << endl; }
		for (int c = 0; c < WIDTH; c++)
		{
			if (c != 0) { cout << " | "; }
			else { cout << " "; }
			cout << m_board[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

bool Program::IsTaken(int row, int col)
{
	return m_board[row][col] != ' ';
}

void Program::PlaceToken(char symbol, int row, int col)
{
	m_board[row][col] = symbol;
}

bool Program::BoardIsFull()
{
	// Check to see if all spaces are taken
	for (int r = 0; r < HEIGHT; r++)
	{
		for (int c = 0; c < WIDTH; c++)
		{
			if (m_board[r][c] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

/**
* @return 0 for player 0 win, 1 for player 1 win, or -1 for no win
*/
int Program::CheckForWinner()
{
	// Ugly long way:
	for (int s = 0; s < 2; s++)	// each player
	{
		// Horizontal wins
		for (int r = 0; r < HEIGHT; r++)
		{
			if (m_board[r][0] == m_symbols[s] &&
				m_board[r][1] == m_symbols[s] &&
				m_board[r][2] == m_symbols[s])
			{
				return s;
			}
		}

		// Vertical wins
		for (int c = 0; c < WIDTH; c++)
		{
			if (m_board[0][c] == m_symbols[s] &&
				m_board[1][c] == m_symbols[s] &&
				m_board[2][c] == m_symbols[s])
			{
				return s;
			}
		}

		// Diagonal wins
		if (m_board[0][0] == m_symbols[s] &&
			m_board[1][1] == m_symbols[s] &&
			m_board[2][2] == m_symbols[s])
		{
			return s;
		}

		if (m_board[0][2] == m_symbols[s] &&
			m_board[1][1] == m_symbols[s] &&
			m_board[2][0] == m_symbols[s])
		{
			return s;
		}
	}

	// No winners detected
	return -1;
}

int main()
{
	Program program;
	program.Run();

	return 0;
}