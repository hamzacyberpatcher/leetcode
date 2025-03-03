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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode * temp = head;
        int length = 1;

        while(temp->next != NULL)
        {
            temp = temp->next;
            length++;
        }

        temp->next = head;

        temp = head;

        k = k % length;
        int stepsToNext = length - k;
        int idx = 0;

        while(idx < stepsToNext - 1)
        {
            temp = temp->next;
            idx++;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
