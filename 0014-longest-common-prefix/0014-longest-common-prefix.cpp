class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();

        int index = 0;
        bool match = false;
        while(true)
        {
            char ch = -1;
            bool break_outer = false;
            if(strs[0].length() > index)
                ch = strs[0][index];
            else
                break;

            for(int i=1; i<size; ++i)
            {
                if(strs[i].length() > index && strs[i][index] == ch)
                    continue;
                else
                    break_outer = true;
                    break;
            }

            if(break_outer)
                break;

            index++;
            match = true;
        }

        if(match)
            return strs[0].substr(0, index);
        else
            return "";
    }
};