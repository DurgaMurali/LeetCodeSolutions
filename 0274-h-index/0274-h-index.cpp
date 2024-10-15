class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int total = citations.size();

        int result = 0;
        for(int i=0; i<total; ++i)
        {
            if(citations[i] > 0)
            {
                if(total-i >= citations[i] && result < citations[i])
                    result = citations[i];
                else if(total-i < citations[i] && result < total-i)
                    result = total-i;
            }
            
        }
        return result;
    }
};