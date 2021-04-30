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
    ListNode *reverseList(ListNode *head);
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

// Recursice Approach
// Time Complexity: O(n)
// Space Complexity: O(n) (Due to Implicit Stack)
ListNode *linkedList::reverseList(ListNode *head)
{
    // if head == NULL, returns NULL
    // if head->next == NULL, it has reached the last node(New Head Node), returns last node(head)
    if (!head or !head->next)
        return head;
    // Traverses till the last node
    ListNode *temp = reverseList(head->next);
    // reverses the link
    head->next->next = head;
    head->next = NULL;
    return temp;
}

// // Iterative Approach
// // Time Complexity: O(n)
// // Space Complexity: O(1)
// ListNode *linkedList::reverseList(ListNode *head)
// {
//     ListNode *p = head, *q{NULL}, *r{NULL};
//     while (p)
//     {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }
//     return q;
// }

void solve()
{
    vector<int> vec{1, 2, 3, 4, 5};
    linkedList LL;
    for (auto i : vec)
        LL.Insert(i);
    LL.Display();
    ListNode *head = LL.getRoot();
    LL.setRoot(LL.reverseList(head));
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