class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : v){
            int istart = it.first;
            int iend = it.second;

            if(iend > start)return false;
        }
        v.push_back(make_pair(start,end));
        return 1;
    }
};
