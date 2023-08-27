/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class cmp{
    public:
     bool operator()(ListNode*a,ListNode*b){
         return a->val>b->val;
     }
    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        ListNode*tail=dummy;
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;        
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        
        while(!pq.empty()){
            ListNode*x=pq.top();
            pq.pop();
            
            tail->next=x;
            tail=x;
            if(tail->next!=NULL)pq.push(tail->next);
        }
        return dummy->next;
        
    }
};