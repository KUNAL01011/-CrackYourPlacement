#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int val)
  {
    this->val = val;
    next = nullptr;
  }
};

class CircularLinkedList
{
public:
  ListNode *head;
  ListNode *tail;
  int size;

  CircularLinkedList()
  {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  // Insert at beginning
  void insertFront(int val)
  {
    ListNode *node = new ListNode(val);

    if (size == 0)
    {
      head = node;
      tail = node;

      // Point back to itself
      tail->next = head;
    }
    else
    {
      node->next = head;
      head = node;

      // Tail must point to new head
      tail->next = head;
    }

    size++;
  }

  // Insert at end
  void insertEnd(int val)
  {
    ListNode *node = new ListNode(val);

    if (size == 0)
    {
      head = node;
      tail = node;

      tail->next = head;
    }
    else
    {
      node->next = head;
      tail->next = node;
      tail = node;
    }

    size++;
  }

  // Insert at index
  void insert(int index, int val)
  {
    if (index < 0 || index > size)
    {
      return;
    }

    if (index == 0)
    {
      insertFront(val);
      return;
    }

    if (index == size)
    {
      insertEnd(val);
      return;
    }

    ListNode *curr = head;

    // Find node before index
    for (int i = 0; i < index - 1; i++)
    {
      curr = curr->next;
    }

    ListNode *node = new ListNode(val);

    node->next = curr->next;
    curr->next = node;

    size++;
  }

  // Remove from beginning
  void removeFront()
  {
    if (size == 0)
    {
      return;
    }

    if (size == 1)
    {
      delete head;

      head = nullptr;
      tail = nullptr;
    }
    else
    {
      ListNode *toDelete = head;

      head = head->next;

      // Maintain circular connection
      tail->next = head;

      delete toDelete;
    }

    size--;
  }

  // Remove from end
  void removeEnd()
  {
    if (size == 0)
    {
      return;
    }

    if (size == 1)
    {
      delete head;

      head = nullptr;
      tail = nullptr;
    }
    else
    {
      ListNode *curr = head;

      // Find node before tail
      while (curr->next != tail)
      {
        curr = curr->next;
      }

      delete tail;

      tail = curr;

      // Maintain circular connection
      tail->next = head;
    }

    size--;
  }

  // Remove at index
  void remove(int index)
  {
    if (index < 0 || index >= size)
    {
      return;
    }

    if (index == 0)
    {
      removeFront();
      return;
    }

    if (index == size - 1)
    {
      removeEnd();
      return;
    }

    ListNode *curr = head;

    // Find node before index
    for (int i = 0; i < index - 1; i++)
    {
      curr = curr->next;
    }

    ListNode *toDelete = curr->next;

    curr->next = toDelete->next;

    delete toDelete;

    size--;
  }

  // Get value
  int get(int index)
  {
    if (index < 0 || index >= size)
    {
      return -1;
    }

    ListNode *curr = head;

    for (int i = 0; i < index; i++)
    {
      curr = curr->next;
    }

    return curr->val;
  }

  // Print
  void print()
  {
    if (size == 0)
    {
      cout << "EMPTY\n";
      return;
    }

    ListNode *curr = head;

    for (int i = 0; i < size; i++)
    {
      cout << curr->val << " -> ";
      curr = curr->next;
    }

    cout << "(HEAD)\n";
  }

  // Destructor
  ~CircularLinkedList()
  {
    if (size == 0)
    {
      return;
    }

    ListNode *curr = head;

    for (int i = 0; i < size; i++)
    {
      ListNode *next = curr->next;
      delete curr;
      curr = next;
    }
  }
};

int main()
{
  CircularLinkedList list;

  list.insertEnd(10);
  list.insertEnd(20);
  list.insertEnd(30);

  list.print();

  list.insertFront(5);

  list.print();

  list.insert(2, 15);

  list.print();

  list.remove(2);

  list.print();

  list.removeFront();

  list.print();

  list.removeEnd();

  list.print();

  cout << "Index 1: " << list.get(1) << endl;

  return 0;
}