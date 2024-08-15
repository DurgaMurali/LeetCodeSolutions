class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> sorted_nums;

        while(index1 < nums1_size && index2 < nums2_size)
        {
            if(nums1[index1] > nums2[index2])
            {
                int low_index = binarySearch(nums2, nums1[index1], nums2_size-1, index2);
                low_index = (low_index >= nums2_size) ? nums2_size-1 : low_index;
                low_index = (nums2[low_index] > nums1[index1]) ? low_index-1 : low_index;

                for(int i=index2; i<=low_index; i++)
                    sorted_nums.push_back(nums2[i]);

                sorted_nums.push_back(nums1[index1]);

                index1++;
                index2 = low_index+1;
            }
            else if(nums2[index2] > nums1[index1])
            {
                int low_index = binarySearch(nums1, nums2[index2], nums1_size-1, index1);
                low_index = (low_index >= nums1_size) ? nums1_size-1 : low_index;
                low_index = (nums1[low_index] > nums2[index2]) ? low_index-1 : low_index;

                for(int i=index1; i<=low_index; i++)
                    sorted_nums.push_back(nums1[i]);

                sorted_nums.push_back(nums2[index2]);

                index2++;
                index1 = low_index+1;
            }
            else
            {
                sorted_nums.push_back(nums1[index1]);
                sorted_nums.push_back(nums2[index2]);
                index1++;
                index2++;
            }
        }

        while(index1 < nums1_size)
        {
            sorted_nums.push_back(nums1[index1]);
            index1++;
        }

        while(index2 < nums2_size)
        {
            sorted_nums.push_back(nums2[index2]);
            index2++;
        }

        int total_size = nums1_size + nums2_size;
        /*for(int i=0; i<total_size; i++)
            std::cout << sorted_nums[i] << ", ";
        std::cout << "\n";*/
        double result = 0.0;
        if(total_size % 2 > 0)
            result = sorted_nums[total_size/2];
        else
        {
            int middle_index = total_size/2;
            result = (sorted_nums[middle_index-1] + sorted_nums[middle_index])/2.0;
        }

        return result;   
    }

    int binarySearch(vector<int> &nums, int target, int high, int low)
    {
        if(low == high || low > high)
            return low;

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