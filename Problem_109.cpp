// Problem 109

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        /*
        1. Recursive Solution Works best.
        2. Get to the middle of the list using the slow pointer when the fast pointer reaches the end..
        3. Keep a back pointer to keep track of the left to mid node.
        4. Root  carries the head value.
        5. Recursive for right and left subtrees.
        6. Corner Cases:
            a. When head is NULL
            b. When head has a single node in the Linked List.
            c. Another corner case when the number of elements in the list only remain 2
            d. Starting List elements being 3, everything remains in the normal case
        
        */
        
        
        if(head == NULL) return NULL;
        
        if(head->next == NULL){
            
            TreeNode * root = new TreeNode(head->val);
            return root;
        }
        
        
        ListNode * init = new ListNode(INT_MIN);
        
        ListNode * back = init;
        ListNode * slow = head;
        ListNode * fast = head;
        
        back->next = head;
        
        while(fast->next != NULL){
            
            slow = slow->next;
            back = back->next;
            
            if(fast->next) fast = fast->next;
            if(fast->next) fast = fast->next;
            
        }
        
        
        
        TreeNode * root = new TreeNode(slow->val);
        
        back->next = NULL;
        
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        delete init;
        
        return root;
        
        
    }
};