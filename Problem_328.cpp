// Problem 328


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

    void printList(ListNode * head){
        
        ListNode * temp = head;
       while(temp != NULL){
           
           cout << temp->val << " : ";
           temp = temp->next;
           
       }
        
        cout << endl;
    }
    ListNode* oddEvenList(ListNode* head) {
        
        
        
        /*
        
        1. The question is to remove and insert alternate nodes.
        2. Corner Cases dealing is very important:
            a. Total Nodes less than or equal to 3, return same list.
            b. Total Nodes greater than 3, another method
        3. Key thing to notice is that after removal and insertion, we need to move back and current forward only by one.
        4. Algo:
            a. Keep 3 pointers - LastAdd, back, current
            b. Any removed node is added after lastAdd, and lastAdd updated.
            c. back and current incremented
            
        
        
        
        */
        
        if(head== NULL || head->next == NULL || head->next->next == NULL) return head;
        
        ListNode * lastOdd = head;
        ListNode * back = head;
        ListNode * current = back->next;
        
        ListNode * temp;
        
        while(current != NULL){
            
            
            
            
            back = back->next;
            current = current->next;
            
            
            if(current){
             
                back->next = current->next;
                temp = current;
                
                
                temp->next = lastOdd->next;
                lastOdd->next = temp;
               
                
                lastOdd = lastOdd->next;
                current = back->next;
                
                
            
            
            }
           
            
            
        }
        
       
       
       
        return head;
        
    }
};