#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL) {}
};

// Re-Wiring
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;
    ListNode *evenStart{NULL}, *evenEnd{NULL}, *oddStart{NULL}, *oddEnd{NULL};
    int count = 1;
    while (head)
    {
        if (count & 1)
        {
            if (!oddStart)
            {
                oddStart = head;
                oddEnd = head;
            }
            else
            {
                oddEnd->next = head;
                oddEnd = oddEnd->next;
            }
            head = head->next;
            oddEnd->next = NULL;
        }
        else
        {
            if (!evenStart)
            {
                evenStart = head;
                evenEnd = head;
            }
            else
            {
                evenEnd->next = head;
                evenEnd = evenEnd->next;
            }
            head = head->next;
            evenEnd->next = NULL;
        }
        count++;
    }
    oddEnd->next = evenStart;
    return oddStart;
}

int main()
{
    // [ 2, 1, 3, 5, 6, 4, 7 ]
    // [1, 2, 3, 4, 5]

    ListNode *head = new ListNode(2), *temp;
    temp = head;
    temp->next = new ListNode(1);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(6);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(7);

    ListNode *res = oddEvenList(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}