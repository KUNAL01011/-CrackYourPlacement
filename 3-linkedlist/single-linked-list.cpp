#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

class LiskedList
{
public:
    ListNode* head;
    ListNode* tail;
    int size;

    LiskedList()
    {
        head = new ListNode(-1); // dummy node
        tail = head;
        size = 0;
    }

    // Insert at beginning
    void insertFront(int val)
    {
        ListNode* node = new ListNode(val);

        node->next = head->next;
        head->next = node;

        if (tail == head)
        {
            tail = node;
        }

        size++;
    }

    // Insert at end
    void insertEnd(int val)
    {
        ListNode* node = new ListNode(val);

        tail->next = node;
        tail = node;

        size++;
    }

    // Insert at a specific index
    // index = 0 means first element
    void insert(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }

        // Insert at end
        if (index == size)
        {
            insertEnd(val);
            return;
        }

        ListNode* curr = head;

        // Move to node BEFORE index
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        ListNode* node = new ListNode(val);

        node->next = curr->next;
        curr->next = node;

        size++;
    }

    // Remove from a specific index
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }

        ListNode* curr = head;

        // Move to node BEFORE index
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        ListNode* toDelete = curr->next;

        // If removing tail
        if (toDelete == tail)
        {
            tail = curr;
        }

        curr->next = toDelete->next;

        delete toDelete;

        size--;
    }

    // Get value at index
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        ListNode* curr = head->next;

        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        return curr->val;
    }

    // Print list
    void print()
    {
        ListNode* curr = head->next;

        while (curr)
        {
            cout << curr->val << " -> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }

    // Destructor
    ~LiskedList()
    {
        ListNode* curr = head;

        while (curr)
        {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main()
{
    LiskedList list;

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

    cout << "Value at index 1: " << list.get(1) << endl;

    return 0;
}