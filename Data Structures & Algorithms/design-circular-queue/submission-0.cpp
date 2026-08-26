class MyCircularQueue {
private:
    int size;
    struct node{
        int val;
        node* next;
        node() : val(0), next(nullptr) {}
        node(int v) : val(v), next(nullptr) {}
    };
    node* fr = nullptr;
    node* re = nullptr;
public:
    MyCircularQueue(int k) : size(k) {
        
    }
    
    bool enQueue(int value) {
        if(size == 0) return false;
        if(!fr){
            fr = new node(value);
            re = fr;
        }else{
            re->next = new node(value);
            re = re->next;
        }
        size--;
        return true;
    }
    
    bool deQueue() {
        if(!fr) return false;
        node* temp = fr;
        if(fr == re){
            fr = nullptr;
            re = nullptr;
            delete temp;
        }else{
            fr = fr->next;
            delete temp;
        }
        size++;
        return true;
    }
    
    int Front() {
        if(!fr) return -1;
        return fr->val;
    }
    
    int Rear() {
        if(!fr) return -1;
        return re->val;
    }
    
    bool isEmpty() {
        return !fr;
    }
    
    bool isFull() {
        return size == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */