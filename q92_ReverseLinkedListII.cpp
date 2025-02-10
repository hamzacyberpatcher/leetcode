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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;

        ListNode* curr = head;

        int idx = 1;

        while(idx != left)
        {
            curr = curr->next;
            idx++;
        }

        while(idx <= right)
        {
            s.push(curr->val);
            idx++;
            curr = curr->next;
        }

        idx = 1;
        curr = head;

        while(idx != left)
        {
            curr = curr->next;
            idx++;
        }

        while(idx <= right)
        {
            curr->val = s.top();
            s.pop();
            idx++;
            curr = curr->next;
        }

        return head;
    }
};
