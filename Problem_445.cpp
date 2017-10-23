// Problem 445


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
        
        cout << "Printing the List" << endl;
        
        ListNode * visit = head;
        
        while(visit != NULL){
            
            cout << visit->val << " : ";
            visit = visit->next;
            
        }
        cout << endl;
        
    }

    ListNode* reverseList(ListNode * head){
        
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode * front = NULL;
        ListNode * dummy = new ListNode(INT_MIN);
        
        ListNode *back = dummy;
        
        ListNode * head = NULL;
        
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        
        int carry = 0;
        int new_val;
        
        
        
        while(head1 != NULL && head2 != NULL){
            
            
            new_val = head1->val + head2->val + carry;
            
            cout << "New Val = " << new_val << endl;
            carry = new_val / 10;
            new_val = new_val % 10;
            
            front = new ListNode(new_val);
            
            if(back->val == INT_MIN) {
                
                head = front;
                cout << "Head Value = " << head->val << endl;    
                
            }
            
            
            
            if(back != front)back->next = front;
            back = front;
            front = NULL;
            
            
            head1 = head1->next;
            head2 = head2->next;
            
            cout << "Another Iteration" << endl;
            
        }
        
        cout << "Out of both loops" << endl; 
        
        while(head1 != NULL){
            
            cout << "Head 1 NOT NULL" << endl;
            
            new_val = head1->val + carry;
            
            carry = new_val / 10;
            new_val = new_val % 10;
            
            front = new ListNode(new_val);
            
            
            
            
            if(back != front)back->next = front;
            back = front;
            front = NULL;
            
            
            head1 = head1->next;
            
            
        }
        
        
        
        
        
        while(head2 != NULL){
            
            cout << "Head 2 NOT NULL" << endl;            
            
            new_val = head2->val + carry;
            
            carry = new_val / 10;
            new_val = new_val % 10;
            
            front = new ListNode(new_val);
            
            
            
            
            if(back != front)back->next = front;
            back = front;
            front = NULL;
            
            
            head2 = head2->next;
            
        }
        
        
        
        if(carry){
            
            ListNode *front = new ListNode(carry);
            if(back != front)back->next = front;
            back = front;
            front = NULL;
            
        }
        
        back->next = NULL;
        cout << "End Value = " << back->val << endl;
        
        delete dummy;
        
        printList(head);
        ListNode *return_head = reverseList(head);
        
        
        return return_head;
        
    }
};