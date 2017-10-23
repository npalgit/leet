// Problem 138

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 using namespace std;
 
 typedef unordered_map<RandomListNode * , RandomListNode *> HashMap;
 
class Solution {
    
private:
    HashMap myMap;
    
public:
    RandomListNode *copyRandomList(RandomListNode *head) {


        /*
        1. This is Solution 1.
        2. It is O(n) in time and O(n) in space
        
        
        if(head == NULL) return NULL;
        RandomListNode * travel = head;

        RandomListNode * start = new RandomListNode(0);
        RandomListNode * back = start;
        RandomListNode * front;
        
        while(travel)  {
            
            front = new RandomListNode(travel->label);
            back->next = front;
            
            myMap[travel] = front;
            
            back = front;
            travel = travel->next;
            
            
            
        }
        
        back->next = NULL;
        
        travel = head;
        back = start->next;
        
        while(travel){
            
            front = travel->random;
            
            if(front) {
                
                back->random = myMap[front];
                
            }
            
            back = back->next;
            travel = travel->next;
            
            
            
        }
        
    
        RandomListNode * finalHead = start->next;
        
        delete start;
        
        return finalHead;
        
        */
        
        
        
        /*
        1. This is the 2nd Solution
        2. This is O(n) in time and O(1) in space.
        3. We traverse the Linked List 3 times in this solution
        
        */
        
        
        if(head == NULL) return NULL;
        RandomListNode * travel = head;

        
        RandomListNode * front;
        
        
        // Ist Pass
        // Generating new Nodes for every node in the LL
        // New Node is placed just next to the original node
        while(travel)  {
            
            front = new RandomListNode(travel->label);
            front->next = travel->next;
            
            travel->next = front;
            
            travel = travel->next->next;
            
        }
        
        
        
        // 2nd Pass
        // This is used to do the random pointer atttachments in the new nodes
        RandomListNode * visit;
        travel = head;
        
        while(travel)  {
            
            
            front = travel->next;
            
            visit = travel->random;
            
            if(visit) {
                
                front->random = visit->next;
                
            }
            
            travel = travel->next->next;
            
        }
        
        
        
        travel = head;
        
        RandomListNode * start = travel->next;
        
        front = travel->next;
        
        
        // 3rd Pass
        // This is used to separate the 2 Linked Lists
        // Basically, every alternate node is attached to a new list
        while(travel){
            
            travel->next = front->next;
            
            
            travel = travel->next;
            
            if(travel) {
                
                front->next = travel->next;
                front = front->next;
            
            }
            
        }
        
        
        return start;
        
        
    }
};