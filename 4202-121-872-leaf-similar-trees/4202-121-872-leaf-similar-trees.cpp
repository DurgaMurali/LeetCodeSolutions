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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first_sequence, second_sequence;
        leafSequence(first_sequence, root1);
        leafSequence(second_sequence, root2);

        if(first_sequence.size() != second_sequence.size())
            return false;

        int size = second_sequence.size();
        for(int i=0; i<size; ++i)
        {
            if(first_sequence[i] != second_sequence[i])
                return false;
        }

        return true;
    }

    void leafSequence(vector<int> &sequence, TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            sequence.push_back(root->val);
            return;
        }

        if(root->left != NULL)
            leafSequence(sequence, root->left);
        if(root->right != NULL)
            leafSequence(sequence, root->right);
    }
};