#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinarySearchTree
{
public:
    TreeNode *root;
    BinarySearchTree() : root(NULL) {}
    bool isValidBST(TreeNode *root);
};

// // Approach 1, uses recursion but uses min and max values as a parameter
// bool helper(TreeNode *root, TreeNode *min, TreeNode *max)
// {
//     if (!root)
//         return true;
//     if ((min and root->val < min->val) or (max and root->val > max->val))
//         return false;
//     return helper(root->left, min, root) and helper(root->right, root, max);
// }

// bool BinarySearchTree::isValidBST(TreeNode *root)
// {
//     return helper(root, NULL, NULL);
// }

// Approach 2, uses recursion but does not need min and max values
TreeNode *previous = NULL;

bool BinarySearchTree::isValidBST(TreeNode *root)
{
    // the `previous` TreeNode can be declared as a static member,
    // however it did not work in leetcode
    // static TreeNode *previous = NULL;
    if (!root)
        return true;
    if (!isValidBST(root->left))
        return false;
    if (previous and previous->val >= root->val)
        return false;
    previous = root;
    return isValidBST(root->right);
}

void solve()
{
    BinarySearchTree *tree = new BinarySearchTree();
    // // True
    // tree->root = new TreeNode(2);
    // tree->root->left = new TreeNode(1);
    // tree->root->right = new TreeNode(3);
    // False
    // [5,1,4,null,null,3,6]
    tree->root = new TreeNode(5);
    tree->root->left = new TreeNode(1);
    tree->root->right = new TreeNode(4);
    tree->root->right->left = new TreeNode(3);
    tree->root->right->right = new TreeNode(6);

    string res = tree->isValidBST(tree->root) == true ? "True\n" : "False\n";
    cout << res;
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