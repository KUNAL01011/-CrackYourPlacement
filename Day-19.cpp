#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int val;
};
class ListNode
{
public:
    int data;
    ListNode *next;
    int val;
};

// 1 . Reverse Linked List
ListNode *reverseList(ListNode *head)
{
    if (!head)
        return head;
    ListNode *prev = NULL;
    ListNode *Next = head->next;
    ListNode *curr = head;

    while (curr->next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        Next = Next->next;
    }
    curr->next = prev;
    return curr;
}
// 2 . Palindrome Linked List
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *Next = head->next;
    ListNode *curr = head;

    while (curr->next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        Next = Next->next;
    }
    curr->next = prev;
    return curr;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next)
    {
        fast = fast->next;
        if (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    ListNode *head2 = reverse(slow->next);

    while ((head != NULL && head2 != NULL) && head->val == head2->val)
    {
        head = head->next;
        head2 = head2->next;
    }
    if (head == NULL || head2 == NULL)
    {
        return true;
    }

    return false;
}

// 3 . Delete nodes having greater value on right
Node *compute(Node *head)
{
    if (head->next == nullptr)
        return head;

    head->next = compute(head->next);

    if (head->data < head->next->data)
        return head->next;
    else
        return head;
}
// 4. Intersection of Two Linked Lists

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1->next && temp2->next)
    {
        if (temp1 == temp2)
        {
            return temp2;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1->next == 0)
    {
        int diff = 0;
        while (temp2->next)
        {
            temp2 = temp2->next;
            diff++;
        }

        while (diff--)
        {
            headB = headB->next;
        }
    }
    else
    {
        int diff = 0;
        while (temp1->next)
        {
            diff++;
            temp1 = temp1->next;
        }

        while (diff--)
        {
            headA = headA->next;
        }
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
int main()
{

    return 0;
}