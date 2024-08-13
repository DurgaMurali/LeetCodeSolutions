class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        
        backtrack(k, result, combination, 0, n);
        
        return result;
    }

    void backtrack(int k, vector<vector<int>> &result, vector<int> &combination, int start, int remaining)
    {
        if(remaining == 0 && combination.size() == k)
        {
            result.push_back(combination);
            return;
        }
        else if(combination.size() == k || remaining <= 0)
            return;

        for(int i=start; i < 9; i++)
        {
            combination.push_back(i+1);
            backtrack(k, result, combination, i+1, remaining-i-1);
            combination.pop_back();
        }
    }
};