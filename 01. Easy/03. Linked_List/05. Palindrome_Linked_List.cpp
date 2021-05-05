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
    bool isPalindrome(ListNode *);
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

ListNode *Reverse(ListNode *head)
{
    if (!head or !head->next)
        return head;
    ListNode *temp = Reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
bool linkedList::isPalindrome(ListNode *head)
{

    if (!head)
        return false;
    if (!head->next)
        return true;
    ListNode *p{head}, *q{head};
    while (p and p->next)
    {
        p = p->next->next;
        q = q->next;
    }
    if (p)
        q = q->next;
    q = Reverse(q);
    p = head;
    while (p and q)
    {
        if (p->val != q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return true;
}

void solve()
{
    linkedList LL;
    vector<int> vec{1};
    for (auto i : vec)
        LL.Insert(i);
    LL.Display();
    string s = (LL.isPalindrome(LL.getRoot()) == true) ? "True\n" : "False\n";
    LL.Display();
    cout << s;
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