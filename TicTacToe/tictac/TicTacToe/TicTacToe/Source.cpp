#include <iostream>

using namespace std; //using namespace std despite general industry consensus to avoid, since previous instructors recommend it

//2d string array with items indexed from 1-9
string space[3][3] = { {"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"} }; //2D array for storing token values
void CreateBoard(); //generates game board and tracks progress
void MakeChoice(string); //player selects space, game inserts current player's token at selected space
string HasWon(); //checks if a player has won and, if so, who won
string winnerExt = "0"; //stores the winner of the game


int main()
{
	CreateBoard();
	cout << "\nGameplay instructions: Enter a number on the board"
		"\nthat has not yet been chosen. X goes first."
		"\nThe first player to get 3 in a row wins!" << endl;
	for (int turns = 1; turns < 5; turns++) //no wins are possible in the first 4 turns
	{
		if (turns % 2 != 0) //X goes first, thus odd turns are X turns
		{
			cout << "Player X, enter a number: ";
			MakeChoice("X");
			CreateBoard();
		}
		if (turns % 2 == 0) //O goes second, thus even turns are O turns
		{
			cout << "Player O, enter a number: ";
			MakeChoice("O");
			CreateBoard();
		}
	}
	for (int turns = 1; turns < 6; turns++) //Winning becomes possible in turn 5, and after turn 9 the game ends
	{
		winnerExt = HasWon();
		if (winnerExt == "0") //no one has won; game continues
		{
			if (turns % 2 != 0)
			{
				cout << "Player X, enter a number: ";
				MakeChoice("X");
				CreateBoard();
			}
			if (turns % 2 == 0)
			{
				cout << "Player O, enter a number: ";
				MakeChoice("O");
				CreateBoard();
			}
		}
		else //someone has won; game ends
		{
			cout << "Congratulations, player " << winnerExt << "! You have won." << endl;
			return 0;
		}
	}
	if (winnerExt == "0") //tie game
	{
		cout << "Sadly, the game has resulted in a tie." << endl;
		return 0;
	}
	else //this condition should not occur
	{
		cout << "Something has gone terribly wrong." << endl;
		return 0;
	}
	return 0;
}


void CreateBoard() 
{
	cout << "\tTic-Tac-Toe\n\n"; //game name title

	//top row
	cout << "       |       |       \n"; //7 spaces per spot
	cout << "   " << space[0][0] << "   |   " << space[0][1] << "   |   " << space[0][2] << "   \n";
	cout << "       |       |       \n";

	//mid row
	cout << "_______________________\n"; //23 underscores
	cout << "       |       |       \n";
	cout << "   " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << "   \n";
	cout << "       |       |       \n";
	cout << "_______________________\n";

	//bot row
	cout << "       |       |       \n";
	cout << "   " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << "   \n";
	cout << "       |       |       \n";
}

void MakeChoice(string currentPlayer)
{
	bool changed = false;
	string choice = "0";
	cin >> choice;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (space[i][j] == choice) //sequential search of 2d array
			{
				space[i][j] = currentPlayer; //replace existing character
				changed = true;
				break;
			}
		}
	}
	if (changed == false)
	{
		cout << "Invalid number. Please try again." << endl;
		MakeChoice(currentPlayer);
	}
}

string HasWon() 
{
	string winner = "0";
	for (int i = 0; i < 3; i++)
	{
		if (space[i][0] == space[i][1] && space[i][0] == space[i][2]) //check horizontal wins
		{
			winner = space[i][1];
			break;
		}
		if (space[0][i] == space[1][i] && space[0][i] == space[2][i]) //check vertical wins
		{
			winner = space[1][i];
			break;
		}
	}
	if (space[0][0] == space[1][1] && space[0][0] == space[2][2]) //check diagonal down win
	{
		winner = space[1][1];
	}
	if (space[0][2] == space[1][1] && space[0][2] == space[2][0]) //check diagonal up win
	{
		winner = space[1][1];
	}
	return winner;
}