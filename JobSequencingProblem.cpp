#include <bits/stdc++.h>

struct Job
{
  int deadline;
  int profit;
};

bool cmp(Job a, Job b)
{
  return (a.profit > b.profit);
}

int jobScheduling(vector<vector<int>> &jobs)
{
  int n = jobs.size();

  struct Job arr[n];

  for (int i = 0; i < n; i++)
  {
    arr[i].deadline = jobs[i][0];
    arr[i].profit = jobs[i][1];
  }

  sort(arr, arr + n, cmp);

  int maxDeadline = arr[0].deadline;

  for (int i = 0; i < n; i++)
  {
    maxDeadline = max(maxDeadline, arr[i].deadline);
  }

  vector<int> seq(maxDeadline + 1, -1);

  int totalProfit = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = arr[i].deadline; j > 0; j--)
    {
      if (seq[j] == -1)
      {
        seq[j] = i;
        totalProfit += arr[i].profit;
        break;
      }
    }
  }

  return totalProfit;
}
