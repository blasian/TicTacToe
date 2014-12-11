#include <iostream>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();

int main()
{
	int player = 1, i, choice;
	char mark;
	do
	{
		board();
		player = (player%2) ? 1:2;
		cout << "Player" << player << ", enter a number: ";
		cin >> choice;
		mark = (player == 1) ? 'X':'O';
		
		if ((square[choice] - '0') == choice)
			switch(choice)
			{
				case 1:
					square[1] = mark;
					break;
				case 2:
					square[2] = mark;
					break;
				case 3:
					square[3] = mark;
					break;
				case 4:
					square[4] = mark;
					break;
				case 5:
					square[5] = mark;
					break;
				case 6:
					square[6] = mark;
					break;
				case 7:
					square[7] = mark;
					break;
				case 8:
					square[8] = mark;
					break;
				case 9:
					square[9] = mark;
					break;
				default:
					cout << "Invalid move";
					player--;
					cin.ignore();
					cin.get();
			}
		else
		{
			cout << "Invalid move";
			player--;
			cin.ignore();
			cin.get();
		}


		i = checkwin();
		player++;
	} while (i == -1);
	board();
	if (i==1)
	{
		cout << "Player " << --player << " wins";
	} else {
		cout << "Draw";
	}
	cin.ignore();
	cin.get();
	return 0;
}

int checkwin()
{
	int count = 0;

	//	Check diagnals 
	if ((square[1] == square[5] && square[5] == square[9]) ||
		(square[3] == square[5] && square[5] == square[7]))
		return 1;

	// Check horizontals
	for (int i = 1; i <= 9; i+=3)
	{
		if (square[i] == square[i+1] && square[i+1] == square[i+2])
			return 1;
	}

	//	Check verticals
	for (int i = 1; i <= 3; i++)
	{
		if (square[i] == square[i+3] && square[i+3] == square[i+6])
			return 1;
	}

	//	Checks for a full board
	for (int i = 1; i <= 9; i++)
	{
		if (square[i] - '0' != i)
			count ++;
	}
	if (count == 9) {return 0;}

	// Otherwise game is still going
	return -1;
}

void board()
{
	system("clear");
	cout << "\n\nTic-Tac-Toe\n\n";
	cout << "Player 1 (X) - Player 2 (O)";
	cout << endl << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}





