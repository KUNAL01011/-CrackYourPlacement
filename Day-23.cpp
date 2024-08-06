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
// Rearrange a given linked list in-place.
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

// Merge k Sorted Lists
class compare
{
public:
    bool operator()(ListNode *data1, ListNode *data2)
    {
        return data1->val > data2->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        ListNode *listHead = lists[i];
        if (listHead != NULL)
        {
            pq.push(listHead);
        }
    }

    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (!pq.empty())
    {
        ListNode *topNode = pq.top();
        pq.pop();

        if (head == NULL)
        {
            head = topNode;
            tail = topNode;

            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
            if (tail->next != NULL)
            {
                pq.push(tail->next);
            }
        }
    }
    return head;
}


// Reverse Nodes in k-Group
int length(ListNode *head)
{
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int len = length(head);
    if (len < k)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nextNode = curr->next;
    int pos = 0;

    while (pos < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }
    if (nextNode != NULL)
    {
        ListNode *recAns = reverseKGroup(nextNode, k);
        head->next = recAns;
    }
    return prev;
}

// Subtraction in Linked List
Node *subLinkedList(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    // Remove leading zeros
    head1 = removeLeadingZeros(head1);
    head2 = removeLeadingZeros(head2);

    // Calculate lengths
    int n1 = length(head1);
    int n2 = length(head2);

    // Ensure head1 points to the larger number
    if (n2 > n1 || (n1 == n2 && compare(head1, head2) < 0))
        swap(head1, head2);

    // Reverse the lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    // Perform subtraction
    head1 = subtractLists(head1, head2);

    // Reverse the result list
    head1 = reverse(head1);

    // Remove leading zeros
    head1 = removeLeadingZeros(head1);

    // If the result is empty, return a zero node
    if (!head1)
        return new Node(0);

    return head1;
}

Node *removeLeadingZeros(Node *head)
{
    while (head && head->data == 0)
        head = head->next;
    return head ? head : new Node(0);
}

int length(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *reverse(Node *head)
{
    Node *prev = NULL, *curr = head, *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int compare(Node *head1, Node *head2)
{
    while (head1 && head2)
    {
        if (head1->data != head2->data)
            return head1->data - head2->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

Node *subtractLists(Node *head1, Node *head2)
{
    Node *tail1 = head1, *tail2 = head2;
    int carry = 0;
    while (tail1)
    {
        int t2 = tail2 ? tail2->data : 0;
        int diff = tail1->data + carry - t2;
        if (diff < 0)
        {
            diff += 10;
            carry = -1;
        }
        else
        {
            carry = 0;
        }
        tail1->data = diff;
        tail1 = tail1->next;
        if (tail2)
            tail2 = tail2->next;
    }
    return head1;
}
int main()
{

    return 0;
}