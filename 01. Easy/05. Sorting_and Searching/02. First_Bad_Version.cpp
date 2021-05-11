#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version)
{
    // Based on the test case we have to change the value of version
    if (version >= 4)
        return true;
    return false;
}

int helper(int start, int end)
{
    if (start == end)
        return start;
    int mid = (start / 2) + (end / 2);
    if (isBadVersion(mid))
        return helper(start, mid);
    return helper(mid + 1, end);
}

int firstBadVersion(int n)
{
    return helper(1, n);
}

int main()
{
    cout << firstBadVersion(5) << "\n";
    return 0;
}