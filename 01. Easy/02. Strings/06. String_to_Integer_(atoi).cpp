#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int myAtoi(string s)
{
    int res{}, sign{1}, size = s.size(), i{};
    while (i < size and s[i] == ' ')
        i++;
    if (i < size and (s[i] == '-' or s[i] == '+'))
        sign = (s[i++] == '-') ? -1 : +1;
    while (i < size and isdigit(s[i]))
    {
        if (INT_MAX / 10 < res or (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            return sign == -1 ? INT_MIN : INT_MAX;
        res = (res * 10) + (s[i++] - '0');
    }
    return sign * res;
}

void solve()
{
    cout << myAtoi("-2147483648") << endl;
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