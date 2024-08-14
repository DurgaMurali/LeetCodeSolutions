class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};

        if(nums.empty())
            return result;

        result[0] = findFirst(nums, target, nums.size()-1, 0);
        result[1] = findLast(nums, target, nums.size()-1, 0);

        return result;
    }

    int findFirst(vector<int> &nums, int target, int high, int low){
        if(low > high)
            return -1;

        int mid = (high + low)/2;
        if(nums[mid] == target)
        {
            if(mid-1 >= 0 && nums[mid-1] != nums[mid])
                return mid;
            else if(mid-1 < 0)
                return mid;
            else
                high = mid-1;
        }
        else if(nums[mid] > target)
            high = mid-1;
        else
            low = mid+1;

        return findFirst(nums, target, high, low);
    }

    int findLast(vector<int> &nums, int target, int high, int low){
        if(low > high)
            return -1;

        int mid = (high + low)/2;
        if(nums[mid] == target)
        {
            if(mid+1 < nums.size() && nums[mid+1] != nums[mid])
                return mid;
            else if(mid+1 >= nums.size())
                return mid;
            else
                low = mid+1;
        }
        else if(nums[mid] > target)
            high = mid-1;
        else
            low = mid+1;

        return findLast(nums, target, high, low);
    }
};