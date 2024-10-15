class Solution {
public:
    /*static bool compare_func(const vector<int> &pair1, const vector<int> &pair2)
    {
        std::cout << pair1[0] << ", " << pair2[0] << std::endl;
        return (pair1[0] < pair2[0]);
    }*/

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::cout << intervals.size() << std::endl;
        for(int i=0; i<intervals.size(); ++i)
        {
            if(intervals[i].empty())
                std::cout << i << " is empty" << std::endl;
        }
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &pair1, const vector<int> &pair2){
            return (pair1[0] < pair2[0]);
        });
        //std::sort(intervals.begin(), intervals.end(), &Solution::compare_func);
        vector<vector<int>> merged_intervals;

        int index = 1;
        vector<int> prev_vec = {intervals[0][0], intervals[0][1]};
        while(index < intervals.size())
        {
            if(prev_vec[0] == intervals[index][0])
            {
                prev_vec[1] = (prev_vec[1] > intervals[index][1]) ? prev_vec[1] : intervals[index][1];
            }
            else if(intervals[index][0] > prev_vec[0] && intervals[index][0] <= prev_vec[1])
            {
                prev_vec[1] = (prev_vec[1] > intervals[index][1]) ? prev_vec[1] : intervals[index][1];
            }
            else
            {
                merged_intervals.push_back(prev_vec);
                prev_vec = intervals[index];
            }

            index++;
        }
        merged_intervals.push_back(prev_vec);

        return merged_intervals;
    }
};