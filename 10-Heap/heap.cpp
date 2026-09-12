#include <bits/stdc++.h>
using namespace std;
// MIN HEAP
class Heap
{
public:
  vector<int> heap;

  Heap()
  {
    heap.push_back(0);
  }

  void push(int val)
  {
    heap.push_back(val);
    int i = heap.size() - 1;

    // Percolate up
    while (i > 1 && heap[i] < heap[i / 2])
    {
      int tmp = heap[i];
      heap[i] = heap[i / 2];
      heap[i / 2] = tmp;
      i = i / 2;
    }
  }

  int pop()
  {
    if (heap.size() == 1)
    {
      return -1;
    }
    if (heap.size() == 2)
    {
      int res = heap[heap.size() - 1];
      heap.pop_back();
      return res;
    }

    int res = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    int i = 1;
    // Percolate down
    while (2 * i < heap.size())
    {
      if (2 * i + 1 < heap.size() && heap[2 * i + 1] < heap[2 * i] && heap[i] > heap[2 * i + 1])
      {
        // swap right child
        int temp = heap[i];
        heap[i] = heap[2 * i + 1];
        heap[2 * i + 1] = temp;
        i = 2 * i + 1;
      }
      else if (heap[i] > heap[2 * i])
      {
        // Swap left child
        int temp = heap[i];
        heap[i] = heap[2 * i];
        heap[2 * i] = temp;
        i = 2 * i;
      }
      else
      {
        break;
      }
    }
    return res;
  }

  int top()
  {
    if (heap.size() > 1)
    {
      return heap[1];
    }
    return -1;
  }

  void heapify(vector<int> &arr)
  {
    arr.push_back(arr[0]);

    heap = arr;
    int curr = (heap.size() - 1) / 2;

    while (curr > 0)
    {
      // percolate down
      int i = curr;

      while (2 * i < heap.size())
      {
        if (2 * i + 1 < heap.size() && heap[2 * i + 1] < heap[2 * i] && heap[i] > heap[2 * i + 1])
        {
          int temp = heap[i];
          heap[i] = heap[2 * i + 1];
          heap[2 * i + 1] = temp;
          i = 2 * i + 1;
        }
        else if (heap[i] > heap[2 * i]){
          // Swap left child
        int temp = heap[i];
        heap[i] = heap[2 * i];
        heap[2 * i] = temp;
        i = 2 * i;
        }
        else{
          break;
        }
      }
      curr--;
    }
  }
};

int main()
{
  return 0;
}