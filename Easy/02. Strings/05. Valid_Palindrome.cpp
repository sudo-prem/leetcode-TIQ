#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0, j = s.size() - 1;
    while (i <= j)
    {
        while (!isalpha(s[i]) and !isdigit(s[i]) and i <= j)
            i++;
        while (!isalpha(s[j]) and !isdigit(s[j]) and i <= j)
            j--;
        if (s[i] != s[j] and i <= j)
            return false;
        i++;
        j--;
    }
    return true;
}

void solve()
{
    string s{"race a car"}, res{};
    res = isPalindrome(s) ? "True\n" : "False\n";
    cout << res;
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