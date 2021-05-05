#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val) {}
};

class linkedList
{
private:
    ListNode *root;

public:
    linkedList() : root(NULL) {}
    ListNode *getRoot() { return root; }
    void Insert(int);
    void Display();
    void deleteNode(ListNode *);
};

void linkedList::Insert(int val)
{
    ListNode *temp = new ListNode(val);
    if (!this->root)
    {
        root = temp;
        return;
    }
    ListNode *t = root;
    while (t->next)
        t = t->next;
    t->next = temp;
}

void linkedList::Display()
{
    ListNode *t = root;
    cout << "[ ";
    while (t)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << "]\n";
}

void linkedList::deleteNode(ListNode *node)
{
    // for submission change Node to ListNode
    ListNode *prev = node;
    node = node->next;
    while (node->next)
    {
        prev->val = node->val;
        prev = node;
        node = node->next;
    }
    prev->val = node->val;
    prev->next = NULL;
}

void solve()
{
    vector<int> vec{4, 5, 1, 9};
    linkedList LL;
    for (auto i : vec)
        LL.Insert(i);
    LL.Display();
    ListNode *node = LL.getRoot();
    node = node->next;
    LL.deleteNode(node);
    LL.Display();
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