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
    bool isSymHelper(TreeNode *root1, TreeNode *root2);
    bool isSymmetric(TreeNode *root);
};

bool BinarySearchTree::isSymHelper(TreeNode *root1, TreeNode *root2)
{
    if (!root1 and !root2)
        return true;
    if (!root1 or !root2)
        return false;
    if (root1->val == root2->val)
        return (isSymHelper(root1->left, root2->right) and isSymHelper(root1->right, root2->left));
    return false;
}

bool BinarySearchTree::isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isSymHelper(root->left, root->right);
}

void solve()
{
    BinarySearchTree *tree = new BinarySearchTree();
    tree->root = new TreeNode(1);
    tree->root->left = new TreeNode(2);
    tree->root->right = new TreeNode(2);

    string res = tree->isSymmetric(tree->root) == true ? "True\n" : "False\n";
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
