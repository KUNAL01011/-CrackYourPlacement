#include<bits/stdc++.h>
using namespace std;

vector<int> quick_sort(vector<int>&arr, int s, int e){
  if(e - s + 1 <= 1) return arr;
  
  int pivot = arr[e];
  int left = s;

  for(int i = s; i < e; i++){
    if(arr[i] < pivot){
      int temp = arr[left];
      arr[left] = arr[i];
      arr[i] = temp;
      left++;
    }
  }

  arr[e] = arr[left];
  arr[left] = pivot;

  quick_sort(arr, s, left-1);
  quick_sort(arr, left+1, e);
  return arr;
}

int main() {
  return 0;
}