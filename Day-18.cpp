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

// Sort a linked list of 0s, 1s and 2s
Node *segregate(Node *head)
{

    // Add code here
    Node *prev = head;
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            swap(curr->data, prev->data);
            prev = prev->next;
        }
        curr = curr->next;
    }

    prev = head;
    while (prev->data == 0)
    {
        prev = prev->next;
    }

    curr = prev;

    while (curr != NULL)
    {
        if (curr->data == 1)
        {
            swap(curr->data, prev->data);
            prev = prev->next;
        }
        curr = curr->next;
    }

    return head;
}
// Convert Binary Number in a Linked List to Integer

int getDecimalValue(ListNode *head)
{
    int num = 0;
    while (head != NULL)
    {
        if (head->val == 0)
        {
            num = num * 2;
        }
        else
        {
            num = (num * 2) + 1;
            cout << " second : " << num;
        }
        head = head->next;
    }
    return num;
}
// Remove Linked List Elements

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->val == val && prev == NULL)
        {
            head = curr->next;
            curr = head;
        }
        else if (curr->val == val)
        {
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

// Multiply two linked lists

long long multiplyTwoLists(Node *first, Node *second)
{
    // code here
    long long val1 = 0;
    long long val2 = 0;
    Node *temp1 = first;
    Node *temp2 = second;

    while (temp1 != NULL)
    {
        val1 = temp1->data + ((val1 * 10) % 1000000007);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        val2 = temp2->data + ((val2 * 10) % 1000000007);
        temp2 = temp2->next;
    }

    long long ans = (val1 * val2) % 1000000007;
    return ans;
}

int main()
{

    return 0;
}