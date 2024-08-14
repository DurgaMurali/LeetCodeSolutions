class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0)
            return -1;
        else if(size == 1)
            return binarySearch(nums, target, size-1, 0);
        else
        {
            int pivot = findPivot(nums, nums[size-1], size-1, 0);
            std::cout << "pivot = " << pivot << std::endl;

            if(pivot > -1)
            {
                if(target >= nums[pivot] && target <= nums[size-1])
                    return binarySearch(nums, target, size-1, pivot);
                else
                    return binarySearch(nums, target, pivot-1, 0);
            }
            else
                return binarySearch(nums, target, size-1, 0);
        }

        return -1;
    }

    int findPivot(vector<int> &nums, int target, int high, int low)
    {
        if(low > high)
            return -1;

        int mid = (high + low)/2;

        if(nums[mid] > target)
            low = mid+1;
        else if(nums[mid] <= target && mid-1 >= 0 && nums[mid-1] > nums[mid])
            return mid;
        else
            high = mid-1;

        return findPivot(nums, target, high, low);
    }

    int binarySearch(vector<int> &nums, int target, int high, int low)
    {
        if(low > high)
            return -1;

        int mid = (high + low)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            low = mid+1;
        else
            high = mid-1;

        return binarySearch(nums, target, high, low);
    }
};