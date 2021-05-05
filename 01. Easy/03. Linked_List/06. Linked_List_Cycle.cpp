#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : next(NULL) {}
};

void Insert(ListNode *head, int val)
{
    ListNode *temp = new ListNode(val);
    if (!head)
    {
        head = temp;
        return;
    }
    ListNode *t = head;
    while (t->next)
        t = t->next;
    t->next = temp;
}

bool hasCycle(ListNode *head)
{
    if (!head or !head->next)
        return false;
    ListNode *p{head->next->next}, *q{head->next};
    while (p != q and p and p->next)
    {
        p = p->next->next;
        q = q->next;
    }
    if (p == q)
        return true;
    return false;
}

void solve()
{
    vector<int> vec{};
    ListNode *head = new ListNode;
    for (auto i : vec)
        Insert(head, i);
    ListNode *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head->next;
    string res = hasCycle(head) == true ? "True\n" : "False\n";
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