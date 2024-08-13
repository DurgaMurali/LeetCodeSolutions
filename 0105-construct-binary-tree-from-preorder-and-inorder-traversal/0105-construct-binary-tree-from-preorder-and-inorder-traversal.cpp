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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root_node = new TreeNode(preorder[0]);
        vector<int>::iterator it = inorder.begin();
        for(; it != inorder.end(); it++)
        {
            if((*it) == preorder[0])
                break;
        }

        vector<int>* inorder_left = initialize_left_inorder(it, &inorder);
        vector<int>* inorder_right = initialize_right_inorder(it, &inorder);
        vector<int>* preorder_left = initialize_left_preorder(inorder_left->size(), &preorder);
        vector<int>* preorder_right = initialize_right_preorder(inorder_left->size(), inorder_right->size(), &preorder);
        
        build_tree(root_node, inorder_left, inorder_right, preorder_left, preorder_right);

        return root_node;
    }

    void build_tree(TreeNode* root, vector<int>* in_left, vector<int>* in_right, vector<int>* pre_left, vector<int>* pre_right)
    {
        if((in_left->size() == 0 || pre_left->size() == 0) && (in_right->size() == 0 || pre_right->size() == 0))
            return;

        if(pre_left->size() > 0 && in_left->size() > 0)
        {
            vector<int>::iterator it = in_left->begin();
            for(; it != in_left->end(); it++)
            {
                if((*it) == pre_left->at(0))
                    break;
            }
            vector<int>* inorder_left = initialize_left_inorder(it, in_left);
            vector<int>* inorder_right = initialize_right_inorder(it, in_left);
            vector<int>* preorder_left = initialize_left_preorder(inorder_left->size(), pre_left);
            vector<int>* preorder_right = initialize_right_preorder(inorder_left->size(), inorder_right->size(), pre_left);

            TreeNode* node = new TreeNode(pre_left->at(0));
            root->left = node;

            build_tree(node, inorder_left, inorder_right, preorder_left, preorder_right);
        }

        if(pre_right->size() > 0 && in_right->size() > 0)
        {
            vector<int>::iterator it = in_right->begin();
            for(; it != in_right->end(); it++)
            {
                if((*it) == pre_right->at(0))
                    break;
            }
            vector<int>* inorder_left = initialize_left_inorder(it, in_right);
            vector<int>* inorder_right = initialize_right_inorder(it, in_right);
            vector<int>* preorder_left = initialize_left_preorder(inorder_left->size(), pre_right);
            vector<int>* preorder_right = initialize_right_preorder(inorder_left->size(), inorder_right->size(), pre_right);

            TreeNode* node = new TreeNode(pre_right->at(0));
            root->right = node;

            build_tree(node, inorder_left, inorder_right, preorder_left, preorder_right);
        }
    }

    vector<int>* initialize_left_inorder(vector<int>::iterator it, vector<int>* left_vector)
    {
        if(it == left_vector->begin())
        {
            //std::cout << "initialize_left_inorder first" << std::endl;
            return new vector<int>();
        }
        else
        {
            //std::cout << "initialize_left_inorder second" << std::endl;
            return new vector<int>(left_vector->begin(), it);
        }
    }

    vector<int>* initialize_right_inorder(vector<int>::iterator it, vector<int>* right_vector)
    {
        if((it+1) != right_vector->end())
        {
            //std::cout << "initialize_right_inorder first" << std::endl;
            return new vector<int>(it+1, right_vector->end());
        }
        else
        {
            //std::cout << "initialize_right_inorder second" << std::endl;
            return new vector<int>();
        }
    }

    vector<int>* initialize_left_preorder(int size, vector<int>* preorder)
    {
        if(size > 0)
        {
            //std::cout << "initialize_left_preorder " << size << std::endl;
            return new vector<int>(preorder->begin()+1, preorder->begin()+size+1);
        }
        else
        {
            //std::cout << "initialize_left_preorder " << size << std::endl;
            return new vector<int>();
        }
    }

    vector<int>* initialize_right_preorder(int left_size, int right_size, vector<int>* preorder)
    {
        if(right_size > 0)
        {
            //std::cout << "initialize_right_preorder " << right_size << std::endl;
            return new vector<int>(preorder->begin()+left_size+1, preorder->begin()+left_size+right_size+1);
        }
        else
        {
            //std::cout << "initialize_right_preorder " << right_size << std::endl;
            return new vector<int>();
        }
    }
};