class TimeMap {
public:
    map<string ,map<int, string, greater<int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key)==0)return "";
        auto it = mp[key].lower_bound(timestamp);
        if(it!=mp[key].end())return it->second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */