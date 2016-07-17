#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "connect.h"

using namespace std;



int main()
{

	cout << "\n\n WELCOME TO PARTH'S CONNECT FOUR GAME\n";
	cout << " To play, first enter player's Name. Then enter you symbol.\n It could be a letter, a number or almost any character.\n";
	//cout << " Then enter second player's Name and symbol\n\n\n";
	cout << "\n\n And finally, to drop your symbol, you'll have to enter the column number\n\n\n";

	connect o;
	o.initialize();
	o.intro();
	o.gamePlay();

	


	system("pause");
	return 0;
}

