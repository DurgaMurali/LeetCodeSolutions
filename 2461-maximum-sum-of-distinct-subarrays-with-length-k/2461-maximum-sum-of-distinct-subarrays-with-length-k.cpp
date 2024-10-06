class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(k > size)
            return 0;

        long long sum = 0;
        long long max_sum = 0;
        unordered_map<int, int> map_set;
        int count = 0;
        int num_dup_seqs = 0;
        bool insert_failed = false;

        for(int i=0; i<size; ++i)
        { 
            if(count >= k)
            {
                if(map_set[nums[i-k]] > 1)
                {
                    map_set.at(nums[i-k]) -= 1;
                    num_dup_seqs--;
                    //std::cout << " dup_sqs = " << num_dup_seqs << std::endl;
                }
                else if(map_set[nums[i-k]] == 1)
                {
                    map_set.erase(nums[i-k]);

                    if(num_dup_seqs == 0)
                    {
                        if(max_sum < sum)
                            max_sum = sum; 
                        //std::cout << "max sum = " << max_sum << std::endl;  
                    }
                }      

                sum -= nums[i-k];
                count--;
                //std::cout << "sum = " << sum << std::endl;
            }

            //std::cout << map_set.count(nums[i]) << std::endl;
            if(map_set.count(nums[i]) > 0)
            {
                map_set.at(nums[i]) += 1;
                num_dup_seqs++;
                //std::cout << "count = " << map_set[nums[i]] << " dup_sqs = " << num_dup_seqs << std::endl;
            }
            else
                map_set.insert(std::pair(nums[i], 1));

            sum += nums[i];
            //std::cout << "sum = " << sum << std::endl;
            count++;
        }

        //std::cout << "count = " << count << ", num_dup_seqs = " << num_dup_seqs << ", max_sum = " << max_sum << ", sum = " << sum << std::endl;
        if(count == k && num_dup_seqs == 0 && max_sum < sum)
            max_sum = sum;

        return max_sum;
    }
};