#include <iostream>
using namespace std;

#define SIZE 3
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int player = 1;
bool isOver = false;
bool isDraw = false;
void showBoard();
void update(int* x, int* y);
bool checkBoard();
void start();


int main()
{
	cout << "\t LET'S PLAY CARO" << endl;
	cout << "PLAYER 1 - [X] \t PLAYER 2 - [O]\n" << endl;
	start();

	while (!isOver)
	{
		int x, y;
		update(&x, &y);
		showBoard();
		isOver = checkBoard();

		if (isOver)
		{
			if (isDraw)
				cout << "-----Draw-----";
			else
				cout << "-----Player " << player<< " is winner-----" << endl;
		}
	}
}
void showBoard()
{
	cout << "-------------" << endl;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		for (unsigned int j = 0; j < SIZE; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------" << endl;
	}
}

void update(int* x, int* y)
{
	char mark;
	player = (player % 2) ? 1 : 2;
	mark = (player == 1) ? 'X' : 'O';

	int position;
	do 
	{
		cout << "Player " << player << ", please input cell position (1-9): ";
		cin >> position;
		*x = (position - 1) / SIZE;
		*y = (position - 1) % SIZE;
	} while (position < 1 || position > 9 || board[*x][*y] != ' ');

	board[*x][*y] = mark;
	player++;
}

bool checkBoard()
{
	if (board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][1] == board[0][2])
		return true;
	else if (board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][1] == board[1][2])
		return true;
	else if (board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][1] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][0] && board[1][0] == board[2][0])
		return true;
	else if (board[0][1] != ' ' && board[0][1] == board[1][1] && board[1][1] == board[2][1])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][2] && board[1][2] == board[2][2])
		return true;
	else if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return true;
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return true;
	else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
	{
		isDraw = true;
		return true;
	}
	return false;
}
void start(){
	int cnt = 1;
	cout << "-------------" << endl;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		for (unsigned int j = 0; j < SIZE; j++)
		{
			cout << "| " << cnt << " ";
			cnt++;
		}
		cout << "|" << endl;
		cout << "-------------" << endl;
	}
}