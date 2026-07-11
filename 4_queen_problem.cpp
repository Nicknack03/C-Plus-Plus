#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>>& board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";

        cout << endl;
    }

    cout << endl;
}

bool solveNQueens(int row,
                  int n,
                  vector<vector<int>>& board,
                  vector<int>& column,
                  vector<int>& diagonal1,
                  vector<int>& diagonal2)
{
    if (row == n)
    {
        printBoard(board, n);
        return true;
    }

    bool found = false;

    for (int col = 0; col < n; col++)
    {
        // Check whether current position is safe
        if (!column[col] &&
            !diagonal1[row - col + n - 1] &&
            !diagonal2[row + col])
        {
            board[row][col] = 1;

            column[col] = 1;
            diagonal1[row - col + n - 1] = 1;
            diagonal2[row + col] = 1;

            found = solveNQueens(row + 1,
                                 n,
                                 board,
                                 column,
                                 diagonal1,
                                 diagonal2) || found;

            // Backtrack
            board[row][col] = 0;

            column[col] = 0;
            diagonal1[row - col + n - 1] = 0;
            diagonal2[row + col] = 0;
        }
    }

    return found;
}

int main()
{
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<int> column(n, 0);

    // There are (2*n - 1) diagonals
    vector<int> diagonal1(2 * n - 1, 0);
    vector<int> diagonal2(2 * n - 1, 0);

    bool solution = solveNQueens(
        0,
        n,
        board,
        column,
        diagonal1,
        diagonal2);

    if (!solution)
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}