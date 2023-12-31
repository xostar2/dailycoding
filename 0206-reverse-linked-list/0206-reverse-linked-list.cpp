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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode*cur=head;
        ListNode* start=NULL;
        ListNode*pre=NULL;
        ListNode* end=NULL ;
        
        while(cur!=NULL){
            end=cur->next;
            cur->next=pre;
            pre=cur;
            cur=end;
            
        }
        
        
        return  pre;
    }
};