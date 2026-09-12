#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>arr){
  int n = arr.size();

  for(int i = 1; i < n; i++){
    int j = i-1;
    while(j >= 0 && arr[j] > arr[j+1]){
      int temp = arr[j+1];
      arr[j+1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main() {
  return 0;
}