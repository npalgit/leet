// Problem 24

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
    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode * back = dummy;
        ListNode * front = head;
        ListNode * visit = front->next;
        ListNode * nextFront = NULL;
        
         //cout << "Before While" << endl;
        
        while(visit) {
            //cout << "In while" << endl;
            nextFront = visit->next;
            visit->next = front;
            front->next = nextFront;
            back->next = visit;
            
            back = front;
            front = nextFront;
            if(front) visit = front->next;
            else visit = NULL;
            
            
        }
        //cout << "After While" << endl;
        
        head = dummy->next;
        
        delete dummy;
        return head;
        
    }
};