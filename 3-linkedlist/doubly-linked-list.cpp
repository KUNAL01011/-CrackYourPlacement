#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next = nullptr;
  ListNode *prev = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

class LinkedList
{
public:
  ListNode *head;
  ListNode *tail;
  int size;

  LinkedList()
  {
    // Dummy node
    head = new ListNode(-1);
    tail = head;
    size = 0;
  }

  // Insert at beginning
  void insertFront(int val)
  {
    ListNode *node = new ListNode(val);

    node->next = head->next;
    node->prev = head;

    head->next = node;

    if (tail == head)
    {
      tail = node;
    }
    else
    {
      node->next->prev = node;
    }

    size++;
  }

  // Insert at end
  void insertEnd(int val)
  {
    ListNode *node = new ListNode(val);

    node->prev = tail;
    tail->next = node;

    tail = node;

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

    // Find node currently at index
    ListNode *curr = head->next;

    for (int i = 0; i < index; i++)
    {
      curr = curr->next;
    }

    ListNode *node = new ListNode(val);

    // Connect node to both sides
    node->prev = curr->prev;
    node->next = curr;

    curr->prev->next = node;
    curr->prev = node;

    size++;
  }

  // Remove from beginning
  void removeFront()
  {
    if (size == 0)
    {
      return;
    }

    ListNode *toDelete = head->next;

    head->next = toDelete->next;

    if (toDelete->next)
    {
      toDelete->next->prev = head;
    }
    else
    {
      // List becomes empty
      tail = head;
    }

    delete toDelete;
    size--;
  }

  // Remove from end
  void removeEnd()
  {
    if (size == 0)
    {
      return;
    }

    ListNode *toDelete = tail;

    tail = tail->prev;
    tail->next = nullptr;

    delete toDelete;
    size--;
  }

  // Remove from index
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

    ListNode *curr = head->next;

    for (int i = 0; i < index; i++)
    {
      curr = curr->next;
    }

    // Connect previous and next nodes
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    size--;
  }

  // Get value
  int get(int index)
  {
    if (index < 0 || index >= size)
    {
      return -1;
    }

    ListNode *curr;

    // We can choose the closer side!
    if (index < size / 2)
    {
      curr = head->next;

      for (int i = 0; i < index; i++)
      {
        curr = curr->next;
      }
    }
    else
    {
      curr = tail;

      for (int i = size - 1; i > index; i--)
      {
        curr = curr->prev;
      }
    }

    return curr->val;
  }

  // Print forward
  void printForward()
  {
    ListNode *curr = head->next;

    while (curr)
    {
      cout << curr->val << " <-> ";
      curr = curr->next;
    }

    cout << "NULL\n";
  }

  // Print backward
  void printBackward()
  {
    ListNode *curr = tail;

    while (curr != head)
    {
      cout << curr->val << " <-> ";
      curr = curr->prev;
    }

    cout << "HEAD\n";
  }

  // Destructor
  ~LinkedList()
  {
    ListNode *curr = head;

    while (curr)
    {
      ListNode *next = curr->next;
      delete curr;
      curr = next;
    }
  }
};

int main()
{
  LinkedList list;

  list.insertEnd(10);
  list.insertEnd(20);
  list.insertEnd(30);

  list.printForward();

  list.insertFront(5);

  list.printForward();

  list.insert(2, 15);

  list.printForward();

  list.remove(2);

  list.printForward();

  list.removeFront();

  list.printForward();

  list.removeEnd();

  list.printForward();

  cout << "Index 1: " << list.get(1) << endl;

  list.printBackward();

  return 0;
}