#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
  vector<int> stack;
  void push(int n){
    stack.push_back(n);
  }
  int pop(){
    int res = stack[stack.size()-1];
    stack.pop_back();
    return res;
  }
};

int main(){
  return 0;
}