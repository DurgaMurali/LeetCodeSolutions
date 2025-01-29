class RecentCounter {
public:
    list<int> times;

    RecentCounter() {
        times.clear();
    }
    
    int ping(int t) {
       times.push_back(t);

       int range = t - 3000;
       
        while(times.front() < range)
            times.pop_front();

       return times.size(); 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */