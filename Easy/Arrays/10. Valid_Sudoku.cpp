#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValidSudoku(vector<vector<char>> &board)
{
    vector<vector<bool>> hashRow(9, vector<bool>(10, false));
    vector<vector<bool>> hashCol(9, vector<bool>(10, false));
    vector<vector<vector<bool>>> hashBox(3, vector<vector<bool>>(3, vector<bool>(10, false)));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                int temp = board[i][j] - '0';
                if (hashRow[i][temp])
                    return false;
                if (hashCol[j][temp])
                    return false;
                if (hashBox[i / 3][j / 3][temp])
                    return false;
                hashRow[i][temp] = true;
                hashCol[j][temp] = true;
                hashBox[i / 3][j / 3][temp] = true;
            }
        }
    }
    return true;
}

void solve()
{
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (isValidSudoku(board))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t{1};
    // cin >> t;
    while (t--)
        solve();
    return 0;
}