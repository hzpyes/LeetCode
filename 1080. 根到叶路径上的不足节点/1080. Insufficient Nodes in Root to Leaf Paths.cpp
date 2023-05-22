class Solution
{
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        dfs(root, limit, 0);
        return root;
    }

    void dfs(TreeNode *&root, int limit, int path)
    {
        path += root->val;
        if (!root->left && !root->right)
        {
            if (path < limit)
                root = NULL;
        }
        else
        {
            if (root->left)
                dfs(root->left, limit, path);
            if (root->right)
                dfs(root->right, limit, path);
            if (!root->left && !root->right)
                root = NULL;
        }
    }
};