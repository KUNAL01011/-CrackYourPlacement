#include <bits/stdc++.h>
using namespace std;

class DynamicArray
{
  int cap = 2;
  int size = 0;
  int *arr = new int[2];

public:
  DynamicArray() {};
  ~DynamicArray() {
    delete[] arr;
  }

  void pushback(int n)
  {
    if (size == cap)
    {
      resize();
    }
    arr[size] = n;
    size++;
  }
  void resize()
  {
    cap = 2 * cap;
    int *newArr = new int[cap];

    for (int i = 0; i < size; i++)
    {
      newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
  }

  void popback()
  {
    if (size > 0)
    {
      size--;
    }
  }

  int get(int i)
  {
    if (i < size && i >= 0)
    {
      return arr[i];
    }
    return -1;
  }

  int insert(int i, int n)
  {
    if (i < size && i >= 0)
    {
      arr[i] = n;
      return;
    }
  }
};

int main()
{
  return 0;
}