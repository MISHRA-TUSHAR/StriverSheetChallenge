#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>>& matrix, int n, int m) {
    int i, j, left, right, top, bottom, k, temp;

    left = 0;
    top = 0;
    right = m - 1;
    bottom = n - 1;

    while (top < bottom && left < right) {
        temp = matrix[top][left];
        for (i = left + 1; i <= right; i++) {
            k = matrix[top][i];
            matrix[top][i] = temp;
            temp = k;
        }
        top++;

        for (i = top; i <= bottom; i++) {
            k = matrix[i][right];
            matrix[i][right] = temp;
            temp = k;
        }
        right--;

        for (i = right; i >= left; i--) {
            k = matrix[bottom][i];
            matrix[bottom][i] = temp;
            temp = k;
        }
        bottom--;

        for (i = bottom; i >= top; i--) {
            k = matrix[i][left];
            matrix[i][left] = temp;
            temp = k;
        }
        left++;

        matrix[top - 1][left - 1] = temp;
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        rotateMatrix(matrix, row, row);
    }
};
