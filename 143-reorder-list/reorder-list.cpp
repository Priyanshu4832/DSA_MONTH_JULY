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

    ListNode* rev(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* ahead = head;


        while(ahead!=NULL){
            ahead = curr->next;

            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        
        ListNode* tort = head;
        ListNode* hare = head;

        while(hare->next!=NULL && hare->next->next!=NULL){
            tort = tort->next;
            hare = hare->next->next;
        }
        
        ListNode* new_head = tort->next;
        tort->next = NULL;


        ListNode* head1 = head;
        ListNode* head2 = rev(new_head);


        while(head1!=NULL && head2!=NULL){
            ListNode* store1 = head1->next;
            head1->next = head2;
            ListNode* store2 = head2->next;
            head2->next=store1;

            head1 = store1;
            head2 = store2;
        }
    }
};