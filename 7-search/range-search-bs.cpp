// Here we don't have the target we are give a range and we have to find the correct number
#include<bits/stdc++.h>
using namespace std;

int isCorrect(int n) {
  if(n > 10){
    return 1;
  }
  else if (n < 10){
    return -1;
  }
  else {
    return 0;
  }
}

int binary_search(int low, int high){
  while(low <= high){
    int mid = low + (high - low) / 2;

    if(isCorrect(mid) > 0){
      high = mid - 1;
    }
    else if(isCorrect(mid) < 0){
      low = mid+1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

int main() {
  return 0;
}