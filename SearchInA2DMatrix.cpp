bool searchMatrix(vector<vector<int>>& mat, int target) {
    int row = mat.size();
    int col = mat[0].size();
    
    int start = 0;
    int end = row * col - 1;
    
    int mid = start + (end - start)/2;
    
    while (start <= end) {
        int element = mat[mid/col][mid%col];
        
        if (element == target) {
            return true;
        }
        
        if (element < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return false;
}
