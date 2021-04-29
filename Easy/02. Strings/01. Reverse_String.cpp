#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reverseString(vector<char> &s)
{
    char temp{};
    int n = s.size() - 1;
    int mid = n / 2;
    for (int i = 0; i <= mid; ++i)
    {
        temp = s[i];
        s[i] = s[n - i];
        s[n - i] = temp;
    }
}

void solve()
{
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (auto i : s)
        cout << i << ' ';
    cout << endl;
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