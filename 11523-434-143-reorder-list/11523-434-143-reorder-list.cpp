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
    void reorderList(ListNode* head) {
        ListNode *head_node = head;
        ListNode *last_node = head;
        int count = 1;

        if(head_node == NULL || head_node->next == NULL)
            return;

        while(last_node->next != NULL)
        {
            last_node = last_node->next;
            count++;
        }

        bool even = (count % 2 == 0);
        int mid_point = (count/2) + 1;
        //std::cout << count << ", " << mid_point << std::endl;
        ListNode *mid_node = head;
        ListNode* prev_node = NULL;
        count = 1;

        while(count < mid_point)
        {
            count++;
            prev_node = mid_node;
            mid_node = mid_node->next;
        }

        //std::cout << mid_node->val << std::endl;
        //std::cout << prev_node->val << std::endl;

        ListNode* cur_node = mid_node;
        if(even)
            prev_node->next = NULL;
        else
            cur_node = mid_node->next;

        ListNode* next_node = NULL;
        prev_node = NULL;

        while(cur_node != NULL)
        {   
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }

        mid_node->next = NULL;

        while(head_node != NULL && prev_node != NULL)
        {
            last_node = head_node->next;
            head_node->next = prev_node;
            
            head_node = last_node;
            last_node = prev_node->next;
            prev_node->next = head_node;

            prev_node = last_node;
        }
    }
};