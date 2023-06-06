#include <bits/stdc++.h>

int countPaths(vector<vector<int>>& dp, int rows, int columns) {
    if (rows < 1 || columns < 1) return 0;
    if (rows == 1 && columns == 1) return 1;

    if (dp[rows][columns] != -1) return dp[rows][columns];

    return dp[rows][columns] = countPaths(dp, rows - 1, columns) + countPaths(dp, rows, columns - 1);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return countPaths(dp, m, n);
}
