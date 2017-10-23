// Problem 143

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
    
    void reorderList(ListNode* head) {
        
        /*
        1. Easy Solution.
        2. Get to the mid of the list.
        3. Reverse the second half of the list.
        4. Alternatively Add the reversed second half list in the first list.
        5. Corner Cases:
            a. whwn only 1 or 2 elements
            b. Adding the second half list till any list reaches the end
        
        */
        
        if(head == NULL || head->next == NULL) return;
        
        ListNode * init = new ListNode(INT_MIN);
        
        ListNode *back = init;
        ListNode *slow = head;
        ListNode *fast = head;
        
        back->next = head;
        while(fast->next != NULL){
            
            slow = slow->next;
            back = back->next;
            
            if(fast->next) fast = fast->next;
            if(fast->next) fast = fast->next;
            
        }
        
        ListNode *secondStart = slow->next;
        
        slow->next = NULL;
        
        secondStart = reverseList(secondStart);
        
        
        ListNode * lastInsert = head;
        
        while(secondStart != NULL && lastInsert != NULL){
            
            ListNode * temp = secondStart;
            
            secondStart = secondStart->next;
            
            temp->next = lastInsert->next;
            lastInsert->next = temp;
            
            if(lastInsert->next)lastInsert = lastInsert->next;
            if(lastInsert->next)lastInsert = lastInsert->next;
            
        }
        
        delete init;
        
    }
};