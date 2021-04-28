#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> plusOne(vector<int> &digits)
{
    vector<int> res;
    int carry{1};
    auto i = digits.rbegin();
    while (i != digits.rend())
    {
        int value = (*(i) + carry);
        res.push_back(value % 10);
        carry = value / 10;
        i++;
    }
    if (carry)
        res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
}

void solve()
{
    vector<int> digits{4, 3, 2, 1}, res;
    res = plusOne(digits);
    for (auto i : res)
        cout << i << " ";
    cout << "\n";
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