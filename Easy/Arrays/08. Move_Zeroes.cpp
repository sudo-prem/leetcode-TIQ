#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void moveZeroes(vector<int> &nums)
{
    int s = nums.size();
    for (int i = s - 1; i >= 0; --i)
    {
        if (nums[i] == 0)
            for (int j = i; j + 1 < s; ++j)
                swap(nums[j], nums[j + 1]);
    }
}

void solve()
{
    vector<int> nums{0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (auto i : nums)
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