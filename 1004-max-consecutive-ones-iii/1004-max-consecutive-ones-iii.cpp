class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int max_sum = 0;
        int num_flips = k;

        int start_index = 0;
        int end_index = 0;
        int sum = 0;

        while(end_index < size)
        {
            if(nums[end_index] == 0 && num_flips > 0)
            {
                sum++;
                num_flips--;
                end_index++;
            }
            else if(nums[end_index] == 1)
            {
                sum++;
                end_index++;
            }
            else if(nums[end_index] == 0 && num_flips <= 0)
            {
                if (sum > max_sum)
                    max_sum = sum;

                if (nums[start_index] == 0)
                {
                    sum--;
                    num_flips++;
                }
                else if (nums[start_index] == 1)
                    sum--;

                start_index++;

                if(num_flips > 0)
                {
                    sum++;
                    num_flips--;
                    end_index++;
                }
            }
        }

        if (sum > max_sum)
            max_sum = sum;

        return max_sum;
    }
};