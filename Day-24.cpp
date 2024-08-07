#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int val;
    Node *child;
    Node *bottom;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// Implement Stack using Queues
class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    int pop()
    {
        int poped = -1;
        if (!q.empty())
        {
            poped = q.front();
            q.pop();
        }
        return poped;
    }

    int top()
    {
        int fr = -1;
        if (!q.empty())
        {
            fr = q.front();
        }
        return fr;
    }

    bool empty()
    {
        return q.empty();
    }
};

// Backspace String Compare
string updateString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
bool backspaceCompare(string s, string t)
{
    string temp1 = updateString(s);
    string temp2 = updateString(t);

    return temp1 == temp2 ? true : false;
}

// Implement Queue using Stacks
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    };

    int pop()
    {
        int poped = -1;
        if (!s2.empty())
        {
            poped = s2.top();
            s2.pop();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            poped = s2.top();
            s2.pop();
        }

        return poped;
    }

    int peek()
    {
        int fr = -1;
        if (!s2.empty())
        {
            fr = s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            fr = s2.top();
        }

        return fr;
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// Flattening a Linked List
Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == 0)
        return list2;
    if (list2 == 0)
        return list1;

    Node *ans = new Node(-1);
    Node *mptr = ans;

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            mptr->bottom = list1;
            mptr = list1;
            list1 = list1->bottom;
        }
        else
        {
            mptr->bottom = list2;
            mptr = list2;
            list2 = list2->bottom;
        }
    }

    if (list1)
    {
        mptr->bottom = list1;
    }
    if (list2)
    {
        mptr->bottom = list2;
    }

    return ans->bottom;
}
// Function which returns the  root of the flattened linked list.
Node *flatten(Node *root)
{
    // Your code here
    priority_queue<Node *, vector<Node *>, greater<Node *>> pq;
    Node *temp = root;
    while (temp)
    {
        Node *tempNext = temp->next;
        temp->next = NULL;

        pq.push(temp);
        temp = tempNext;
    }

    if (pq.empty())
    {
        return root;
    }

    Node *ans = new Node(-1);
    Node *tail = ans;

    while (!pq.empty())
    {
        tail->bottom = mergeTwoLists(ans->bottom, pq.top());
        pq.pop();
    }

    return ans->bottom;
}

int main()
{

    return 0;
}