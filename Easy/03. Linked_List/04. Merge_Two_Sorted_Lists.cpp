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
    void setRoot(ListNode *node) { this->root = node; }
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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    ListNode *l = l1->val < l2->val ? l1 : l2;
    l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
    ListNode *l3 = l;
    while (l1 and l2)
    {
        if (l1->val < l2->val)
        {
            l3->next = l1;
            l3 = l3->next;
            l1 = l1->next;
        }
        else
        {
            l3->next = l2;
            l3 = l3->next;
            l2 = l2->next;
        }
    }
    if (l1)
        l3->next = l1;
    else if (l2)
        l3->next = l2;
    return l;
}

void solve()
{
    linkedList L1, L2, L3;
    vector<int> vec1{1, 2, 4}, vec2{1, 3, 4};
    for (auto i : vec1)
        L1.Insert(i);
    for (auto i : vec2)
        L2.Insert(i);
    L1.Display();
    L2.Display();
    L3.setRoot(mergeTwoLists(L1.getRoot(), L2.getRoot()));
    L3.Display();
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