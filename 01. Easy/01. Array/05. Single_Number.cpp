#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int singleNumber(vector<int> &nums)
{
    int s = nums.size();
    if (s == 1)
        return nums[0];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < s; i += 2)
        if (nums[i] != nums[i + 1])
            return nums[i];
    return -1;
}

void solve()
{
    vector<int> nums{4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
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