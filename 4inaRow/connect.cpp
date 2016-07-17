#include "connect.h"
#include <iostream>
using namespace std;

connect::connect()
{
}

void connect::intro()
{
	cout << endl << endl;
	cout << " Player 1's Name: ";
	cin >> player1;
	cout << " " << player1 << ", enter your symbol:  ";
	cin >> checkChar1;
	while (checkChar1.length() != 1)
	{
		cout << " Enter a character, not a word! " << endl;
		cout << " Symbol: ";
		cin >> checkChar1;
	}
	symbol1 = checkChar1[0];
	
	
	cout << endl;
	cout << " Player 2's Name: ";
	cin >> player2;
	cout << " " << player2 << ", enter your symbol:  ";
	cin >> checkChar2;
	while (checkChar2.length() != 1 || checkChar2 == checkChar1)
	{
		if (checkChar2.length() != 1){
			cout << " Enter a character, not a word! " << endl;
			cout << " Symbol: ";
			cin >> checkChar2;
		}
		else if (checkChar2 == checkChar1)
		{
			cout << " " << player2 << ", you can't pick the same symbol as " << player1 << endl;
			cout << " Enter your symbol again: ";
			cin >> checkChar2;
		}
	}
	symbol2 = checkChar2[0];

	cout << endl;



}




void connect::gamePlay()
{
	int whichPlayer = 3;
	int p1Drop;
	int p2Drop;
	while (true)
	{
		displayBoard();
		if (whichPlayer % 2 != 0) // if odd
		{
			cout << "\n\n " << player1 << ":  ";
			cin >> p1Drop;
			while (p1Drop < 1 || p1Drop > 7){ 
				cout << " Invalid Entry! Try again " << endl;
				cout << " " << player1 << ":  "; 
				cin >> p1Drop; }
			p1Drop = isFull(p1Drop);
		//	cout << " p1Drop is " << p1Drop << endl;
			for (int i = ROW; i > 0; i--)
			{
				if (board[i-1][p1Drop-1] == ' ')
				{
					board[i-1][p1Drop - 1] = symbol1;
					break;
				}
			}
			bool win1 = checkForWin(symbol1);
			if (win1) {
				displayBoard();
				cout << endl << " YAY! " << player1 << " WON " << endl;
				break;
			}
			whichPlayer++;
		}
		else if (whichPlayer % 2 == 0) // if even
		{
			cout << "\n\n " << player2 << ":  ";
			cin >> p2Drop;
			while (p2Drop < 1 || p2Drop > 7){
				cout << " Invalid Entry! Try again " << endl;
				cout << " " << player2 << ":  ";
				cin >> p2Drop;
			}
			p2Drop = isFull(p2Drop);
			//cout << " p2Drop is " << p2Drop << endl;
			for (int i = ROW; i > 0; i--)
			{

				if (board[i-1][p2Drop - 1] == ' ')
				{
					board[i-1][p2Drop - 1] = symbol2;
					break;
				}
			}
			bool win2 = checkForWin(symbol2);
			if (win2) {
				displayBoard();
				cout << endl << " YAY! " << player2 << " WON " << endl;
				break;
			}
			whichPlayer++;
		}
	}

}

int connect::isFull(int colNum)
{
	bool full = true;
	for (int i = 0; i < ROW; i++)
	{
		if (board[i][colNum - 1] == ' ')
		{
			full = false;
		//	cout << " Column is not full " << endl;
			break;
		}
	}
	if (full)
	{
		cout << " Column " << colNum << " is full. Choose a different one. " << endl;
		cout << " Column: ";
		cin >> colNum;
		colNum = isFull(colNum);
	}
	else if (!full)
	{
		return colNum;
	}
}


bool connect::checkForWin(char S)
{
	bool winner = false;
	// CHECK VERTICAL EVERY COLUMN
	for (int c = 0; c < COL; c++)
	{
		for (int r = ROW; r > (ROW - 3); r--)		
		{
			if (board[r - 1][c] == S && board[r - 2][c] == S) // if 1st 2 match then check other 2, else break
			{
				if (board[r - 3][c] == S && board[r - 4][c] == S)
				{
					winner = true;
					//cout << " Winner is True " << endl;
					return true;
				}
				//else { break; }
			}
			//else { break; }
		}
	}
	/*if (winner){
		return true;
	}*/
	//-----------------------------------------------------------------------------------------
	// CHECK HORIZONTAL EVERY ROW
	for (int r = ROW; r > 0; r--)
	{
		for (int c = 0; c <(COL - 3); c++)
		{
			if (board[r - 1][c] == S && board[r - 1][c+1] == S) // if 1st 2 match then check other 2, else break
			{
				if (board[r - 1][c+2] == S && board[r - 1][c+3] == S)
				{
					winner = true;
					return true;
				}
			//	else { break; }
			}
			//else { break; }
		}
	}
	/*if (winner){
		return true;
	}
	else{
		return false;
	}
	*/
	//-----------------------------------------------------------------------------------------

	/// CHECK DIAGOANL RIGHT
	// 
	for (int itr = 6; itr > 3; itr--)
	{
		for (int c = 0; c < 4; c++)
		{
			if (board[itr - 1][c] == S && board[itr - 2][c + 1] == S)
			{
				if (board[itr - 3][c + 2] == S && board[itr - 4][c + 3] == S)
				{
					winner = true;
					return true;
				}
			}
		}
	}
	/// CHECK DIAGOANL LEFT
	//
	for (int itrs = 6; itrs > 3; itrs--)
	{
		for (int c = COL-1; c >= 4; c--)  // ****************************** CHANGE MADE HERE MADE > INTO >=
		{
			if (board[itrs - 1][c] == S && board[itrs- 2][c - 1] == S)
			{
				if (board[itrs - 3][c - 2] == S && board[itrs - 4][c - 3] == S)
				{
					winner = true;
					return true;
				}
			}
		}
	}

	
	if (!winner){
		return false;
	}





}



















void connect::initialize()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void connect::displayBoard()
{
	//system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	cout << endl;
	cout << " ************************************************ " << endl;
	cout << "                 CONNECT FOUR                     " << endl;
	cout << " ************************************************ " << endl;
	cout << endl;
	cout << "        " << player1 << " is '" << symbol1 << "' and " << player2 << " is '" << symbol2 << "' " << endl;
	cout << " ************************************************ " << endl << endl;
	//cout << " PLAYER 1 IS 'O' & PLAYER 2 IS 'X' " << endl << endl;

	cout << "    1   2   3   4   5   6   7 " << endl;
	cout << "   ___________________________" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << board[0][3] << " | " << board[0][4] << " | " << board[0][5] << " | " << board[0][6] << " | " << endl;
	//cout << "                              " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << " | " << board[1][4] << " | " << board[1][5] << " | " << board[1][6] << " | " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << " | " << board[2][4] << " | " << board[2][5] << " | " << board[2][6] << " | " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | " << board[3][3] << " | " << board[3][4] << " | " << board[3][5] << " | " << board[3][6] << " | " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[4][0] << " | " << board[4][1] << " | " << board[4][2] << " | " << board[4][3] << " | " << board[4][4] << " | " << board[4][5] << " | " << board[4][6] << " | " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;
	cout << "  |   |   |   |   |   |   |   |" << endl;
	cout << "  | " << board[5][0] << " | " << board[5][1] << " | " << board[5][2] << " | " << board[5][3] << " | " << board[5][4] << " | " << board[5][5] << " | " << board[5][6] << " | " << endl;
	cout << "  |___|___|___|___|___|___|___|" << endl;

}











connect::~connect()
{
}


/*

*/