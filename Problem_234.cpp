// Problem 234

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

    
    
    ListNode* reverseList(ListNode* head) {
        
        
        
        /*
        1. Very easy solution.
        2. Keep next of front in visit, and reverse the node to back
        3. Corner Case:
            a. Empty List
            b. The next of first element has to point to NULL to signify end of list in reverse direction
        
        */
        if(head == NULL) return NULL;
        
        ListNode * front = head->next;
        ListNode * back = head;
        
        ListNode * visit;
        
        while(front != NULL){
            
            visit = front->next;
            front->next = back;
            
            if(back->next == front) back->next = NULL;
            back = front;
            front = visit;
            
        }
        
        return back;
    }
    
    bool isPalindrome(ListNode* head) {
        
        
        if(head == NULL) return 1;
        if(head->next == NULL) return 1;
        
        ListNode * jumpOne = head;
        ListNode * jumpTwo = head;
        
        int stepsOne = 0;
        int stepsTwo  = 0;
        while(jumpTwo->next != NULL && jumpTwo->next->next != NULL){
            
            jumpTwo = jumpTwo->next->next;
            jumpOne = jumpOne->next;
            
            
            
        }
        
        jumpOne->next=reverseList(jumpOne->next);
        jumpOne=jumpOne->next;
        
        while(jumpOne != NULL){
            
            if(head->val != jumpOne->val)
                return false;
            head = head->next;
            jumpOne = jumpOne->next;
        
            
        }
        return true;
        
        
        
        
      
        
        
    }
};