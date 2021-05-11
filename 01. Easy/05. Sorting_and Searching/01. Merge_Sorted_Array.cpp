#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = nums1.size() - 1;
    n = nums2.size() - 1;
    m = i - n - 1;
    while (m >= 0 and n >= 0 and i >= 0)
        nums1[i--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    while (i >= 0 and n >= 0)
        nums1[i--] = nums2[n--];
}

int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0}, nums2{2, 5, 6};
    // vector<int> nums1{1}, nums2{};
    int m = nums1.size(), n = nums2.size();
    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); ++i)
        cout << nums1[i] << " ";
    cout << "\n";
    return 0;
}