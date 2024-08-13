class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size();
        int max_subsequence = 0;
        int sum = 0;
        int next_sum = 0;

        int index = 0;
        while(index < size)
        {
            if (nums[index] == 1)
            {
                sum++;
                next_sum++;
            }
            else if (nums[index] == 0)
            {
                if (sum > max_subsequence)
                    max_subsequence = sum;

                sum = next_sum;
                next_sum = 0;
            }
            index++;
        }

        if (sum == size)
            sum--;
        if (sum > max_subsequence)
            max_subsequence = sum;

        return max_subsequence;
    }
};