class CustomStack {
public:
    vector<int> v;
    int mc, top;
    CustomStack(int n) {
        v.resize(n);
        mc = n;
        top = -1;
    }
    
    void push(int x) {
        if(top < mc - 1){
            top+=1;
            v[top] = x;
        }
        return;
    }
    
    int pop() {
        if(top != -1){
            int ans = v[top];
            top --;
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int n = min(k, top+1);
        for(int i=0; i<n;i++)v[i] += val;
    }
};

