class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        string result = "";
        int i = length-1, j = length-1;

        while (i>=0 && j>=0)
        {
            if(i==j && s[i] == ' ')
            {
                i--;
                j--;
            }
            else if (s[i] != ' ')
                i--;
            else if (i<j && s[i] == ' ')
            {
                string sub_str = s.substr(i+1, j-i);
                result += sub_str + " ";
                i--;
                j = i;
            }
        }

        if (i < 0 && j > i)
        {
            string sub_str = s.substr(i+1, j-i);
            result += sub_str;
        }
        else if (i < 0 && i == j)
        {
            int res_len = result.length();
            string sub_str = result.substr(0, res_len-1);
            result = sub_str;
        }

        return result;
    }
};