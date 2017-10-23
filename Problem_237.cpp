// Problem 237

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        
        /*
        
        Logic is to replace current's node value with next node value, and delete the next node.
        
        
        */
        ListNode * temp = node->next;
        node->next = temp->next;
        
        node->val = temp->val;
        
        delete temp;
        
        
    }
};