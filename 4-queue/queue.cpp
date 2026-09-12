#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next = NULL;

  ListNode(int val)
  {
    this->val = val;
  }
};

class Queue
{
public:
  ListNode *left = NULL;
  ListNode *right = NULL;

  Queue() {};

  void enqueue(int val)
  {
    ListNode *newNode = new ListNode(val);

    if (right != NULL)
    {
      right->next = newNode;
      right = right->next;
    }
    else
    {
      left = right = newNode;
    }
  }

  int dequeue()
  {
    if (left == nullptr)
    {
      return -1; // Better to throw an exception
    }
    // Remove left node and return value
    int val = left->val;
    left = left->next;
    if (!left)
    {
      right = nullptr;
    }
    return val;
  }

  void print()
  {
    ListNode *curr = left;
    while (curr != nullptr)
    {
      cout << curr->val << " -> ";
      curr = curr->next;
    }
    cout << endl;
  }
};

int main()
{
  return 0;
}