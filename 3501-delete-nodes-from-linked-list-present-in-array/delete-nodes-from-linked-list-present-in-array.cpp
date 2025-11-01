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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* curr=head;


        unordered_set<int> st;
        for(auto it : nums) st.insert(it);


        while(curr!=NULL){

            if(st.find(curr->val)!=st.end() ){
                

                if(prev==NULL && curr->next==NULL){
                    return NULL;
                }
                else if(prev==NULL) {
                    ListNode* temp=curr->next;
                    curr->next=NULL;
                    curr=temp;
                    head=curr;
                }
                else if(curr->next==NULL){
                    prev->next=NULL;
                    curr=NULL;
                }
                else {
                    prev->next=curr->next;
                    curr->next=NULL;
                    curr=prev->next;

                }
               
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
        }

        return head;

    }
};