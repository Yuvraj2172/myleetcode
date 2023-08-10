class LFUCache {
public:
    class node{
        public:
        int key, value, cnt;
        node* next;
        node* prev;
        node(int _key, int _value){
            key = _key;
            value = _value;
            cnt=1;
        }
    };
    class list{
        public:
        int size;
        node* head;
        node* tail;
        list(){
            head = new node(0,0);
            tail = new node(0,0);
            head->next = tail;
            tail->prev = head;
            size=0;
        }
        void addfront(node* n){
            node* temp = head->next;
            n->next = temp;
            n->prev = head;
            temp->prev = n;
            head->next = n;
            size++;
        }
        void removenode(node* delnode){
            node* delnext = delnode->next;
            node* delprev = delnode->prev;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };
    map<int, node*> keyNode;
    map<int, list*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(node* n){
        keyNode.erase(n->key);
        freqListMap[n->cnt]->removenode(n);
        if(n->cnt == minFreq && freqListMap[n->cnt]->size==0){
            minFreq++;
        }
        list* nextHigherFreqList = new list();
        if(freqListMap.find(n->cnt+1)!= freqListMap.end()){
            nextHigherFreqList = freqListMap[n->cnt+1];
        }
        n->cnt +=1;
        nextHigherFreqList->addfront(n);
        freqListMap[n->cnt] = nextHigherFreqList;
        keyNode[n->key] = n;
    }
    int get(int key) {
        if(keyNode.find(key)!= keyNode.end()){
            node* n = keyNode[key];
            int val = n->value;
            updateFreqListMap(n);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            node* n = keyNode[key];
            n->value = value;
            updateFreqListMap(n);
        }
        else{
            if(curSize == maxSizeCache){
                list* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removenode(list->tail->prev);
                curSize--;
            }
            curSize++;
            // new value has to be added which is not there previously 
            minFreq = 1;
            list* listFreq = new list();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            node* n = new node(key, value);
            listFreq->addfront(n);
            keyNode[key] = n;
            freqListMap[minFreq] = listFreq;
        }
    }
};

