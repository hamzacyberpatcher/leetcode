/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    vector<ListNode*> vec;
public:
    bool hasCycle(ListNode *head) {

        if (head == NULL) return false;
        
        while(head->next != NULL)
        {
            auto it = find(vec.begin(), vec.end(), head);
            if (it != vec.end())
            {
                return true;
            }
            else
            {
                vec.push_back(head);
            }
            head = head->next;
        }

        return false;

    }
};
