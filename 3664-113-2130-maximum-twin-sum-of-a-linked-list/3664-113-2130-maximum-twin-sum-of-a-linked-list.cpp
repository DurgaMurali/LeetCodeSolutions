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
class Solution {
public:
    int pairSum(ListNode* head) {
        int count = 1;
        ListNode* node = head;

        while(node->next != NULL)
        {
            count++;
            node = node->next;
        }

        int middle = (count/2)+1;
        count = 1;
        ListNode* middle_node = head;

        while(count < middle)
        {
            node = middle_node;
            middle_node = middle_node->next;
            count++;
        }
        node->next = NULL;

        node = middle_node;
        ListNode* prev_node = NULL;
        ListNode* next_node = NULL;
        while(node != NULL)
        {
            next_node = node->next;
            node->next = prev_node;
            prev_node = node;

            node = next_node;
        }

        node = head;
        int sum = 0;
        while(node != NULL && prev_node != NULL)
        {
            int twin_sum = node->val + prev_node->val;
            if(twin_sum > sum)
                sum = twin_sum;

            node = node->next;
            prev_node = prev_node->next;
        }

        return sum;
    }
};