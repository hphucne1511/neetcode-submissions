class LRUCache {
private:
    struct node{
        int val;
        int key;
        node* next;
        node* prev;
        node() : val(0), next(nullptr), prev(nullptr) {}
        node(int v, int key) : val(v), key(key), next(nullptr), prev(nullptr) {}
        node(int v, node* next, node* prev) : val(v), next(next), prev(prev) {}
    };
    node* left = new node(-1, -1);
    node* right = new node(-1, -1);
    unordered_map<int, node*> m;
    int cap;
public:
    LRUCache(int capacity) : cap(capacity) {
        left->next = right;
        right->prev = left;
    }
    ~LRUCache(){
        node* cur = left;
        while(cur){
            node* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        node* temp = m[key];
        del(temp);
        makeLast(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            m[key]->val = value;
            node* temp = m[key];
            del(temp);
            makeLast(temp);
        }else{
            node* temp = new node(value, key);
            makeLast(temp);
            m.insert({key, temp});
            if(cap == 0){
                node* t = left->next;
                del(t);
                m.erase(t->key);
                delete t;
            }else{
                cap--;
            }
        }
    }
    void del(node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
        n->prev = nullptr;
        n->next = nullptr;
    }
    void makeLast(node* n){
        n->prev = right->prev;
        n->next = right;
        right->prev->next = n;
        right->prev = n;
    }
};
