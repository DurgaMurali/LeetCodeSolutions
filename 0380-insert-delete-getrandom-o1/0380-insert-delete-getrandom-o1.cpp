class RandomizedSet {
public:
    std::unordered_set<int> set;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        std::pair<std::unordered_set<int>::iterator, bool> out = set.insert(val);
        return out.second;
    }
    
    bool remove(int val) {
        size_t erased = set.erase(val);
        if(erased >= 1)
            return true;
        else
            return false;
    }
    
    int getRandom() {
        int index = rand()%set.size();
        unordered_set<int>::iterator itr = set.begin();
        std::advance(itr, index);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */