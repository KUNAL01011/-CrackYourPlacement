#include <bits/stdc++.h>
using namespace std;

// Implement Stack and Queue using Deque
// structure for a node of deque
struct DQueNode
{
    int value;
    DQueNode *next;
    DQueNode *prev;
};

// Implementation of deque class
class Deque
{
private:
    // pointers to head and tail of deque
    DQueNode *head;
    DQueNode *tail;

public:
    // constructor
    Deque()
    {
        head = tail = NULL;
    }

    // if list is empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    // count the number of nodes in list
    int size()
    {
        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = head;
            int len = 0;
            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    // insert at the first position
    void insert_first(int element)
    {
        // allocating node of DQueNode type
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if the element is first element
        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // insert at last position of deque
    void insert_last(int element)
    {
        // allocating node of DQueNode type
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if element is the first element
        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    // remove element at the first position
    void remove_first()
    {
        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = head;
            head = head->next;
            if (head)
                head->prev = NULL;
            delete temp;
            if (head == NULL)
                tail = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // remove element at the last position
    void remove_last()
    {
        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = tail;
            tail = tail->prev;
            if (tail)
                tail->next = NULL;
            delete temp;
            if (tail == NULL)
                head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // displays the elements in deque
    void display()
    {
        // if list is not empty
        if (!isEmpty())
        {
            DQueNode *temp = head;
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};

// Class to implement stack using Deque
class Stack : public Deque
{
public:
    // push to push element at top of stack
    // using insert at last function of deque
    void push(int element)
    {
        insert_last(element);
    }

    // pop to remove element at top of stack
    // using remove at last function of deque
    void pop()
    {
        remove_last();
    }
};

// class to implement queue using deque
class Queue : public Deque
{
public:
    // enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element)
    {
        insert_last(element);
    }

    // dequeue to remove element from first
    // using remove at first function of deque
    void dequeue()
    {
        remove_first();
    }
};

// Next Greater Element I
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++)
    {
        int j = 0;
        while (nums2[j] != nums1[i])
        {
            j++;
        }
        // search for the next greater element
        for (int k = j + 1; k < nums2.size(); k++)
        {
            if (nums2[k] > nums1[i])
            {
                ans[i] = nums2[k];
                break;
            }
        }
    }
    return ans;
}

// Evaluation of Postfix Expression
int evaluatePostfix(string S)
{
    stack<int> st;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
            st.push(S[i] - '0');
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if (S[i] == '+')
                st.push(op1 + op2);
            else if (S[i] == '-')
                st.push(op1 - op2);
            else if (S[i] == '*')
                st.push(op1 * op2);
            else if (S[i] == '/')
                st.push(op1 / op2);
        }
    }

    return st.top();
}

// Implement two stacks in an array
class twoStacks
{
public:
    twoStacks() : arr(100), top1(-1), top2(100), size(100)
    {
        // Initialization is done in the member initializer list
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
            return -1;
        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size)
            return -1;
        return arr[top2++];
    }

private:
    vector<int> arr;
    int top1, top2, size;
};

int main()
{

    return 0;
}