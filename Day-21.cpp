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

// Partition List
ListNode *partition(ListNode *head, int x)
{
    vector<int> less;
    vector<int> greter;

    ListNode *curr = head;

    while (curr)
    {
        if (curr->val < x)
        {
            less.push_back(curr->val);
        }
        else
        {
            greter.push_back(curr->val);
        }
        curr = curr->next;
    }
    curr = head;
    int i = 0;
    while (i < less.size())
    {
        curr->val = less[i];
        i++;
        curr = curr->next;
    }
    int j = 0;
    while (j < greter.size())
    {
        curr->val = greter[j];
        j++;
        curr = curr->next;
    }

    return head;
}

// Remove Nth Node From End of List
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == n)
        return head->next;
    int pos = cnt - n;
    temp = head;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp->next = temp->next->next;
    return head;
}

// Flatten a Multilevel Doubly Linked List
Node *flatten(Node *head)
{
    Node *curr = head;
    Node *tail = head;

    stack<Node *> st;
    while (curr != NULL)
    {
        if (curr->child != NULL)
        {
            Node *child = curr->child;

            if (curr->next != NULL)
            {
                st.push(curr->next);
                curr->next->prev = NULL;
            }
            curr->next = child;
            child->prev = curr;
            curr->child = NULL;
        }
        tail = curr;
        curr = curr->next;
    }

    while (!st.empty())
    {
        curr = st.top();
        st.pop();
        tail->next = curr;
        curr->prev = tail;

        while (curr != NULL)
        {
            tail = curr;
            curr = curr->next;
        }
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

int main()
{

    return 0;
}