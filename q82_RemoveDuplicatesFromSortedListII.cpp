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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> map;

        ListNode * curr = head;

        while(curr != nullptr)
        {
            if(map.find(curr->val) != map.end())
            {
                map[curr->val]++;
            }
            else
            {
                map.insert({curr->val, 1});
            }
            curr = curr->next;
        }

        ListNode dummy(0, head);
        ListNode * prev = &dummy;
        curr = head;

        while(curr != nullptr)
        {
            if (map[curr->val] > 1)
            {
                ListNode* toDel = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete toDel;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
