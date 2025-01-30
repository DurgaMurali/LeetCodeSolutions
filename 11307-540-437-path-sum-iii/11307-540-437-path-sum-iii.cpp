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
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;

        queue<TreeNode*> que;
        que.push(root);
        int count = 0;

        while(!que.empty())
        {
            TreeNode* node = que.front();
            dfs(node, targetSum, count);
            que.pop();

            if(node->left != NULL)
                que.push(node->left);
            if(node->right != NULL)
                que.push(node->right);
        }

        return count;
    }

    void dfs(TreeNode* root, int targetSum, int &count)
    {
        stack<pair<TreeNode*, long>> tree_stack;
        tree_stack.push(make_pair(root, 0));

        while(!tree_stack.empty())
        {
            TreeNode* node = tree_stack.top().first;
            long sum = tree_stack.top().second + node->val;
            tree_stack.pop();

            if(sum == targetSum)
                count += 1;

            if(node->left != NULL)
                tree_stack.push(make_pair(node->left, sum));

            if(node->right != NULL)
                tree_stack.push(make_pair(node->right, sum));
        }
    }
};