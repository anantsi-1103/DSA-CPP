#include <iostream>
using namespace std;

const int N = 5;

void printBoard(char board[N][N])
{
    cout << " -------- --------- ----------- \n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(char board[N][N], int row, int col)
{
    // vertical up
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    // left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; j--, i--)
    {

        if (board[i][j] == 'Q')
            return false;
    }
    // right

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; j++, i--)
    {

        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

bool solveQueen(char board[N][N], int row)
{

    // base case
    if (row == N)
    {
        printBoard(board);
        return true;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';

            if (solveQueen(board, row + 1))
                return true;
        }
        board[row][col] = 'x';
    }
    return false;
}
int main()
{

    char board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 'x';
        }
    }

    
    solveQueen(board, 0);

    return 0;
}