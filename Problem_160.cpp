// Problem 160

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        /*
        1. Very good question in terms of thinking.
        2. Good Idea.
        
        */
        
        ListNode * travelA = headA;
        ListNode * travelB = headB;
        
        if(travelA == NULL || travelB == NULL) return NULL;
        
        while(travelA != travelB && travelA != NULL && travelB != NULL){
            
            
            
            travelA = travelA->next;
            travelB = travelB->next;
            
            if(travelA == travelB) break;
            
            if(travelA == NULL) travelA = headB;
            if(travelB == NULL) travelB = headA;
            
            
            
        }
        
        return travelA;
        
    }
};