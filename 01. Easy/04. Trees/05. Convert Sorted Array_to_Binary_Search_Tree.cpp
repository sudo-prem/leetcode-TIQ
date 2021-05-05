#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TreeNode
{
public:
    int val{};
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

TreeNode *helper(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = helper(nums, start, mid - 1);
    node->right = helper(nums, mid + 1, end);
    return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    return helper(nums, 0, nums.size() - 1);
}

void preOrder(TreeNode *root)
{
    if (root)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void solve()
{
    vector<int> nums{-10, -3, 0, 5, 9};
    TreeNode *res = sortedArrayToBST(nums);
    preOrder(res);
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