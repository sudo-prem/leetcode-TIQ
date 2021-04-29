#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int firstUniqChar(string s)
{
    vector<int> hash(26, 0);
    int size = s.size();
    for (int i = 0; i < size; ++i)
        hash[s[i] - 'a']++;
    for (int i = 0; i < size; ++i)
        if (hash[s[i] - 'a'] == 1)
            return i;
    return -1;
}

void solve()
{
    // string s{"leetcode"}; // 0
    string s{"loveleetcode"}; // 2
    cout << firstUniqChar(s) << endl;
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