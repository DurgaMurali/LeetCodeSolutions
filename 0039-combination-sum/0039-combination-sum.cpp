class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;

        backtrack(result, candidates, combination, 0, target);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int>& candidates, vector<int> &combination, int start_index, int remaining)
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
            combination.push_back(candidates[i]);
            backtrack(result, candidates, combination, i, remaining-candidates[i]);
            combination.pop_back();
        }
    }
};