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
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Add Two Numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
}

// Copy List with Random Pointer
Node *copyRandomList(Node *head)
{
    if (!head)
        return 0;

    // Generating the copy list for next elements
    Node *it = head;
    while (it)
    {
        Node *clonedNode = new Node(it->val);
        clonedNode->next = it->next;
        it->next = clonedNode;
        it = it->next->next;
    }

    // Generating the copy list for random elements
    it = head;
    while (it)
    {
        Node *clonedNode = it->next;
        clonedNode->random = it->random ? it->random->next : nullptr;
        it = it->next->next;
    }

    // Converting the list into original form
    it = head;
    Node *clonHead = it->next;
    while (it)
    {
        Node *temp = it->next;
        it->next = it->next->next;
        if (temp->next)
        {
            temp->next = temp->next->next;
        }
        it = it->next;
    }
    return clonHead;
}

// Add Two Numbers II
ListNode *reverse(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;

    while (curr)
    {
        ListNode *NextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = NextNode;
    }

    return prev;
}
ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head1 = reverse(l1);
    ListNode *head2 = reverse(l2);
    ListNode *Sum = AddTwoNumbers(head1, head2);
    ListNode *Ans = reverse(Sum);

    return Ans;
}

// Reverse Linked List II
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    // ListNode* head1 = NULL;
    // ListNode* tail = NULL;
    ListNode *temp = head;
    vector<int> ans;
    while (temp)
    {
        ans.push_back(temp->val);
        temp = temp->next;
    }

    int s = left - 1;
    int e = right - 1;

    while (s <= e)
    {
        swap(ans[s], ans[e]);
        s++;
        e--;
    }

    temp = head;
    int i = 0;
    while (temp && i < ans.size())
    {
        temp->val = ans[i];
        i++;
        temp = temp->next;
    }

    return head;
}

int main()
{

    return 0;
}