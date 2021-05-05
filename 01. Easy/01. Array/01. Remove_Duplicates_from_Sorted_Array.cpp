#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return n;
    auto i = nums.begin();
    while (i + 1 != nums.end())
    {
        if (*i == *(i + 1))
        {
            nums.erase(i);
            n--;
        }
        else
            i++;
    }
    return n;
}

void solve()
{
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = removeDuplicates(nums);
    cout << "[ ";
    for (int i = 0; i < n; ++i)
        cout << nums[i] << " ";
    cout << "]\n";
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