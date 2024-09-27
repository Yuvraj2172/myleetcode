class MyCalendarTwo {
public:
    vector<pair<int,int>> booking;
    vector<pair<int,int>> doublebooking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto e : doublebooking){
            if(max(e.first, start) < min(e.second, end)){
                return 0;
            }
        }
        for(auto e : booking){
            if(max(e.first, start), min(e.second, end)){
                doublebooking.push_back({max(e.first, start), min(e.second, end)});
            }
        }

        booking.push_back({start,end});
        return 1;

    }
};

auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();