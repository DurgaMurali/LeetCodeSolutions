class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> occurrences;

        int count = 1;
        for(int i=0; i<arr.size()-1; ++i)
        {
            if(arr[i] == arr[i+1])
                count++;

            else if(arr[i] != arr[i+1])
            {
                pair<unordered_set<int>::iterator, bool> result = occurrences.insert(count);
                count = 1;
                if(!result.second)
                    return false;
            }
        }

        if(count >= 1)
        {
            pair<unordered_set<int>::iterator, bool> result = occurrences.insert(count);
            if(!result.second)
                return false;
        }

        return true;
    }
};