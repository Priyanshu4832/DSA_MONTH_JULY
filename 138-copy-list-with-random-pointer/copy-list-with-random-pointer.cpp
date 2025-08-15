/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) {
            Node* copy = new Node(head->val);
            if(head->random!=0) copy->random = copy;
            else copy->random = 0;
            return copy;
        }
        //step 1 create interweaved

        Node* mov = head;
        while(mov!=NULL){
            Node* store = mov->next;

            Node* copyNode = new Node(mov->val);
            mov->next = copyNode;
            copyNode->next = store;
            mov = store;
        }

        //step 2 now point random
        Node* movOriginal = head;
        Node* movCopy = head->next;
        while(true){

            Node* random = movOriginal->random;
            if(random!=0){
                movCopy->random = random->next;
            }
            else{
                movCopy->random = 0;
            }

            movOriginal = movOriginal->next->next;
            if(movOriginal == NULL) break;
            movCopy = movCopy->next->next;
        }
        movOriginal = head;
        movCopy = head->next;
        //step 3 separate both linked list

        

        Node* Original = head;
        Node* Copy = head->next;
        while(true){

            Original->next = Copy->next;
            Copy->next = Copy->next->next;
            

            Copy = Copy->next;
            Original = Original->next;

            
            if(Copy->next == NULL){
                Original->next=NULL;
                break;
            } 
           
        }



        return movCopy;





    }
};