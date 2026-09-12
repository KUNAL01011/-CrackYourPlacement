#include<bits/stdc++.h>
using namespace std;

int fibbo(int n){
  if(n <= 1){
    return n;
  }
  return fibbo(n-1) + fibbo(n-2);
}

int main() {
  return 0;
}