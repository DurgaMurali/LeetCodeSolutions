/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        buildBST(&root, head);
        return root;
    }

    ListNode* midPoint(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;

        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* prevptr = NULL;

        while(fastptr != NULL && fastptr->next != NULL)
        {
            prevptr = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        prevptr->next = NULL;
        return slowptr;
    }

    void buildBST(TreeNode** node, ListNode* head)
    {
        ListNode* mid = midPoint(head);
        if(mid != NULL)
        {
            TreeNode* new_node = place_node(node, mid->val);
            if(mid != head)
                buildBST(&new_node, head);
            buildBST(&new_node, mid->next);
        }
    }

    TreeNode* place_node(TreeNode** node, int value)
    {
        //std::cout << value << std::endl;
        TreeNode* new_node = new TreeNode(value);
        if((*node) != NULL && value < (*node)->val)
            (*node)->left = new_node;
        else if((*node) != NULL && value > (*node)->val)
            (*node)->right = new_node;
        else if((*node) == NULL)
            (*node) = new_node;

        return new_node;
    }
};