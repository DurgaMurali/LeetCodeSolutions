class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int num_operations = 0;
        int size = nums.size();

        sort(nums);

        int begin_index = 0;
        int end_index = size-1;

        if (nums[begin_index] >= k)
            return num_operations;

        while(nums[end_index] >= k)
            end_index--;

        while(begin_index < end_index)
        {
            int remainder = k - nums[begin_index];
            if(nums[end_index] == remainder)
            {
                num_operations++;
                begin_index++;
                end_index--;
            }
            else if(nums[end_index] > remainder)
                end_index--;
            else
                begin_index++;
        }

        return num_operations;
    }

    void sort(vector<int>& nums)
    {
        mergesort(nums, 0, nums.size()-1);
    }

    void mergesort(vector<int>& nums, int begin, int end)
    {
        if (begin >= end)
            return;

        int mid = begin + (end - begin)/2;
        mergesort(nums, begin, mid);
        mergesort(nums, mid+1, end);

        merge(nums, begin, mid, end);
    }

    void merge(vector<int>& nums, int begin, int mid, int end)
    {
        int left_size = mid - begin + 1;
        int right_size = end - mid;
        vector<int> left_array(left_size);
        vector<int> right_array(right_size);

        for(int i=0; i<left_size; i++)
            left_array[i] = nums[begin + i];

        for(int j=0; j<right_size; j++)
            right_array[j] = nums[mid + 1 + j];

        int sort_index = begin;
        int i=0,j=0;
        while(i<left_size && j<right_size)
        {
            if(left_array[i] <= right_array[j])
            {
                nums[sort_index] = left_array[i];
                i++;
            }
            else if(right_array[j] < left_array[i])
            {
                nums[sort_index] = right_array[j];
                j++;
            }
            sort_index++;
        }

        while(i<left_size)
        {
            nums[sort_index] = left_array[i];
            i++;
            sort_index++;
        }
        while(j<right_size)
        {
            nums[sort_index] = right_array[j];
            j++;
            sort_index++;
        }
    }
};