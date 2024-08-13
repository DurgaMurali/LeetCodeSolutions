#include <cmath>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int)nums.size();
        int i=0, j=size-1;
        int num_zeros = 0;
        int product = 1;
        vector<int> result(size);

        while(i<=j && j>=i)
        {
            if(nums[i] == 0)
                num_zeros++;

            if (num_zeros <= 1 && nums[i] != 0)
                product *= nums[i];

            if(i == j)
                break;

            if(nums[j] == 0)
                num_zeros++;

            if (num_zeros <= 1 && nums[j] != 0)
                product *= nums[j];

            i++;
            j--;
        }
        
        i=0, j=size-1;
        while(i<=j && j>=i)
        {
            if ((num_zeros > 1) || (num_zeros == 1 && nums[i] != 0))
                result[i] = 0;
            else if (num_zeros == 1 && nums[i] == 0)
                result[i] = product;
            else if (num_zeros == 0)
                result[i] = product * pow(nums[i], -1);

            if(i == j)
                break;

            if ((num_zeros > 1) || (num_zeros == 1 && nums[j] != 0))
                result[j] = 0;
            else if (num_zeros == 1 && nums[j] == 0)
                result[j] = product;
            else if (num_zeros == 0)
                result[j] = product * pow(nums[j], -1);

            i++;
            j--;
        }

        return result;
    }
};