#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = nums1.size() - 1, j = nums2.size() - 1;
    while (i >= 0 and j >= 0)
    {
        while (nums1[i] < nums2[j])
        {
            if (j == 0)
                return res;
            j--;
        }
        while (nums1[i] > nums2[j])
        {
            if (i == 0)
                return res;
            i--;
        }
        if (nums1[i] == nums2[j])
        {
            res.push_back(nums1[i]);
            i--;
            j--;
        }
    }
    return res;
}

void solve()
{
    vector<int> nums1{9, 3, 7}, nums2{6, 4, 1, 0, 0, 4, 4, 8, 7}, res;
    res = intersect(nums1, nums2);
    for (auto i : res)
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