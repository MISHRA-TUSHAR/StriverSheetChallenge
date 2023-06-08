#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n)
{

  int size = arr.size();

  int answer = 0;

  for (int i = 0; i < size; i++)
  {

    for (int j = i + 1; j < size; j++)
    {

      if (arr[j] == arr[i])
      {

        answer = arr[j];
      }
    }
  }

  return answer;
}