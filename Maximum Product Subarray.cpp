#include <bits/stdc++.h> 

int maximumProduct(vector<int>& arr, int n) {
    int maximum = INT_MIN;
    int prefixProduct = 1;
    int suffixProduct = 1;
    
    for (int i = 0; i < n; ++i) {
        if (suffixProduct == 0) {
            suffixProduct = 1;
        }
        
        if (prefixProduct == 0) {
            prefixProduct = 1;
        }
        
        suffixProduct = suffixProduct * arr[n - i - 1];
        prefixProduct *= arr[i];
        maximum = max(maximum, max(prefixProduct, suffixProduct));
    }
    
    return maximum;
}
