#include <algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        vector<int> prev_comb;
        sort(candidates.begin(), candidates.end());

        backtrack(result, candidates, combination, 0, target, prev_comb);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int>& candidates, vector<int> &combination, int start_index, int remaining, vector<int> &prev_comb)
    {
        if(remaining == 0)
        {
            result.push_back(combination);
            return;
        }
        else if(remaining < 0)
            return;

        for(int i=start_index; i<candidates.size(); i++)
        {
            if(i == start_index || candidates[i] != candidates[i-1])
            {
                combination.push_back(candidates[i]);
                backtrack(result, candidates, combination, i+1, remaining-candidates[i], prev_comb);
                combination.pop_back();
            }
        }
    }
};