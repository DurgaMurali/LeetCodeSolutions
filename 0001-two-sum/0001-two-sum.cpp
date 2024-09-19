class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> map;
        vector<int> result;
        
        for(int i=0; i<size; i++)
        {
            map.insert(make_pair(nums[i], i));
        }
        
        for(int i=0; i<size; i++)
        {
            int remainder = target - nums[i];
            unordered_map<int, int>::iterator it = map.find(remainder);
            if(it != map.end() && (*it).second != i)
            {
                int index = (*it).second;
                if(index != i)
                {
                    result.push_back(index);
                    result.push_back(i);
                }
                /*if(i > index)
                {
                    result.push_back(index);
                    result.push_back(i);
                }
                else
                {
                    result.push_back(i);
                    result.push_back(index);
                }*/
                return result;
            }      
        }
        
        return result;
    }
};