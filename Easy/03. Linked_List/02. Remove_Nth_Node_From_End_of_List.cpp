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
    ListNode *removeNthFromEnd(ListNode *, int);
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

ListNode *linkedList::removeNthFromEnd(ListNode *head, int n)
{
    n--;
    ListNode *fast = head, *slow = head, *prev = head;
    while (n--)
        fast = fast->next;
    while (fast->next)
    {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if (slow == head)
        return slow->next;
    prev->next = slow->next;
    return head;
}

void solve()
{
    vector<int> vec{1, 2, 3, 4, 5};
    linkedList LL;
    for (auto i : vec)
        LL.Insert(i);
    LL.Display();
    ListNode *head = LL.getRoot();
    LL.setRoot(LL.removeNthFromEnd(head, 2));
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