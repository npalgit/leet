// Problem 141

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 using namespace std;
 
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode * fast = head;
        ListNode * slow = head;
        
        if(head == NULL) return false;
        
        if(slow->next) slow = slow->next;
        else return NULL;
        
        if(fast->next && fast->next->next) fast = fast->next->next;
        else return false;
        
        while(slow != fast){
            
            slow = slow->next;
            if(fast->next && fast->next->next) fast = fast->next->next;
            else return false;
        }
        
        
        return true;
        
    }
};