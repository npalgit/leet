// Problem 23

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

typedef vector<ListNode*> Vector;
typedef pair<int, ListNode*>  Pair;
typedef priority_queue<Pair, vector<Pair>, greater<Pair>> PQ;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        // Following Solution is O(nlogn) in time and O(n) in space.
        
        /*
        if(lists.empty()) return NULL;
        
        PQ myPQ;
        for(int i = 0; i < lists.size(); i++){
            
            ListNode * front = lists[i];
            
            while(front != NULL){
                
                myPQ.push(make_pair(front->val, front) );
                front = front->next;
                
            }
            
            
        }
        
        ListNode * answer = new ListNode(INT_MAX);
        ListNode * travel;
        
        while(myPQ.size()){
            
            if(answer->val == INT_MAX){
                
                answer->val = myPQ.top().first;
                answer->next = NULL;
                travel = answer;
                myPQ.pop();
                continue;
            } 
            
            
                
            travel->next = new ListNode(myPQ.top().first);
            travel = travel->next;
            
            travel->next = NULL;
            myPQ.pop();
            
        }
        
        if(answer->val == INT_MAX ) return NULL;
        else return answer;
        */
        
        
        PQ myPQ;
        
        for(int i = 0; i < lists.size(); i++){
            
            if(lists[i]) myPQ.push(make_pair(lists[i]->val, lists[i]));
            
        }
        
        
        //ListNode * answer = new ListNode(INT_MAX);
        
        ListNode * answer = new ListNode(0);
        ListNode * travel = answer;
   
        
        while(myPQ.size()){
           
            
            travel->next = myPQ.top().second;
            travel = travel->next;
            
            
            if(travel->next) myPQ.push(make_pair(travel->next->val, travel->next));
            
            travel->next = NULL;
            
            myPQ.pop();
            
            
            
        }
        
       
        
        return answer->next;
        
        
    }
};