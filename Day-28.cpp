#include <bits/stdc++.h>
using namespace std;

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a

    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a

    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// Flatten Nested List Iterator
class NestedIterator
{
    vector<int> output;
    int i = 0;

public:
    void solve(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                output.push_back(nestedList[i].getInteger());
            }
            else
            {
                solve(nestedList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) { solve(nestedList); }

    int next()
    {
        int ans = output.at(i);
        i++;
        return ans;
    }

    bool hasNext()
    {
        if (i < output.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// Maximum of minimum for every window size
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int index = st.top();
            st.pop();

            if (st.empty())
            {
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int index = st.top();
        st.pop();

        if (st.empty())
        {
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        else
        {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
}

// LRU Cache
class LRUCache
{
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

// The Celebrity Problem
int celebrity(vector<vector<int>> &M)
{
    int n = M.size();
    stack<int> st;

    // step 1
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // step 2

    while (st.size() != 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b])
        {
            // a crebrity nahi hai may be b
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int ans = st.top();
    st.pop();

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] != 0)
        {
            return -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] != 1 && i != ans)
        {
            return -1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}