#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *random;
    int val;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Node
{
public:
    int data;
    Node *next;
    int val;
    Node *child;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Sort List
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
ListNode *findMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = findMid(head);

    ListNode *left = head;
    ListNode *right = mid->next;

    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    ListNode *merge = mergeTwoLists(left, right);
    return merge;
}

// Remove Duplicates from Sorted List II
ListNode *deleteDuplicates(ListNode *head)
{
    map<int, int> mp;
    ListNode *temp = head;

    while (temp)
    {
        mp[temp->val]++;
        temp = temp->next;
    }

    temp = head;
    ListNode *prev = NULL;

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            temp->val = it.first;
            prev = temp;
            temp = temp->next;
        }
    }
    if (prev == NULL)
    {
        return NULL;
    }
    else
    {
        prev->next = NULL;
    }
    return head;
}

// Reorder List
ListNode *getMid(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *ahead = NULL;

    while (cur != NULL)
    {
        ahead = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ahead;
    }
    return prev;
}

void merge(ListNode *&head1, ListNode *&head2)
{
    ListNode *h1next;
    ListNode *h2next;

    while (head1 != NULL and head2 != NULL)
    {
        h1next = head1->next;
        h2next = head2->next;

        head1->next = head2;
        head2->next = h1next;

        head1 = h1next;
        head2 = h2next;
    }
}

void reorderList(ListNode *head)
{
    if (!head)
        return;

    // step 1 -> get middle
    ListNode *middle = getMid(head);

    // step 2 -> reverse from the next of middle
    ListNode *temp = middle->next;
    middle->next = reverseLL(temp);

    // step 3 -> merge the two halves
    ListNode *firstHalf = head;
    ListNode *secondHalf = middle->next;

    middle->next = NULL;

    merge(firstHalf, secondHalf);
}

// Segregate even and odd nodes in a Linked List
Node *divide(Node *head)
{
    // code here
    vector<int> even;
    vector<int> odd;

    Node *temp = head;
    while (temp)
    {
        if (temp->data & 1)
        {
            odd.push_back(temp->data);
        }
        else
        {
            even.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head;
    for (auto v : even)
    {
        temp->data = v;
        temp = temp->next;
    }
    for (auto v : odd)
    {
        temp->data = v;
        temp = temp->next;
    }

    return head;
}

int main()
{

    return 0;
}