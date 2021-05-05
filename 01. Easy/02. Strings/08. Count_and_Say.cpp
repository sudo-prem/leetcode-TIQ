#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string countNum(string s)
{
    int i{}, size = s.size();
    string res{};
    while (i < size)
    {
        int j = i + 1;
        while (s[j] == s[i])
            j++;
        res.append(to_string(j - i));
        res.append(to_string(s[i] - '0'));
        i += (j - i);
    }
    return res;
}

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    return countNum(countAndSay(n - 1));
}

void solve()
{
    cout << countAndSay(4) << endl;
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