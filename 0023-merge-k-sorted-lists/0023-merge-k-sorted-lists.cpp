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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> next_pointers;
        ListNode* head = NULL;
        ListNode* prev_ptr = NULL;
        int size = lists.size();

        while(true)
        {
            int min = INT_MAX;
            int index = 0;
            int count = 0;
            for(int i=0; i<size; ++i)
            {
                if(lists[i] != NULL && min > lists[i]->val)
                {
                    min = lists[i]->val;
                    index = i;
                    count++;
                }
            }
            //std::cout << "Min = " << min << ", index = " << index << std::endl;
            if(count == 0)
                break;

            if(head == NULL)
            {
                head = lists[index];
                prev_ptr = head;
                //std::cout << prev_ptr->val << std::endl;
                lists[index] = lists[index]->next;
                /*if(lists[index] != NULL)
                    std::cout << "next list index = " << lists[index]->val << std::endl;*/
            }
            else
            {
                prev_ptr->next = lists[index];
                //std::cout << "prev = " << prev_ptr->val << std::endl;
                //std::cout << "cur = " << prev_ptr->next->val << std::endl;
                lists[index] = lists[index]->next;
                /*if(lists[index] != NULL)
                    std::cout << "next list index = " << lists[index]->val << std::endl;*/

                prev_ptr = prev_ptr->next;
            }
            
        }

        
        return head;
    }
};