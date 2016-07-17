
#ifndef CONNECT_H
#define	CONNECT_H

#include <string>

//#define ROW 6
//#define COL 7
using namespace std;



class connect {
public:
	connect();             /// Constructor
	
	void initialize();
	void displayBoard();
	void gamePlay();
	int isFull(int colNum);
	bool checkForWin(char S);
	void intro();
	~connect();
private:
	char board[6][7];
	const int ROW = 6;
	const int COL = 7;
	string player1, player2;
	string checkChar1, checkChar2;
	char symbol1, symbol2;
};

#endif	



/*
Replace strings with Chars
Make only 1 checkForWin function and pass in player's symbol (char) as a parameter
Start with bottom left corner and check for  vertical, horizontal, and diagonal for any similarity. 
  - to save time, break when two consecutive different symbols are found or a blank is found
  - start with bottom left and check upward, then start with the one above it and check upward and so on
  - then start with bottom left and check horizontal, then start with the one next to it and check horizontal and so on
  - you should also break after checking a row/column till half way. because after half way, if there is less than 4 spaces remaining, there are obviously not gonna have 4 connected spaces b/c again there's less than 4 spaces to have
  - and there's no need to check backward because you've already checked them

  let players choose their symbol and make sure both player's symbols are different

*/

