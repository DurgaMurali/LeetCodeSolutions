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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;

        vector<int> array;
        InorderTraversal(root, array);

        for(size_t i=1; i<array.size(); ++i)
        {
            //std::cout << array[i] << ", ";
            if(array[i-1] >= array[i])
                return false;
        }

        return true;
    }

    void InorderTraversal(TreeNode* root, vector<int> &array)
    {
        if(root == NULL)
            return;

        InorderTraversal(root->left, array);

        array.push_back(root->val);

        InorderTraversal(root->right, array);    
    }
};