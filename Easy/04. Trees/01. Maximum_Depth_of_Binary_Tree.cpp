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

class Tree
{
public:
    TreeNode *root;
    Tree() : root(NULL) {}
    int maxDepth(TreeNode *root);
};

int Tree::maxDepth(TreeNode *root)
{
    if (root)
    {
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return x > y ? x + 1 : y + 1;
    }
    return 0;
}

void solve()
{
    Tree *tree = new Tree();
    tree->root = new TreeNode(3);
    tree->root->left = new TreeNode(9);
    tree->root->right = new TreeNode(20);
    tree->root->right->left = new TreeNode(15);
    tree->root->right->right = new TreeNode(7);
    cout << tree->maxDepth(tree->root) << endl;
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