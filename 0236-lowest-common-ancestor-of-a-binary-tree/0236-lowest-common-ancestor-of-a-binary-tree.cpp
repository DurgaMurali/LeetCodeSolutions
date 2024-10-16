/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return root;

        bool p_found = false;
        bool q_found = false;
        TreeNode* ancestor = NULL;
        post_order_traversal(root, p, q, &ancestor);

        return ancestor;
    }

    int post_order_traversal(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode** ancestor)
    {
        if(node == NULL || *ancestor != NULL)
            return 0;

        int val1_found = post_order_traversal(node->left, p, q, ancestor);
        int val2_found = post_order_traversal(node->right, p, q, ancestor);

        int val3_found = 0;
        if(node->val == p->val || node->val == q->val)
            val3_found = 1;

        //std::cout << node->val << " - " << val1_found << ", " << val2_found << ", " << val3_found << std::endl;

        if(val1_found + val2_found + val3_found >= 2)
        {
            *ancestor = node;
            return 0;
        }
        else
            return val1_found + val2_found + val3_found;
    }
};