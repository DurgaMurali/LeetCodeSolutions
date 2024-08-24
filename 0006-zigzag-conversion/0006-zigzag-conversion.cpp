class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 0)
            return "";

        vector<vector<char>> result(numRows);
        string::iterator it = s.begin();
        int row_assigner = 0;
        bool col_complete = false;

        for(; it != s.end(); ++it)
        {
            if(row_assigner < numRows & !col_complete)
                row_assigner++;
            else if(row_assigner == numRows && numRows > 2)
            {
                col_complete = true;
                row_assigner--;
            }
            else if(row_assigner > 2 && col_complete)
                row_assigner--;
            else if(row_assigner == 2)
            {
                col_complete = false;
                row_assigner = 1;
            }

            std::cout << row_assigner << std::endl;
            result[row_assigner-1].push_back(*it);
        }

        string result_string = "";
        vector<vector<char>>::iterator itr = result.begin();
        for(; itr != result.end(); ++itr)
        {
            vector<char>::iterator iter = (*itr).begin();
            for(; iter != (*itr).end(); ++iter)
                result_string += (*iter);
        }

        return result_string;
    }
};