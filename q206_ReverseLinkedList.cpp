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
    ListNode* reverseList(ListNode* head) {

        // iterative approach

        // ListNode* curr = head,* prev = nullptr, *next;

        // while(curr != nullptr)
        // {
        //     next = curr->next;

        //     curr->next = prev;

        //     prev = curr;
        //     curr = next;
        // }

        // return prev;
        
        // stack based approach

        stack<int> s;

        ListNode* curr = head;

        while(curr != nullptr)
        {
            s.push(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr != nullptr)
        {
            curr->val = s.top();
            s.pop();
            curr = curr->next;
        }

        return head;
    }
};
