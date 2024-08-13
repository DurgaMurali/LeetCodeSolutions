class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int size = height.size();
        int left_index = 0, right_index = size-1;

        while(left_index < size && right_index >= 0)
        {
            int area = 0;
            if (left_index == right_index)
                break;
            else if (height[left_index] > height[right_index])
            {
                area =  height[right_index] * (right_index - left_index);
                right_index--;
            }
            else if(height[left_index] <= height[right_index])
            {
                area =  height[left_index] * (right_index - left_index);
                left_index++;
            }

            if(area > max)
                max = area;
        }

        return max;
    }
};