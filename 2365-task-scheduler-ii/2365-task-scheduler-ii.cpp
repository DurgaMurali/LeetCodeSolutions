class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> task_days_count;
        long long total_days = 0;

        std::vector<int>::iterator task_itr = tasks.begin();
        for(; task_itr!=tasks.end(); ++task_itr)
        {
            total_days++;
            unordered_map<int, long long>::iterator count_itr = task_days_count.find(*task_itr);
            if(count_itr != task_days_count.end())
            {
                long long days_passed = total_days - count_itr->second;
                if(days_passed > space)
                {
                    count_itr->second = total_days;
                }
                else
                {
                    int remaining = space - days_passed;
                    count_itr->second = total_days + remaining + 1;
                    total_days += remaining + 1;
                }
            }
            else
            {
                task_days_count.insert(std::make_pair(*task_itr, total_days));
            }
        }

        return total_days;
    }
};