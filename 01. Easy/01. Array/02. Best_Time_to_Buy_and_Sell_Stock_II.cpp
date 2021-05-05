#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxProfit(vector<int> &prices)
{
    int profit{};
    auto i = prices.begin();
    while (i + 1 != prices.end())
    {
        if (*i < *(i + 1))
            profit += *(i + 1) - *i;
        i++;
    }
    return profit;
}

void solve()
{
    vector<int> prices{7, 6, 4, 3, 1};
    cout << maxProfit(prices) << "\n";
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