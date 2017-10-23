// Problem 142

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
    ListNode *detectCycle(ListNode *head) {
        
        /*
        1. Let us start with 2 pointers - slow and fast.
        2. Slow increments by 1, and fast by 2.
        3. if slow and fast meet, it confirms there is a cycle.
        4. if fast reaches a NULL, it confirms cycle doesn't exist
        5. the steps I will take from starting point, and this point will meet at the starting of the cycle.
        6. Corner Cases:
            a. we care that slow isn't equal to fast in the while loop.
            b. But, it is equal at very first iteration as they both start from head.
            c. Therefore, we go for a do while loop.
        
        */
        
        
        if(head == NULL) return NULL;
        
        ListNode * fast = head;
        ListNode * slow = head;
        
        if(slow->next) slow = slow->next;
        else return NULL;
        
        if(fast->next && fast->next->next) fast = fast->next->next;
        else return NULL;
        
        
        while(slow != fast){
            
            
            slow = slow->next;
            
            if(fast->next && fast->next->next) fast = fast->next->next;
            else return NULL;
            
        }
        
        
        ListNode * travel = head;
        
        while(slow != travel){
            
            travel = travel->next;
            slow = slow->next;
            
        }
        
        
        return travel;
        
        
    }
};