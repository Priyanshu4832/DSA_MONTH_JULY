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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* mov = head;
        int cnt = 0;


        ListNode* start=NULL;
        ListNode* end=NULL;
        ListNode* prev = NULL;
        ListNode* behind = NULL;
        ListNode* ahead = NULL;

        while(mov!=NULL){

            
            cnt+=1;
            if(cnt<=left){
                start = mov;
                prev = behind;
            }
            if(cnt==right){
                end = mov;
                ahead = mov->next;
                break;
            }
            behind = mov;
            mov = mov->next;
        }

        //prev is start ka prev
        //ahead is end ka ahead;

        if(prev==NULL){
            //starting node aa gaya
            end->next = NULL;
            ListNode* newHead = rev(start);

            ListNode* mover = newHead;
       
            while(mover->next!=NULL){
                mover=mover->next;
            }
            mover->next = ahead;
            return newHead;


        }
        if(prev==NULL && ahead==NULL){
            return rev(head);
        }
        prev->next = NULL;

        end->next = NULL;

        prev->next = rev(start);
        ListNode* mover = prev->next;
       
        while(mover->next!=NULL){
            mover=mover->next;
        }
        mover->next = ahead;

        return head;


    }
};