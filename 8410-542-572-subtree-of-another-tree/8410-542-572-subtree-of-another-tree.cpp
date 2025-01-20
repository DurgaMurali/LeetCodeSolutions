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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty())
        {
            TreeNode* node = bfs.front();
            bfs.pop();
            if(isSameTree(node, subRoot))
                return true;

            if(node->left != NULL)
                bfs.push(node->left);

            if(node->right != NULL)
                bfs.push(node->right);
        }

        return false;
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL && subRoot == NULL)
            return true;
        else if((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL))
            return false;
        else if(root->val != subRoot->val)
            return false;
        
        if(isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right))
            return true;

        return false;
    }

};