class MyQueue {
public:
    queue<int> q;
    MyQueue() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.size()!=0){
            int ele = q.front();
            q.pop();
            return ele;
        }
        return -1;
    }
    
    int peek() {
        if(!q.empty())
        return q.front();
        return -1;
    }
    
    bool empty() {
        return q.size() ==0 ;
    }
};
