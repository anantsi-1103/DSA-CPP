#include <iostream>
using namespace std;
const int N = 9;

bool isSafe(int board[N][N], int row, int col, int num)
{
    // row
    for (int j = 0; j < N; j++)
    {
        if (board[row][j] == num)
            return false;
    }
    // col
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    // cell -> 
    int sr = (row/3) * 3;
    int sc = (col/3) * 3;

    for(int i = sr; i<sr+3 ; i++){
        for(int j = sc ; j < sc + 3 ; j++){
            if(board[i][j] == num){
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolv(int board[N][N], int row, int col)
{
    if (row == N)
    {
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if (nextCol == N)
    {
        nextRow++;
        nextCol = 0;
    }

    if (board[row][col] != 0)
    {
        return sudokuSolv(board, nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;

            if (sudokuSolv(board, nextRow, nextCol))
                return true;
        }
        board[row][col] = 0;
    }

    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int board[N][N] =
        {
            {9, 1, 3, 0, 0, 0, 5, 0, 0},
            {6, 0, 7, 0, 0, 0, 0, 2, 4},
            {0, 5, 0, 0, 8, 0, 0, 7, 0},

            {0, 7, 9, 0, 0, 0, 0, 0, 0},
            {0, 0, 2, 0, 9, 0, 0, 4, 3},
            {0, 0, 0, 0, 0, 4, 0, 9, 0},

            {0, 4, 0, 0, 0, 1, 9, 0, 0},
            {7, 0, 6, 0, 0, 9, 0, 0, 5},
            {0, 0, 1, 0, 0, 6, 4, 0, 7}};

   
    if(sudokuSolv(board,0,0)){
        cout<<"Sudoku Solver: \n";
        printBoard(board);
    }
    else{
        cout<< "No Solution Exist \n";
    }

    return 0;
}