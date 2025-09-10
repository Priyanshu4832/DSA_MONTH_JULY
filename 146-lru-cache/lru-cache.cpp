
class LRUCache{
    
private:
    struct Node{
        int key;
        int value;
        Node* next ;
        Node* prev ;
        
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }

    };
    Node* head;
    Node* tail;
    
    int capacity;
    unordered_map<int,Node*> cache;
    
    void deleteNode(Node* node){
        Node* previous = node->prev;
        Node* ahead = node->next;
        
        previous->next = ahead;
        ahead->prev = previous;
        
        node->next = NULL;
        node->prev = NULL;
    }
    void insertAfterHead(Node* node){
        Node* nodeAfterHead = head->next;
        
        head->next = node;
        node->prev = head;
        node->next = nodeAfterHead;
        nodeAfterHead->prev = node;
    }





public:

    LRUCache(int capacity){
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key){
        
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Node* node = cache[key];
        
        deleteNode(node);
        insertAfterHead(node);
        
        return node->value;
    }
    void put(int key , int value){
        
        if(cache.find(key)!=cache.end()){
            //node exist
            Node* node = cache[key];
            //delete node then put in front
            deleteNode(node);
            insertAfterHead(node);
            //update the value
            node->value = value;
        }
        
        
        else if(cache.size()<capacity){
            //key not there so add it
            Node* node = new Node(key,value);
            insertAfterHead(node);
            //insert in cache map
            cache[key]=node;
        }
        else{
            //key is not there and cpacity is full
            //remove tail guy and add new guy
            Node* nodeBeforeTail = tail->prev;
            deleteNode(nodeBeforeTail);
            
            int tailKey = nodeBeforeTail->key;
            cache.erase(tailKey);
            Node* node = new Node(key,value);
            insertAfterHead(node);
            cache[key]=node;
            
        }
    }
    
    
    
    
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */