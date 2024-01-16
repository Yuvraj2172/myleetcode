class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        else {
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            s.erase(val);
            return true;
        }
        else {
            
            return false;
        }
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size());
    }
};

