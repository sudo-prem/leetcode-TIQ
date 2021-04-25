#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void rotate(vector<vector<int>> &matrix)
{
    int s = matrix.size();
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < i + 1; ++j)
            swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < s; ++i)
        for (int j = 0; j < s / 2; ++j)
            swap(matrix[i][j], matrix[i][s - j - 1]);
}

void solve()
{
    vector<vector<int>> matrix{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
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