class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int low_index = 0;
    int mid_index = -1;
    int current_small_index = 0;
    bool pair_found = false;
    bool triplet_found = false;
    int size = nums.size();

    for(int i=1; i<size; ++i)
    {
        if (pair_found == false)
        {
            if (nums[i] < nums[low_index])
            {
                low_index = i;
                current_small_index = i;
            }
            else if (nums[i] > nums[low_index])
            {
                mid_index = i;
                pair_found = true;
            }
        }
        else if (pair_found == true && low_index == current_small_index)
        {
            if (nums[i] > nums[mid_index])
            {
                triplet_found = true;
                break;
            }
            else if (nums[i] < nums[mid_index] && nums[i] > nums[low_index])
                mid_index = i;
            else if (nums[i] < nums[mid_index] && nums[i] < nums[low_index])
                current_small_index = i;
        }
        else if (pair_found == true && low_index != current_small_index)
        {
            if (nums[i] > nums[mid_index])
            {
                triplet_found = true;
                break;
            }
            else if (nums[i] < nums[current_small_index])
                current_small_index = i;
            else if (nums[i] > nums[current_small_index])
            {
                low_index = current_small_index;
                mid_index = i;
            }
        }

        //std::cout<<low_index << ", " << mid_index << ", " << current_small_index << ", " << pair_found << std::endl;
    }

    return triplet_found;
    }
};