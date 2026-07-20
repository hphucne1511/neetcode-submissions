class MyHashMap {
private:
    struct node{
        pair<int, int> data;
        node* next;
        node(pair<int, int> kv) : data(kv), next(nullptr) {}
    };
    node* arr[10000] = {};
    int hashFunction(int key){
        return key % 10000;
    }
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int newKey = hashFunction(key);
        node* curr = arr[newKey];
        while(curr != nullptr){
            if(curr->data.first == key){
                curr->data.second = value;
                return;
            }
            curr = curr->next;
        }
        node* temp = new node({key, value});
        temp->next = arr[newKey];
        arr[newKey] = temp;
    }
    
    int get(int key) {
        node* curr = arr[hashFunction(key)];
        while(curr != nullptr && curr->data.first != key){
            curr = curr->next;
        }
        if(curr == nullptr) return -1;
        return curr->data.second;
    }
    
    void remove(int key) {
        int idx = hashFunction(key);
        node* curr = arr[idx];
        node* prev = nullptr;
        while(curr != nullptr){
            if(curr->data.first == key){
                if(prev == nullptr){
                    arr[idx] = curr->next;
                    delete curr;
                    return;
                }else{
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        if(curr == nullptr) return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */