#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Solution 1: Uses extra long long which makes it faster but in most cases it should not be allowed
// int reverse(int x)
// {
//     long long res{};
//     while (x)
//     {
//         res = (res * 10);
//         if (res >= INT_MAX or res <= INT_MIN)
//             return 0;
//         res += (x % 10);
//         x /= 10;
//     }
//     return res;
// }

// Solution 2: Here we do not use long long but check if it is not overloading, before multiplying res by 10;
int reverse(int x)
{
    int res{}, max{INT_MAX / 10}, min{INT_MIN / 10};
    while (x)
    {
        if (max < res or min > res)
            return 0;
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve()
{
    int n{-123};
    // int n{1534236469};
    cout << reverse(n) << endl;
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