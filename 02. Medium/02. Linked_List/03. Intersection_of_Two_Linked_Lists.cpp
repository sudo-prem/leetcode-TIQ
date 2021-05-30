#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int v) : val(v), next(NULL) {}
};

// Method 1
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b)
    {
        if (!a)
            a = headB;
        else
            a = a->next;
        if (!b)
            b = headA;
        else
            b = b->next;
    }

    return a;
}

// // Method 2
// // If Auxiliary Stack is allowed
// ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
// {
//     stack<ListNode *> st1, st2;
//     ListNode *res{NULL};
//     while (headA)
//     {
//         st1.push(headA);
//         headA = headA->next;
//     }
//     while (headB)
//     {
//         st2.push(headB);
//         headB = headB->next;
//     }
//     while (st1.top() == st2.top() and st1.top() != NULL)
//     {
//         res = st1.top();
//         st1.pop();
//         st2.pop();
//     }
//     return res;
// }

int main()
{
    // [4,1,8,4,5]
    // [5,6,1,8,4,5]
    ListNode *headA, *headB, *tempA, *tempB, *intersect, *end;
    // Assigning values to headA
    headA = new ListNode(4);
    tempA = headA;
    tempA->next = new ListNode(1);
    tempA = tempA->next;

    // Assigning values to headB
    headB = new ListNode(5);
    tempB = headB;
    tempB->next = new ListNode(6);
    tempB = tempB->next;
    tempB->next = new ListNode(1);
    tempB = tempB->next;

    intersect = new ListNode(8);
    end = intersect;
    end->next = new ListNode(4);
    end = end->next;
    end->next = new ListNode(5);

    tempA->next = intersect;
    tempB->next = intersect;

    // Checking the correctness of the function
    ListNode *res = getIntersectionNode(headA, headB);
    cout << res->val << endl;

    return 0;
}