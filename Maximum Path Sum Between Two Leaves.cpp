long solve(TreeNode<int>* root, long long& maxsum, long long sum) {
    if (root == NULL) return 0;

    long long left = solve(root->left, maxsum, sum);
    long long right = solve(root->right, maxsum, sum);

    sum = max(left, right) + root->val;
    maxsum = max(maxsum, (left + right + root->val));

    return sum;
}

long long int findMaxSumPath(TreeNode<int>* root) {
    if (root == NULL) return -1;
    if (root->left == NULL || root->right == NULL) return -1;

    long long maxsum = 0;
    solve(root, maxsum, 0);

    return maxsum;
}
