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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;

        std::queue<TreeNode*> odd_queue;
        std::queue<TreeNode*> even_queue;
        odd_queue.push(root);
        int level_count = 1;
        vector<int> level_nodes;

        while(!odd_queue.empty() || !even_queue.empty())
        {
            if(level_count % 2 != 0)
            {
                TreeNode* node = odd_queue.front();
                odd_queue.pop();

                if(node != NULL)
                {
                    level_nodes.push_back(node->val);
                    if(node->left != NULL)
                        even_queue.push(node->left);
                    if(node->right != NULL)
                        even_queue.push(node->right);
                }

                if(odd_queue.empty())
                {
                    level_count++;
                    result.push_back(level_nodes);
                    level_nodes.clear();
                }
            }
            else if(level_count % 2 == 0)
            {
                TreeNode* node = even_queue.front();
                even_queue.pop();

                if(node != NULL)
                {
                    level_nodes.push_back(node->val);
                    if(node->left != NULL)
                        odd_queue.push(node->left);
                    if(node->right != NULL)
                        odd_queue.push(node->right);
                }

                if(even_queue.empty())
                {
                    level_count++;
                    result.push_back(level_nodes);
                    level_nodes.clear();
                }
            }
        }
        
        return result;
    }
};