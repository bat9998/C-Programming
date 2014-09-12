#include <iostream>
#include <cstdlib>

using namespace std;

void displayBoard(char b[][3], int size);
void grabInput(char player);
void updateBoard(char b[3][3], int, char player, char currentMove);
void checkWin();
void checkDraw();
bool isPlaying = true; 
bool hasWon = false;
bool hasDrawn = false;

char player = 'X';
char player2 = 'O';
char activePlayer = player;
char currentMove;

char b[3][3] =
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

int main()
{
	displayBoard(b,3);

	while (isPlaying && !hasWon && !hasDrawn)
	{
		grabInput(activePlayer);
		char tile = b[0][currentMove - '1'];
		
		if (currentMove < '1' || currentMove >	'9')
			cout<<"No such square.\n";

		else
		{
			if (tile == 'X' || tile == 'O')
			{
				cout<<"Invalid Move\n";
			}
			else
			{
				updateBoard(b,3,activePlayer,currentMove);
				checkWin();
				checkDraw();
			}
			
		}

		if (hasWon)
			cin.get();
		else
			displayBoard(b,3);

		if (activePlayer == player) activePlayer = player2;
		else activePlayer = player;
	}

}

void displayBoard(char b[3][3], int size)
{
	
	cout<<"::Tic Tac Toe::\n\n";

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			cout<<b[x][y];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void grabInput(char player)
{
	cout<<"Enter your move "<<player<<": ";
	cin>>currentMove;
}

void updateBoard(char b[3][3], int /*size*/, char player, char currentMove)
{
	if (currentMove > '0' && currentMove <= '9')
		b[0][currentMove - '1'] = player;
}

void checkWin()
{
	if (b[0][0] == 'X' && b[0][1] == 'X' && b[0][2] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}
	if (b[1][0] == 'X' && b[1][1] == 'X' && b[1][2] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}
	if (b[2][0] == 'X' && b[2][1] == 'X' && b[2][2] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}

	if (b[0][0] == 'X' && b[1][0] == 'X' && b[2][0] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}
	if (b[0][1] == 'X' && b[1][1] == 'X' && b[2][1] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}
	if (b[0][2] == 'X' && b[1][2] == 'X' && b[2][2] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}

	if (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}
	if (b[0][2] == 'X' && b[1][1] == 'X' && b[2][0] == 'X')
	{
			cout<<"\nPlayer 1 Wins!\n\n";
			hasWon = true;
	}


	if (b[0][0] == 'O' && b[0][1] == 'O' && b[0][2] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[1][0] == 'O' && b[1][1] == 'O' && b[1][2] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[2][0] == 'O' && b[2][1] == 'O' && b[2][2] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'O' && b[1][0] == 'O' && b[2][0] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][1] == 'O' && b[1][1] == 'O' && b[2][1] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'O' && b[1][2] == 'O' && b[2][2] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}

	if (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}
	if (b[0][2] == 'O' && b[1][1] == 'O' && b[2][0] == 'O')
	{
		cout<<"\nPlayer Wins!\n\n";
		hasWon = true;
	}

}

void checkDraw()
{
	if (b[0][0] != '1' && b[0][1] != '2' && b[0][2] != '3' && b[1][0] != '4' && b[1][1] != '5' && b[1][2] != '6' &&
		b[2][0] != '7' && b[2][1] != '8' && b[2][2] != '9' && !hasWon)
	hasDrawn = true;
	if (hasDrawn)
	{
		cout<<"\nThe game is a draw!\n\n";
		cin.get();
	}
}

