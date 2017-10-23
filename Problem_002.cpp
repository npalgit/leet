// Problem 2.cpp

/*
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * back = NULL;
        ListNode * temp = NULL;
        ListNode * start = NULL;
        int carry = 0;
        int mod;
        
        while(temp1 != NULL && temp2 != NULL){
            
             mod = temp1->val + temp2->val + carry;
            
            carry = mod/10;
            mod = mod%10;
             
              temp = new ListNode(mod);
             if(start == NULL) start = temp;
             if(back != NULL) back->next = temp;
           
          // cout << mod << "---"<<temp1 << "----"<< temp2 << endl;
            temp1 = temp1->next;
            //cout << mod << "---"<<temp1 << "----"<< temp2 << endl;
            temp2 = temp2->next;
            //cout << mod << "---"<<temp1 << "----"<< temp2 << endl;
            back = temp;
            
            
            
            
        }
        
        while(temp1 != NULL){
            
            mod = temp1->val + carry;
            
            carry = mod/10;
            mod = mod%10;
 
            
            temp = new ListNode(mod);
                       
            if(start == NULL) start = temp;
            if(back != NULL) back->next = temp;

            temp1 = temp1->next;
            
            back = temp;
            
        }
        
            while(temp2 != NULL){
            
            mod = temp2->val + carry;
            
            carry = mod/10;
            mod = mod%10;
            
            temp = new ListNode(mod);
            
            if(start == NULL) start = temp;
            if(back != NULL) back->next = temp;
            

            

            temp2 = temp2->next;
            
            back = temp;
            
        }
        
        
        if(carry > 0) {
            
            temp = new ListNode(carry);
         
            back->next = temp;
            
            
        }
        
        return start;
    }
};