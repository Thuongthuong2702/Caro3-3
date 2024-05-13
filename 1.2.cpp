#include <iostream>
using namespace std;

#define SIZE 3
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int player = 1;
bool isOver = false;
bool isDraw = false;

void start();
void showBoard();
void update(int* x, int* y);
bool checkBoard();




int main()
{
    cout << "\t LET'S PLAY CARO" << endl;
    cout << " Người chơi  1 - [X] \t Người chơi 2 - [O]\n" << endl;

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
                cout << "----- Hai bạn hoà nhau!-----";
            else
                cout << "-----Người chơi " << player << " đã chiến thắng!-----" << endl;
        }
    }
}
void start() {
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
        cout << "Người chơi " << player << ", hãy chọn vị trí ô (1-9): ";
        cin >> position;
        *x = (position - 1) / SIZE;
        *y = (position - 1) % SIZE;
    } while (position < 1 || position > 9 || board[*x][*y] != ' ');

    board[*x][*y] = mark;
    player++;
}

bool checkBoard()
{
    // Kiểm tra các điều kiện thắng
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true; // hàng ngang
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true; // hàng dọc
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true; // đường chéo chính
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true; // đường chéo phụ

    // Kiểm tra hòa
    int emptyCells = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                emptyCells++;
        }
    }
    if (emptyCells == 0)
    {
        isDraw = true;
        return true; // Hòa
    }

    return false; // Chưa kết thúc
}

