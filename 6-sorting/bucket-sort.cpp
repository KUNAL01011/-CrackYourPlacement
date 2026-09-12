#include<bits/stdc++.h>
using namespace std;

vector<int> bucket_sort(vector<int>&arr){
  // Assuming arr only contains 0, 1 or 2
  int count[] = {0, 0, 0};

  for(int n : arr){
    count[n]++;
  }

  int i = 0;
  for(int n = 0; n < 3; n++){
    for(int j = 0; j < count[n]; j++){
      arr[i] = n;
      i++;
    }
  }
  return arr;
}

int main() {
  return 0;
}