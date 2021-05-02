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
    vector<vector<int>> levelOrder(TreeNode *root);
};

vector<vector<int>> BinarySearchTree::levelOrder(TreeNode *root)
{
    vector<vector<int>> res{};
    if (!root)
        return res;
    queue<TreeNode *> nodeQ{};
    nodeQ.push(root);
    while (!nodeQ.empty())
    {
        int size = nodeQ.size(), counter{};
        vector<int> vec(size, 0);
        while (size--)
        {
            TreeNode *curr = nodeQ.front();
            nodeQ.pop();
            vec[counter++] = curr->val;
            if (curr->left)
                nodeQ.push(curr->left);
            if (curr->right)
                nodeQ.push(curr->right);
        }
        res.push_back(vec);
    }
    return res;
}

void solve()
{
    BinarySearchTree *tree = new BinarySearchTree();
    tree->root = new TreeNode(3);
    tree->root->left = new TreeNode(9);
    tree->root->right = new TreeNode(20);
    tree->root->right->left = new TreeNode(15);
    tree->root->right->right = new TreeNode(7);

    vector<vector<int>> res = tree->levelOrder(tree->root);
    cout << "[ ";
    for (auto i : res)
    {
        cout << "[ ";
        for (auto j : i)
            cout << j << " ";
        cout << "] ";
    }
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
