#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        int start_index = 0;
        int end_index = s.length()-1;
        //int mid_index = (s.length()%2 == 0) ? (s.length()/2 - 1) : (s.length()/2);
        bool isPalindrome = true;

        while(true)
        {
            while(start_index<size && !isalnum(s[start_index]))
            {
                start_index++;
            }

            while(end_index>=0 && !isalnum(s[end_index]))
            {
                end_index--;
            }

            if(start_index<size)
                s[start_index] = tolower(s[start_index]);

            if(end_index>=0)
                s[end_index] = tolower(s[end_index]);

            if(start_index<size && end_index>=0 && start_index<=end_index && s[start_index] == s[end_index])
            {
                if(start_index == end_index)
                    break;

                ++start_index;
                --end_index;
            }
            else if(start_index > end_index)
                break;
            else
            {
                isPalindrome = false;
                break;
            }
        }

        return isPalindrome;
    }
};