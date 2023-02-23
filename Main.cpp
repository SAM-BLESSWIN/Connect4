#include<iostream>
using namespace std;

const static int ROWS = 6;
const static int COLS = 7;
const static char PLAYER_A = 'X';
const static char PLAYER_B = 'O';
char board[ROWS][COLS];

void InitBoard()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = '-';
		}
	}
}


void PrintBoard()
{
	cout  << "\n";
	for (int i = 0; i < ROWS; i++)
	{
		cout << "|";
		for (int j = 0; j < COLS; j++)
		{
			if (board[i][j] == '-')
			{
				cout << " _ ";
			}
			else
			{
				cout << " " << board[i][j] << " ";
			}
			cout << "|";
		}
		cout << "\n\n";
	}
}


int GetCoinInsertedRow(int column, char coin)
{
	int row = -1;
	for (int i = ROWS - 1; i >= 0; i--)
	{
		if (board[i][column] == '-')
		{
			board[i][column] = coin;
			row = i;
			break;
		}
	}

	return row;
}

bool CanAddCoinToBoard(int column, char coin)
{
	if (!(column >= 0 && column < COLS))
	{
		cout << "Please select the column number between 1 to 7 \n";
		return false;
	}
	else if (board[0][column] != '-')
	{
		cout << "The selected column of the board is full \n";
		return false;
	}

	return true;
}


bool VerticalCheck(int row, int column, char coin)
{
	int streak = 0;
	//vertical check
	for (int i = row; i < ROWS; i++)
	{
		if (board[i][column] == coin)
		{
			streak++;

			if (streak == 4)
			{
				return true;
			}

		}
		else
		{
			streak = 0;
		}
	}

	return false;
}

bool HorizontalCheck(int row, int column, char coin)
{
	int streak = 0;
	for(int j = column-3; j <= column+3 && j<COLS;j++)
	{
		if (j < 0) continue;

		if (board[row][j] == coin)
		{
			streak++;

			if (streak == 4)
			{
				return true;
			}
		}
		else
		{
			streak = 0;
		}
	}

	return false;
}

bool RightDiagonalCheck(int row, int column, char coin)
{
	int streak = 0;
	for (int i = row + 3, j = column - 3; i >= row - 3 && j <= column + 3; i--, j++)
	{
		if (i < 0 || i >= ROWS || j < 0 || j >= COLS) continue;

		if (board[i][j] == coin)
		{
			streak++;

			if (streak == 4)
			{
				return true;
			}
		}
		else
		{
			streak = 0;
		}
	}

	return false;
}


bool LeftDiagonalCheck(int row, int column, char coin)
{
	int streak = 0;
	for (int i = row + 3, j = column + 3; i >= row - 3 && j >= column - 3; i--, j--)
	{
		if (i < 0 || i >= ROWS || j < 0 || j >= COLS) continue;

		if (board[i][j] == coin)
		{
			streak++;

			if (streak == 4)
			{
				return true;
			}
		}
		else
		{
			streak = 0;
		}
	}

	return false;
}

bool CheckWin(int row, int column, char coin)
{
	if (VerticalCheck(row, column, coin)) 
		return true;

	if (HorizontalCheck(row, column, coin))
		return true;

	if (RightDiagonalCheck(row, column, coin))
		return true;

	if (LeftDiagonalCheck(row, column, coin))
		return true;

	return false;
}


int main()
{
	InitBoard();
	bool isPlaying = true;
	char coin = PLAYER_A;    //X - player 1 // O - player 2

	cout << "\n\nCONNECT 4 BOARD ";
	cout << ROWS << " * " << COLS<<"\n\n";
	PrintBoard();

	while (isPlaying)
	{
		if (coin == 'X')
			cout << "Player_1 : \n";
		else
			cout << "Player_2 : \n";

		cout << "Enter the column number to insert the coin : ";
		int column;
		cin >> column;
		cout << "\n";
		if (CanAddCoinToBoard(column-1, coin))
		{
			int row = GetCoinInsertedRow(column-1, coin);

			PrintBoard();
			if (CheckWin(row, column-1, coin))
			{
				isPlaying = false;
				break;
			}
			coin = (coin == PLAYER_A) ? PLAYER_B : PLAYER_A;
		}
	}

	if (coin == PLAYER_A)
		cout << "Player A won the game!!";
	else
		cout << "Player B won the game!!";
}