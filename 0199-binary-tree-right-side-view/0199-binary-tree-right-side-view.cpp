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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        std::queue<std::pair<TreeNode*, int>> que;

        if(root == NULL)
            return result;

        int level = 1;
        que.push(std::pair(root, level));
        
        while(!que.empty())
        {
            int nodeLevel = que.front().second;
            TreeNode* node = que.front().first;
            que.pop();

            if(que.empty())
                result.push_back(node->val);
            else if(que.front().second > nodeLevel)
                result.push_back(node->val);

            if(node->left != NULL)
                que.push(std::pair(node->left, nodeLevel+1));
            if(node->right != NULL)
                que.push(std::pair(node->right, nodeLevel+1));
        }

        return result;
    }
};