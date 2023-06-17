#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> result(n);
    st.push(-1);

    for(int i = n-1; i >= 0; i--){
        int current = arr[i];
        
        while(!st.empty() && st.top() <= current){
            st.pop();
        }
        if(st.empty()){
            result[i] = -1;
        }
        else{
            result[i] = st.top();
        }
        st.push(current);
    }

    return result;
}
