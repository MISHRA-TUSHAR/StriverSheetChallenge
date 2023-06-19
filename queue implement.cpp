#include <bits/stdc++.h> 
class Queue {
public:
    int *arr, start, end, maxSize, count;
    Queue() {
        // Implement the Constructor
        maxSize = 10001;
        arr = new int[maxSize];
        start = 0;
        end = 0;
        count=0;
     
    }


    bool isEmpty() {
        // Implement the isEmpty() function
        return (count==0) ? true : false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(count==maxSize) return;
        else{
            arr[end%maxSize] = data;
            end++;
            count++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(start==end) return -1;
        else{
            int ans = arr[start%maxSize];
            arr[start%maxSize] = -1;
            start++;
            count--;
            return ans;
        }
        
    }

    int front() {
        // Implement the front() function
        return (count>0) ? arr[start%maxSize] : -1;
    }
};
