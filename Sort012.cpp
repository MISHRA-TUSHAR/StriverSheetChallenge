#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = 0;

    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            std::swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            std::swap(arr[mid], arr[end]);
            end--;
        }
    }
}
