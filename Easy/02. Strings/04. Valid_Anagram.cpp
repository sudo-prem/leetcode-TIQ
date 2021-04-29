#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// If the strings only contain alphabets
// bool isAnagram(string s, string t)
// {
//     vector<int> hash(26, 0);
//     int size = s.size();
//     if (t.size() != size)
//         return false;
//     for (int i = 0; i < size; ++i)
//     {
//         hash[s[i] - 'a']++;
//         hash[t[i] - 'a']--;
//     }
//     for (int i = 0; i < 26; ++i)
//         if (hash[i] != 0)
//             return false;
//     return true;
// }

// if the strings contained unicode also
bool isAnagram(string s, string t)
{
    if (t.size() != s.size())
        return false;
    vector<char> hashChar{};
    vector<int> hashCount{};
    for (int i = 0; i < s.size(); ++i)
    {
        auto x = find(hashChar.begin(), hashChar.end(), s[i]);
        if (x != hashChar.end())
            hashCount[x - hashChar.begin()]++;
        else
        {
            hashChar.push_back(s[i]);
            hashCount.push_back(1);
        }
        auto y = find(hashChar.begin(), hashChar.end(), t[i]);
        if (y != hashChar.end())
            hashCount[y - hashChar.begin()]--;
        else
        {
            hashChar.push_back(t[i]);
            hashCount.push_back(-1);
        }
    }
    for (auto i : hashCount)
        if (i != 0)
            return false;
    return true;
}

void solve()
{
    string s{"1anagram%"}, t{"na1g%aram"}, res{};
    res = isAnagram(s, t) ? "True\n" : "False\n";
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