// Problem 369


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

    ListNode * reverseLinkedList(ListNode * head){
        
        
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
    
    void printList(ListNode * head) {
        
        ListNode * front = head;
        
        while(front != NULL){
            
            cout <<  front-> val <<" : ";
            front = front->next;
            
        }
        
        cout << endl;
        
    }
    
    ListNode* plusOne(ListNode* head) {
        
        /*
        
        1. Simple Question
        2. With Linked List, the case to terminate is whether on front or front->next
        3. Corner Case:
            a. Single Digit
            b. Null Head
        
        */
        
        head = reverseLinkedList(head);
        
        ListNode * front  = head;
        int carry = 1;
        
        while(front->next != NULL){
            
            front->val = front->val + carry;
            carry = front->val / 10;
            front->val = front->val % 10;
            front = front->next;
            
        }
        
        front->val = front->val + carry;
        
        carry = front->val / 10;
        front->val = front->val % 10;
        
        
        if(carry){
            
            ListNode * node = new ListNode(carry);
            front->next = node;
            node->next = NULL;
        }
        
        head = reverseLinkedList(head);
        
        return head;
        
    }
};