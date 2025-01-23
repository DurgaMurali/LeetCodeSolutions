class Solution {
public:
    string removeStars(string s) {
        /*size_t pos = s.find('*');

        while(pos != string::npos && !s.empty())
        {
            if(pos > 0)
            {
                s.erase(pos-1, 2);
            }

            pos = s.find('*');
        }

        return s;*/

        stack<char> char_stack;
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i] != '*')
                char_stack.push(s[i]);
            else
                char_stack.pop();
        }

        string str = "";
        while(!char_stack.empty())
        {
            str.push_back(char_stack.top());
            char_stack.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};