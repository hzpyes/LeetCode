/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> res;
    unordered_map<int, int> hash;
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        for (auto &td : to_delete)
            hash[td]++;
        dfs(root, false);
        return res;
    }

    void dfs(TreeNode *&root, bool has_father)
    {
        if (hash[root->val])
        { // 当前点需要被删
            if (root->left)
                dfs(root->left, false);
            if (root->right)
                dfs(root->right, false);
            root = nullptr;
        }
        else
        { // 当前点不需要删
            // 没有父节点那就可以收获结果了
            if (!has_father)
                res.push_back(root);
            // 当前点不需要删且有父节点那就接着遍历
            if (root->left)
                dfs(root->left, true);
            if (root->right)
                dfs(root->right, true);
        }
    }
};