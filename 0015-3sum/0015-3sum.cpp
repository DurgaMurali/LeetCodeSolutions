class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        int index1 = 0;

        std::sort(nums.begin(), nums.end());

        while(index1 < size-2)
        {
            int target = -nums[index1];
            int index2 = index1+1;
            int index3 = size-1;

            while(index2 < index3)
            {
                int sum = nums[index2] + nums[index3];
                if(sum == target)
                {
                    vector<int> zero_vec;
                    zero_vec.push_back(nums[index1]);
                    zero_vec.push_back(nums[index2]);
                    zero_vec.push_back(nums[index3]);
                    result.push_back(zero_vec);
                    while(index2+1 < index3 && nums[index2+1] == nums[index2])
                        index2++;
                    index2++;
                }
                else if(sum > target)
                    index3--;
                else if(sum < target)
                    index2++;
            }

            while(index1+1 < size-2 && nums[index1+1] == nums[index1])
                index1++;
            index1++;
        }

        return result;
    }
};