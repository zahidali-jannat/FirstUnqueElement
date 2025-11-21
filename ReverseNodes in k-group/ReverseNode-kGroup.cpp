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
    int length(ListNode *&head){
         int count=0;
         ListNode *temp=head;
         while(temp!=NULL){
              temp=temp->next;
              count++;
         }
         return count;
    }
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head==NULL){
           return NULL;
         }
    
        int count=0;
        int size=length(head);
        ListNode *current=head;
        ListNode *next=NULL;
        ListNode *prev=NULL;
    
        while(current!=NULL && count <k){
             next=current->next;
             current->next=prev;
             prev=current;
             current=next;
             count++;
        }
    
        if(size-count>=count){
           size=size-count;
           head->next=reverseKGroup(next , k);
        }
        else{
             head->next=next;
        }
        return prev;
       
        }
    };