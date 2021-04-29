#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string longestCommonPrefix(vector<string> &strs)
{
    string res{};
    int i{};
    while (i < strs[0].size())
    {
        char curr = strs[0][i];
        for (auto j : strs)
        {
            if (i > j.size() or j[i] != curr)
                return res;
        }
        res += curr;
        i++;
    }
    return res;
}

void solve()
{
    // vector<string> strs{"flower", "flow", "flight"};
    vector<string> strs{"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs) << endl;
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