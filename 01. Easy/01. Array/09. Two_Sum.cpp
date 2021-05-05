#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result{};
    int s = nums.size();
    for (int i = 0; i < s; ++i)
    {
        for (int j = i + 1; j < s; ++j)
            if (nums[j] == target - nums[i])
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
    }
    return result;
}

void solve()
{
    vector<int> nums{3, 2, 4}, result{};
    int target{6};
    result = twoSum(nums, target);
    for (auto i : result)
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