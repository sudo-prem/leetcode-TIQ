#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void rotate(vector<int> &nums, int k)
{
    int s = nums.size() - 1;
    k %= s + 1;
    int fEnd = s - k;
    for (int i = 0; i <= fEnd / 2; ++i)
    {
        int temp = nums[i];
        nums[i] = nums[fEnd - i];
        nums[fEnd - i] = temp;
    }
    for (int i = 0; i < (k / 2); ++i)
    {
        int temp = nums[fEnd + i + 1];
        nums[fEnd + i + 1] = nums[s - i];
        nums[s - i] = temp;
    }
    for (int i = 0; i <= s / 2; ++i)
    {
        int temp = nums[i];
        nums[i] = nums[s - i];
        nums[s - i] = temp;
    }
}

void solve()
{
    vector<int> nums{1};
    int k = 40;
    rotate(nums, k);
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