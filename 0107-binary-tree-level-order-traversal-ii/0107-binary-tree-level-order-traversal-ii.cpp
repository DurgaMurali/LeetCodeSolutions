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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        int level = 0;
        std::queue<std::pair<TreeNode*, int>> level_order;
        level_order.push(make_pair(root, 1));
        vector<int> nodes;
        while(!level_order.empty())
        {
            if(level_order.front().second > level)
            {
                level = level_order.front().second;
                if(!nodes.empty())
                {
                    result.push_back(nodes);
                    nodes.clear();
                }
            }
            TreeNode* node = level_order.front().first;
            nodes.push_back(node->val);
            level_order.pop();

            if(node->left != NULL)
                level_order.push(make_pair(node->left, level+1));
            if(node->right != NULL)
                level_order.push(make_pair(node->right, level+1));
        }

        if(!nodes.empty())
        {
            result.push_back(nodes);
            nodes.clear();
        }

        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};