class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        ListNode* t1=head1;
        ListNode* t2=head2;
        ListNode* result=new ListNode(-1);
        ListNode* curr=result;
        int carry=0;
        int sum=0;
        while(t1 || t2){
            sum=carry;
            if(t1)sum+=t1->val;
            if(t2)sum+=t2->val; 
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=newNode;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            curr->next=newNode;
        }
        return result->next;
    }
};