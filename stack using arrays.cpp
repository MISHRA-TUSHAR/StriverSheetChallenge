#include <bits/stdc++.h> 

class Stack {
    
public:
    int *arr,size,topo;
    Stack(int cap) {
        arr=new int[cap];
        size=cap;
        topo=-1;
    }
    void push(int num) {
      if(topo==size-1) {}
        else {
            arr[++topo]=num;       
        }
    }
    int pop() {
         if(topo!=-1){
          int ans=arr[topo];
          topo--;
        return ans;
   }
        else return -1; 
    }
    
    int top() {
        if(topo!=-1)
        return arr[topo];
        else return -1;
    }
   int isEmpty() {
        if(topo==-1) return 1;
        else return 0;
    }
     int isFull() {
       if(topo==size-1) return 1;
        else return 0;
    }
   };
