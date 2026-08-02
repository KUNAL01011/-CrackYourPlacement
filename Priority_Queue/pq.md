# Priority Queue
-> For queue those goes first out first like FIFO that queue look like

-> But Priority Queue : Is a type of queue when we focus how the element popped like we have two variation 
1. Max : where maximum element popped first 
2. Min : the minimum element popped 

Note: why two name like Heap / Priority Queue because the undernith queue work but insted of implemented by LinkedList this implemented by Heap

Note : Here we going to use Binary Heap yes binary tree but this is not BST this is just Complete Binary Tree all node must be full on all level but at the filed by left to right left > Root < right

Note : Most intersting point is we assume the this look Binary Tree but that implemented by a array and start with 1-indexed based array

-> Why we use 1-indexed 
-> Because we used to math work like
    leftChild = 2 * i
    rightChild = 2 * i + 1
    parent = i / 2;

# PUSH && POP

## PUSH
take the value place at the end and now compare with there parent if parent is bigger then element we swap with parent and do at root or index-1 
-> T.C = O(logN)

## POP
so for pop we don't have the option pop only pop min means root element so how we gonna do that first we replace the root to last element and to maintain the order we take the find the min of leftChild or rightChild and replace and this go until 
-> T.C = O(logN)

# Heapify
-> To implement the Heap we gonna take T.C = O(nlogn) 
  n -> is element we going to insert and logN is for maintain the order && structure 

-> if we given a array that doesn't follow any order and we have convert this array into Heap in just O(n) time complexity that called Heapify algorithm to do this first we found out the first element that has the child ignore all leaf node how (arr.size() - 1) / 2 and then check min(leftChild, rightChild) and if this greater then root replace and do this all element at the top  