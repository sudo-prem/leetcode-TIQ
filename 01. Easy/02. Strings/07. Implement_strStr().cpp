#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int strStr(string haystack, string needle)
{
    int index{}, i{}, haySize = haystack.size(), needleSize = needle.size();
    if (needleSize == 0)
        return 0;
    if (needleSize > haySize)
        return -1;
    for (i = 0; i < haySize; ++i)
    {
        if (haystack[i] == needle[0])
        {
            bool flag = true;
            int j{};
            index = i;
            while ((i + j < haySize and j < needleSize) and (haystack[i + j] == needle[j]))
            {
                j++;
                cout << haystack[i + j] << ": " << needle[j - 1] << endl;
            }
            if (j == needleSize)
                return index;
        }
    }
    return -1;
}

void solve()
{
    string haystack{"aaabaaabbbabaa"}, needle{"babb"};
    cout << strStr(haystack, needle) << endl;
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