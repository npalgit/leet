// Problem 206

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
    ListNode* reverseList(ListNode* head) {
        
        
        
        /*
        1. Very easy solution.
        2. Keep next of front in visit, and reverse the node to back
        3. Corner Case:
            a. Empty List
            b. The next of first element has to point to NULL to signify end of list in reverse direction
        
        */
        if(head == NULL ) return NULL;
        if(head->next == NULL) return head;
        
        ListNode * front = head;
        ListNode * back = NULL;
        
        ListNode * visit = front->next;
        
        while(visit){
            
            //visit = front->next;
            
            // Reversing
            front->next = back;
            
            // Head Corner Case
            //
            
            // Move Forward
            back = front;
            front = visit;
            visit = visit->next;
            
        }
        
        front->next = back;
        if(back->next == front) back->next = NULL;
        
        return front;
    }
};