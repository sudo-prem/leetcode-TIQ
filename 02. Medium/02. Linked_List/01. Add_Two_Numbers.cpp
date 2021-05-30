#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (!l1 or !l2)
        return l1 ? l2 : l1;
    ListNode *resHead{}, *resTail{};
    int carry{};
    while (l1 and l2)
    {
        int value = l1->val + l2->val + carry;
        if (!resHead)
        {
            resHead = new ListNode(value % 10);
            resTail = resHead;
        }
        else
        {
            resTail->next = new ListNode(value % 10);
            resTail = resTail->next;
        }
        carry = value / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        int value = l1->val + carry;
        resTail->next = new ListNode((value % 10));
        resTail = resTail->next;
        carry = value / 10;
        l1 = l1->next;
    }
    while (l2)
    {
        int value = l2->val + carry;
        resTail->next = new ListNode((value % 10));
        resTail = resTail->next;
        carry = value / 10;
        l2 = l2->next;
    }
    if (carry)
        resTail->next = new ListNode(carry);
    return resHead;
}

int main()
{
    // [2,4,3]
    // [5,6,4]
    ListNode *head1 = new ListNode(2), *head2 = new ListNode(5), *temp;
    temp = head1;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(3);

    temp = head2;
    temp->next = new ListNode(6);
    temp = temp->next;
    temp->next = new ListNode(4);

    ListNode *res = addTwoNumbers(head1, head2);

    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}