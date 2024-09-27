class MyCalendarTwo {
public:
    vector<pair<int,int>> booking, doublebooking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto it : doublebooking){
            if(max(it.first, start) < min(it.second, end))return false;
        }

        for(auto it: booking){
            if(max(it.first, start) < min(it.second, end)){
                doublebooking.push_back(
                    {max(it.first, start), min(it.second, end)}
                );
            }
        }
        booking.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */