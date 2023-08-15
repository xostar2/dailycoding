/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummy=new ListNode(0);
        dummy.next=head;
        ListNode steady=dummy;
        ListNode move=dummy;
        int flag=0;
        if(head==null)return null;
        while(move!=null && move.next!=null){
            
            if(move.next.val==x && flag==0 ){
                flag=1;
                steady=move;
                move=move.next;
            }
            else if(  move.next.val>x && flag==0){
                flag=1;
                steady=move;
                move=move.next;
            }
            else if(  move.next.val<x && flag==0){
                move=move.next;
            }
            else if(move.next.val<x && flag==1  ){
                ListNode temp1=steady;
                ListNode temp2=steady.next;
                ListNode temp3=move;
                ListNode temp4=move.next;
                    temp3.next=temp4.next;
                    temp1.next=temp4;
                    temp4.next=temp2;
                    move=temp3;
                    steady=temp4;
                
            }
            else if(move.next.val>=x && flag==1){
                move=move.next;
            }
        }
        return dummy.next;
    }
}