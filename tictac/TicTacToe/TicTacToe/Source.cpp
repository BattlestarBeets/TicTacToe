#include <iostream>

using namespace std;

//char array with 10 items indexed from 0-9
char space[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // char type since we will be swapping between numbered spaces and characters X and O ; space 0 wont be outputed

void CreateBoard(); //Function to create the board


int main()
{
	CreateBoard();




	return 0;
}


void CreateBoard()
{
	cout << "\tTic-Tac-Toe\n\n"; //game name title

	//top row
	cout << "       |       |       \n"; //7 spaces per spot
	cout << "   " << space[1] << "   |   " << space[2] << "   |   " << space[3] << "   \n";
	cout << "       |       |       \n";

	//mid row
	cout << "_______________________\n"; //23 underscores
	cout << "       |       |       \n";
	cout << "   " << space[4] << "   |   " << space[5] << "   |   " << space[6] << "   \n";
	cout << "       |       |       \n";
	cout << "_______________________\n";

	//bot row
	cout << "       |       |       \n";
	cout << "   " << space[7] << "   |   " << space[8] << "   |   " << space[9] << "   \n";
	cout << "       |       |       \n";
}