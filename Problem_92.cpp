// Problem 92

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


   
   ListNode* reverseList(ListNode* head, int count) {
        
        
        
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
        
        int counter = 0;
        while(front != NULL && counter < count){
            
            visit = front->next;
            front->next = back;
            
            if(back->next == front) back->next = NULL;
            back = front;
            front = visit;
            
            counter++;
            
        }
        
        head->next = front;
        return back;
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        
        /*
        
        1. Take care of Corner Cases
        2. Always think of what will happen when m = 1, and m = 2
        3. A corner case when m = 1
        
        
        
        */
    
        if(head->next == NULL) return head;
        
        ListNode * firstLast = NULL;
        ListNode * secondFirst;
        ListNode* secondLast;
        ListNode* thirdFirst=NULL;
        
        for(int i = 0; i < m-2;i++){
            
            if(firstLast == NULL) firstLast = head;
            firstLast = firstLast->next;
            
        }
        
       // cout << "First Last = " << firstLast << endl;
        
        if(firstLast == NULL && m ==1) secondFirst = head;
        else if(firstLast == NULL && m ==2) {
            
            firstLast = head;
            secondFirst = head->next;
        }
        else secondFirst = firstLast->next;
        //firstLast->next = NULL;
        
        secondLast = reverseList(secondFirst, n-m);
        
        if(thirdFirst)cout << "ThirdFirst = " << thirdFirst->val << endl;
        //secondFirst->next = thirdFirst;
        
        
        if(firstLast)firstLast->next = secondLast;
        
        
        
        if(firstLast)return head;
        else return secondLast;
        
        
        
        
        
    }
};