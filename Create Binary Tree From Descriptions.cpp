class Solution {
public:
    TreeNode* solve(int root, map<pair<int, int>, int>& mp) {
        TreeNode* node = new TreeNode(root);

        if (mp.find({root, 1}) != mp.end()) {

            node->left = solve(mp[{root, 1}], mp);
        }
        if (mp.find({root, 0}) != mp.end()) {

            node->right = solve(mp[{root, 0}], mp);
        }

        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        set<int> child;
        int root_value = 0;
        map<pair<int, int>, int> mp;

        //converting des to map to reduce complexity
        for (auto it : des) {
            child.insert(it[1]);
            mp[{it[0], it[2]}] = it[1];
        }

        //finding root
        for (auto it : des) {
            if (child.find(it[0]) == child.end()) {
                root_value = it[0];
                break;
            }
        }
//Make tree
        TreeNode* root = solve(root_value, mp);
        return root;
    }
};
