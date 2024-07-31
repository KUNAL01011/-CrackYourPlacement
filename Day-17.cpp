#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int *next;
    int *prev;
    int val;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Middle of the Linked List
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

// Linked List Cycle
bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

// Remove Duplicates from Sorted List
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    ListNode *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->val == temp->next->val)
        {
            ListNode *nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

// Merge Two Sorted Lists
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == 0)
        return list2;
    if (list2 == 0)
        return list1;

    ListNode *ans = new ListNode(-1);
    ListNode *mptr = ans;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            mptr->next = list1;
            mptr = list1;
            list1 = list1->next;
        }
        else
        {
            mptr->next = list2;
            mptr = list2;
            list2 = list2->next;
        }
    }

    if (list1)
    {
        mptr->next = list1;
    }
    if (list2)
    {
        mptr->next = list2;
    }

    return ans->next;
}

int main()
{

    return 0;
}