class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int max_length = 0;
        string substring = "";
        int size = s.length();

        for(int i=0; i<size; ++i)
        {
            int pos = substring.find(s[i]);
            if(pos == string::npos)
            {
                substring += s[i];
                length++;
                //std::cout << "Add " << s[i] << ", substring = " << substring << std::endl;
            }
            else
            {
                if(max_length < length)
                    max_length = length;

                substring = substring.substr(pos+1);
                substring += s[i];
                length = substring.length();
                //std::cout << "Remove and add " << s[i] << ", substring = " << substring << std::endl;
            }
        }
        if(max_length < length)
            max_length = length;
        return max_length;
    }
};