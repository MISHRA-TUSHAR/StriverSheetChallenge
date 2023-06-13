#include <bits/stdc++.h> 
void sortStack(stack<int> &stack){
    vector<int> v;
    while(!stack.empty()){
		v.push_back(stack.top());
        stack.pop();
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i = v.size()-1;i>=0;i--){
        stack.push(v[i]);

    }

}
