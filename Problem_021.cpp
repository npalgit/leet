// Problem 21

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        
        /*
        1. Very easy problem with the concept of Dummy Node
        2. Simple Merge Sort Problem
        
        
        */
        ListNode * l1Next;
        ListNode * l2Next;
        ListNode * start = new ListNode(0);
        ListNode * last = start;
        
        while(l1 && l2){
            
            if(l1->val >= l2->val){
                
                l1Next = l1->next;
                l2Next = l2->next;
                
                
                last->next = l2;
                l2 = l2Next;
                
                last = last->next;
                last->next = NULL;
            }
            
            else {
                
                l1Next = l1->next;
                l2Next = l2->next;
                
                last->next = l1;
                l1 = l1Next;
                
                last = last->next;
                last->next = NULL;
                
                
            }
            
            
            
        }
        
        
        if(l1 != NULL) last->next = l1;
        if(l2 != NULL) last->next = l2;
        
        last =start->next;
        delete start;
        
        return last;
        
    }
};