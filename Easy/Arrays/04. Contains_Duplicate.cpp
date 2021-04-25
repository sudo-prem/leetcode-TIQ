#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool containsDuplicate(vector<int> &nums)
{
    vector<int> hash;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (find(hash.begin(), hash.end(), nums[i]) != hash.end())
            return true;
        hash.push_back(nums[i]);
    }
    return false;
}

void solve()
{
    vector<int> nums{1, 2, 3, 1};
    if (containsDuplicate(nums))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
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